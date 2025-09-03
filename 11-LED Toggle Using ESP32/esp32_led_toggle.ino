#include <WiFi.h>

// Set LED GPIO
const int ledPin = 2;

// AP credentials
const char *ssid = "ESP32-LED-Control";
const char *password = "12345678";

// HTML Web Page
const char* htmlPage = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <title>ESP32 LED Control</title>
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  
  <!-- Bootstrap CSS -->
  <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet">

  <!-- Font Awesome -->
  <link href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.5.0/css/all.min.css" rel="stylesheet">

  <!-- Animate.css -->
  <link href="https://cdnjs.cloudflare.com/ajax/libs/animate.css/4.1.1/animate.min.css" rel="stylesheet">

  <!-- SweetAlert2 -->
  <script src="https://cdn.jsdelivr.net/npm/sweetalert2@11"></script>

  <style>
    body {
      background: linear-gradient(to right, #1f4037, #99f2c8);
      color: #fff;
      font-family: 'Segoe UI', sans-serif;
      text-align: center;
      padding-top: 60px;
    }
    .card {
      background-color: rgba(0, 0, 0, 0.6);
      border: none;
      border-radius: 15px;
      padding: 30px;
      box-shadow: 0 0 15px rgba(0,0,0,0.3);
    }
    .btn-led {
      width: 150px;
      height: 60px;
      font-size: 20px;
      margin: 10px;
      border-radius: 30px;
    }
    footer {
      margin-top: 50px;
      font-size: 14px;
      color: #ddd;
    }
  </style>
</head>
<body>
  <div class="container animate_animated animate_fadeInDown">
    <div class="card mx-auto" style="max-width: 400px;">
      <h2><i class="fas fa-lightbulb"></i> ESP32 LED Control</h2>
      <p class="lead">Control your LED wirelessly</p>
      <button class="btn btn-success btn-led" onclick="toggleLED('on')"><i class="fas fa-power-off"></i> Turn ON</button>
      <button class="btn btn-danger btn-led" onclick="toggleLED('off')"><i class="fas fa-power-off"></i> Turn OFF</button>
    </div>
  </div>

  <script>
    function toggleLED(state) {
      fetch("/led?state=" + state)
        .then(() => {
          Swal.fire({
            icon: state === 'on' ? 'success' : 'info',
            title: LED turned ${state.toUpperCase()},
            showConfirmButton: false,
            timer: 1200
          });
        })
        .catch(err => {
          Swal.fire({
            icon: 'error',
            title: 'Oops...',
            text: 'Failed to send command!'
          });
        });
    }
  </script>
</body>
</html>
)rawliteral";


WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  // Set up ESP32 as Access Point
  WiFi.softAP(ssid, password);
  Serial.println();
  Serial.print("Access Point IP: ");
  Serial.println(WiFi.softAPIP());

  server.begin();
}

void loop() {
  WiFiClient client = server.available();
  if (client) {
    Serial.println("New Client Connected.");
    String request = "";
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        request += c;
        if (c == '\n' && request.endsWith("\r\n\r\n")) break;
      }
    }

    Serial.println("Request:");
    Serial.println(request);

    // Handle request
    if (request.indexOf("/led?state=on") != -1) {
      digitalWrite(ledPin, HIGH);
    } else if (request.indexOf("/led?state=off") != -1) {
      digitalWrite(ledPin, LOW);
    }

    // Send response
    client.println("HTTP/1.1 200 OK");
    client.println("Content-type:text/html");
    client.println();
    client.print(htmlPage);
    client.println();
    delay(1);
    client.stop();
    Serial.println("Client disconnected.");
  }
}
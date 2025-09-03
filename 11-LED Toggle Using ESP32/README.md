# ESP32 LED Toggle Web Server  

This project demonstrates how to create a standalone web server with an **ESP32** to control an LED wirelessly through a browser. The ESP32 is configured as an Access Point (AP) and serves a responsive web page where users can toggle the LED state.  

---

## 🚀 Features  
- ESP32 configured as **Access Point** (no external WiFi required).  
- Responsive **Bootstrap-based web interface** with modern UI.  
- LED control using **ON/OFF buttons**.  
- Real-time feedback with **SweetAlert2 notifications**.  
- Runs directly from ESP32 using Arduino IDE.  

---

## 🛠 Requirements  
- **ESP32 board**  
- **Arduino IDE** with ESP32 board support installed  
- LED (or onboard GPIO2 LED can be used)  
- USB cable for programming  

---

## 📋 Setup Instructions  
1. Install the **Arduino IDE** and configure it for ESP32:  
   - Go to **File > Preferences**  
   - Add the following URL in *Additional Board Manager URLs*:  
     ```
     https://dl.espressif.com/dl/package_esp32_index.json
     ```
   - Install **ESP32 boards** from the Board Manager.  

2. Clone this repository:  
   ```bash
   git clone https://github.com/prathu2k4/Marvel01/11-LED%20Toggle%20Using%20ESP32.git
   

3. Open the code in Arduino IDE.

4. Select your ESP32 board under **Tools > Board** and the correct COM port.

5. Upload the code to the ESP32.

6. Open **Serial Monitor** to see the ESP32 Access Point IP (default `192.168.4.1`).

7. Connect your device to the WiFi network:

   * SSID: `ESP32-LED-Control`
   * Password: `12345678`

8. Open the IP in your browser and control the LED!

---

## 📷 Preview

Example Web UI:
![img](https://github.com/prathu2k4/Marvel01/blob/main/images/esp_1.jpg)

---

## 📂 Project Structure

```
esp32-led-toggle/
├── esp32_led_toggle.ino   # Main Arduino sketch
└── README.md              # Documentation
```

---

## 🧑‍💻 Author

Developed as part of an **IoT Learning Task** to understand ESP32 web server and GPIO control.

---

## 📜 License

This project is open-source and available under the [MIT License](LICENSE).

```
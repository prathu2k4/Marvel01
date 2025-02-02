async function getWeather() {
    const location = document.getElementById('location').value;
    const weatherInfo = document.getElementById('weather-info');

    if (!location) {
        alert("Please enter a city name.");
        return;
    }

    const url = `http://api.weatherapi.com/v1/current.json?key=${API_KEY}&q=${location}&aqi=no`;

    try {
        const response = await fetch(url);
        if (!response.ok) {
            throw new Error(`HTTP error! Status: ${response.status}`);
        }
        const data = await response.json();

        weatherInfo.innerHTML = `
            <h2>${data.location.name}, ${data.location.region}, ${data.location.country}</h2>
            <p>Local Time: ${data.location.localtime}</p>
            <img class="weather-icon" src="${data.current.condition.icon}" alt="Weather Icon">
            <p><strong>${data.current.condition.text}</strong></p>
            <div class="details">
                <p>Temp: ${data.current.temp_c}°C (${data.current.temp_f}°F)</p>
                <p>Feels Like: ${data.current.feelslike_c}°C</p>
            </div>
            <div class="details">
                <p>Wind: ${data.current.wind_kph} kph (${data.current.wind_mph} mph)</p>
                <p>Direction: ${data.current.wind_dir}</p>
            </div>
            <div class="details">
                <p>Humidity: ${data.current.humidity}%</p>
                <p>Pressure: ${data.current.pressure_mb} mb</p>
            </div>
            <div class="details">
                <p>Precipitation: ${data.current.precip_mm} mm</p>
                <p>UV Index: ${data.current.uv}</p>
            </div>
        `;

        weatherInfo.style.display = "block"; // Show weather info after fetching data

    } catch (error) {
        weatherInfo.innerHTML = '<p>Error fetching weather data</p>';
        weatherInfo.style.display = "block"; // Show error message if fetching fails
    }

}

function handleKeyPress(event) {
    if (event.key === 'Enter') {
        getWeather();
    }
}

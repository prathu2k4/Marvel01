## Detailed Technical Report: MQ135 Air Quality Gas Sensor (Version 1.4)

### 1. Overview
The MQ135 is a semiconductor gas sensor developed by Zhengzhou Winsen Electronics Technology Co., Ltd, designed for **air quality monitoring**. It’s particularly optimized for detecting a range of gases affecting air quality, such as ammonia, sulfide, benzene series vapors, toluene, hydrogen, and smoke. The sensitive material is **SnO2**, a type of tin dioxide, whose conductivity increases as the presence of target gases rises.

---

### 2. Features and Applications

The MQ135 combines wide sensitivity with stable long-term performance, provided it is operated within specified conditions. It requires a simple drive circuit, making it practical for domestic gas alarms, industrial monitors, and portable detectors. Its bakelite housing and metal cap provide robustness while maintaining low production cost.

---

### 3. Technical Specifications

The sensor detects gases in the **10–1000 ppm range**, with best sensitivity to NH₃, toluene, and smoke. Operating requires two voltages: a **heater voltage (5.0V ±0.1V)** to maintain the sensor at optimal temperature, and a **circuit voltage (≤24V DC, typically 5V)** for signal measurement. Heater resistance is about 29Ω at room temperature with power consumption under 950mW. A typical load resistor (RL) is 4.7kΩ, adjustable depending on the application.

At 400 ppm H₂, output voltage ranges between 2–4V, with sensitivity defined as Rs(air)/Rs(400 ppm H₂) ≥ 5. Standard calibration is performed at 20°C and 55% RH. For accurate readings, a **preheat of at least 48 hours** is necessary, extended further if the sensor has been in long-term storage.

---

### 4. Construction and Circuit

The six-pin package includes two heater pins and two pairs of testing electrodes (internally connected in pairs). Incorrect wiring may cause permanent damage. In the test circuit, RL is connected in series with the sensor, and the voltage across RL (VRL) is the output signal proportional to gas concentration.

---

### 5. Performance Characteristics

Sensor resistance falls as gas concentration increases, producing a corresponding voltage rise across RL. Response to target gases is quick, with recovery once returned to clean air. Accuracy is influenced by temperature and humidity; therefore, calibration should be done under standardized conditions.

Long-term stability is good, though drift may occur if exposed to extreme environments or during prolonged storage. To restore stability, sensors require “aging” (continuous powering) from 48 hours up to one week, depending on storage time.

---

### 6. Handling Guidelines

The MQ135 must be kept away from contaminants such as organic silicon compounds, corrosive gases (H₂S, SOx, Cl₂, HCl), and halogen salts, as these cause irreversible sensitivity loss. Direct contact with water, freezing, or prolonged exposure to very high gas concentrations also degrade performance.

Excessive voltage or misapplied pin connections can result in failure. While condensation and high humidity should be avoided, short-term variations are tolerated if the device is recalibrated.

---

### 7. Soldering and Assembly

Hand soldering should be limited to 250°C for less than three seconds per joint, using rosin flux with minimal chlorine. In wave soldering, the device should pass at 1–2 m/min with solder temperature of 250±10°C. Excess heat, flux residue, or repeated soldering cycles will impair sensitivity.

---

### Summary

The MQ135 is a cost-effective, multi-gas semiconductor sensor suited for air quality monitoring across domestic, industrial, and portable platforms. With a detection range of 10–1000 ppm and a straightforward test circuit, it can be readily integrated with ADC systems for digital monitoring. Proper preheating, careful handling, and avoidance of harmful contaminants are critical for long-term stability. When operated under recommended conditions, the MQ135 offers reliable sensitivity to common pollutants and smoke, making it a versatile choice for practical air quality systems.

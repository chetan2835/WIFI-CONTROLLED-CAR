# 🚗 ESP8266 WiFi Controlled Car using Blynk (New Blynk App)

This project enables you to control an **ESP8266 NodeMCU-based car** using the **Blynk IoT platform**. It connects the NodeMCU to your Wi-Fi and allows you to control the car’s movement (forward, backward, left, right, and stop) through the Blynk mobile app.

---

## 🛠️ Features

- ✅ Control car direction: Forward, Backward, Left, Right
- ✅ Control speed with a slider
- ✅ Real-time control via the **New Blynk App**
- ✅ Easy setup and wireless control using WiFi

---

## 🧰 Hardware Required

| Component              | Quantity |
|------------------------|----------|
| NodeMCU ESP8266        | 1        |
| L298N Motor Driver     | 1        |
| DC Motors (BO or similar) | 2 or 4 |
| Wheels                 | 2 or 4   |
| Chassis                | 1        |
| Power Supply (Battery 7.4V or 12V) | 1 |
| Jumper Wires           | As needed |
| Smartphone (with Blynk app) | 1 |

---

## 🔌 Wiring / Circuit Connections

| NodeMCU Pin | L298N Motor Driver Pin |
|-------------|-------------------------|
| D0          | ENA                     |
| D1          | IN1                     |
| D2          | IN2                     |
| D3          | IN3                     |
| D4          | IN4                     |
| D5          | ENB                     |

**Note**: Connect the L298N motor outputs to your DC motors. Use an external power supply for the motor driver.

---

## 📱 Blynk Setup

1. Go to [https://blynk.io](https://blynk.io) and sign up or log in.
2. Create a new Template:
   - **Template Name**: ESP8266 Car Controller
   - **Hardware**: ESP8266
3. Note down the **Template ID**, **Template Name**, and **Auth Token**
4. Add the following widgets to your project:
   - Button on **V0** (Forward)
   - Button on **V1** (Backward)
   - Button on **V2** (Left)
   - Button on **V3** (Right)
   - Slider on **V4** (Speed control, range 0–1023)
5. Set each widget to **Switch mode** (except the slider).
6. Download the **Blynk IoT** app from Play Store/App Store.
7. Open the app, login, and load your template.

---

## 💻 Code Setup

### 1. Install Libraries

Install these libraries via Arduino IDE Library Manager:

- `Blynk` (latest version for ESP8266)
- `ESP8266WiFi`

### 2. Upload Code

Replace the following placeholders in the code:
```cpp
char auth[] = "YourAuthToken";
char ssid[] = "YourWiFiSSID";
char pass[] = "YourWiFiPassword";

#define BLYNK_TEMPLATE_ID "YourTemplateID"
#define BLYNK_TEMPLATE_NAME "YourTemplateName"

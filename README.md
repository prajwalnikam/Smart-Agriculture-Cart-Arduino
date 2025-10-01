# Smart-Agriculture-Cart-Arduino
**🚗 Obstacle Avoidance Motor Control with Arduino**

This project demonstrates an **Arduino-based motor control system** with obstacle detection and emergency stop functionality. It integrates an **HC-SR04 ultrasonic sensor**, **motor driver (H-bridge)**, and a **relay module** to ensure safe operation of a motor in environments where obstacles may appear.

---

## 📌 Features
- ✅ **Switch Control**: Motor runs only when the external switch is pressed.  
- ✅ **Ultrasonic Obstacle Detection**: Measures distance in real-time using HC-SR04.  
- ✅ **Emergency Stop**: Immediate motor stop if an obstacle is detected within 10 cm.  
- ✅ **Safe Operation**: Motor runs only if no obstacle is detected within 60 cm.  
- ✅ **Relay Control**: Relay is automatically switched ON/OFF based on motor state.  

---

## 🛠 Hardware Requirements
- Arduino Uno (or compatible board)  
- Motor + Motor Driver (H-bridge)  
- Relay Module  
- Ultrasonic Sensor (HC-SR04)  
- Push Button / Switch  
- Power Supply  

---

## ⚡ Circuit Connections

| Component        | Arduino Pin |
|------------------|-------------|
| Motor RPWM       | 5 (PWM)     |
| Motor LPWM       | 6 (PWM)     |
| Relay            | 7           |
| Ultrasonic Trig  | 8           |
| Ultrasonic Echo  | 9           |
| Switch           | 4 (with `INPUT_PULLUP`) |


---

## ⚙️ Constants in Code

const int obstacleThreshold = 60;     // cm - motor stops if obstacle is closer
const int emergencyStopDistance = 10; // cm - immediate stop
const int motorSpeed = 180;           // PWM speed (0-255)
🚀 Working Principle
System starts with motor OFF.

When switch is pressed, the ultrasonic sensor measures distance:

If distance < 10 cm → Emergency stop (motor OFF, relay OFF).

If distance < 60 cm → Motor OFF (too close, safety mode).

If distance > 60 cm → Motor runs forward, relay ON.

Distance is checked continuously every 20 ms.

---

## 📷 Example Scenarios
🔴 Switch OFF → Motor OFF

🚨 Switch ON + Obstacle at 5 cm → Emergency Stop

⛔ Switch ON + Obstacle at 30 cm → Motor OFF (too close)

🟢 Switch ON + No obstacle (100 cm away) → Motor runs

---

## 🧩 Future Improvements
Add reverse movement when obstacle detected.

Adjust motor speed dynamically based on distance.

Add LED or buzzer alerts for obstacle warnings.

Display distance readings on Serial Monitor or LCD.

---

## 👨‍💻 Author
Developed by [Prajwal Nikam]

---

## 🌐 Connect with Me

<p align="center">
  <a href="https://www.linkedin.com/in/prajwal-nikam-pn2181/" target="blank">
    <img src="https://img.shields.io/badge/LinkedIn-blue?style=for-the-badge&logo=linkedin" alt="LinkedIn">
  </a>
  <a href="mailto:prajwalnikam4@gmail.com" target="blank">
    <img src="https://img.shields.io/badge/Gmail-red?style=for-the-badge&logo=gmail&logoColor=white" alt="Gmail">
  </a>
  <a href="https://prajwalnikam.github.io/Portfolio/" target="blank">
    <img src="https://img.shields.io/badge/Portfolio-black?style=for-the-badge&logo=github" alt="Portfolio">
  </a>
</p>
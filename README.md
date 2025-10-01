# Smart-Agriculture-Cart-Arduino
🚗 Obstacle Avoidance Motor Control with Arduino

This project uses an Arduino, an ultrasonic sensor (HC-SR04), a motor driver (H-bridge), and a relay module to build a smart motor control system that can:

✅ Detect obstacles
✅ Stop automatically in emergencies
✅ Run the motor only when it's safe
✅ Be controlled with a simple switch

🛠️ Components Required

🧠 Arduino Uno (or compatible board)

⚡ Motor + Motor Driver (H-bridge)

🔌 Relay Module

📡 Ultrasonic Sensor (HC-SR04)

🎚️ Push Button / Switch

🔋 Power Supply

⚡ Circuit Connections
Component	Arduino Pin
Motor RPWM	5 (PWM)
Motor LPWM	6 (PWM)
Relay	7
Ultrasonic Trig	8
Ultrasonic Echo	9
Switch	4 (with INPUT_PULLUP)
⚙️ How It Works

Switch OFF → Motor stays OFF 📴

Switch ON + Safe Distance (> 60 cm) → Motor runs ✅

Switch ON + Obstacle too close (< 60 cm) → Motor stops ⛔

Emergency! (< 10 cm) → Immediate stop + Relay OFF 🚨

The ultrasonic sensor continuously measures the distance ahead and decides whether the motor should run or stop.

🔢 Code Highlights
const int obstacleThreshold = 60;     // cm, safe distance
const int emergencyStopDistance = 10; // cm, emergency stop
const int motorSpeed = 180;           // PWM speed (0-255)


Motor speed is adjustable (0 - 255).

The system checks distance every 20 ms.

📷 Example Scenarios

Switch OFF → Motor OFF 🔴

Switch ON + Obstacle at 5 cm → Emergency Stop 🚨

Switch ON + Obstacle at 30 cm → Motor OFF (too close) ⛔

Switch ON + No obstacle (100 cm away) → Motor runs 🟢

🧩 Possible Upgrades

✨ Add reverse movement when an obstacle is detected
✨ Use a buzzer or LED for alerts
✨ Show distance readings on Serial Monitor for debugging
✨ Adjust speed based on distance

🚀 Getting Started

Connect all components as per the pin diagram.

Upload the provided Arduino sketch to your board.

Open Serial Monitor (optional) to see distance values.

Press the switch and test the obstacle detection system! 🎉
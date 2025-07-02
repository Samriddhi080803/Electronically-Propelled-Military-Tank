# 🚀 Electronically Propelled Military Tank

A mobile robotic tank prototype designed for military simulations, surveillance, and remote reconnaissance. This Arduino-based UGV (Unmanned Ground Vehicle) features wireless manual control via a joystick and advanced turret control, making it a robust, flexible, and scalable solution for real-world tactical missions.

---

## 📘 Abstract

This project demonstrates the development of an electronically propelled robotic tank using an **Arduino Nano**, capable of performing critical tasks such as **terrain navigation**, **turret rotation**, and **remote operation** via joystick or mobile app.

The tank integrates:
- Gear motors for forward/reverse movement
- Servo motors for steering
- Stepper motor and potentiometer for turret control
- Buck converter for stable voltage regulation

The chassis is built using **steel sheets**, **aluminum brackets**, and **chain-driven wheels**, resulting in a durable yet efficient mechanical structure. This UGV is a scalable, low-cost prototype that can evolve into an autonomous military system with added sensors, GPS, and vision modules.

---

## 🎯 Objectives

1. **Robust UGV Design** for rugged terrains with a durable steel and aluminum chassis.
2. **Wireless Control System** using Arduino Nano and analog joystick.
3. **Dual Motor Propulsion** for efficient forward and reverse movement.
4. **Precision Turret Control** with a stepper motor and potentiometer slider.
5. **Efficient Power Management** with buck converters to support long operation.
6. **Scalability** for future integration of GPS, cameras, and autonomous navigation.

---

## ⚙️ Hardware & Components

- Arduino Nano (x2)
- Gear Motors (for propulsion)
- Servo Motors (for steering)
- Stepper Motor (for turret rotation)
- Joystick module
- Buck Converter (12V to 5V)
- Motor Driver (L298N)
- Steel chassis, bearings, sprockets, aluminum brackets
- Mobile interface via MIT App Inventor (optional)

---

## 🛠️ Working Principle

The Arduino Nano acts as the control center. The **transmitter** side (joystick) sends analog values wirelessly, which the **receiver** Arduino interprets to:
- Drive the motors (forward/reverse/stop)
- Rotate the turret based on potentiometer input
- Steer using servo motors
- Switch between joystick and mobile app input

The power system uses a **12V, 2A supply** regulated down to 5V for Arduino and sensor logic, ensuring reliability and safety.

---

## 📁 Folder Structure

Electronically-Propelled-Military-Tank/
├── Arduino_Code/
│   ├── Transmitter_control.ino      # Code for joystick-side Arduino
│   └── Receiver_Control.ino         # Code for tank-side Arduino
│
├── App_Files/
│   └── tank_control.aia             # (Optional) MIT App Inventor file
│
├── Project_Report/
│   └── FINAL_BLACK_BOOK_2024-2025.pdf   # Your black book report
│
├── Project_Images/
│   ├── hardware_setup.jpg
│   ├── joystick_module.jpg
│   └── screenshot_app_ui.png
│           
└──  README.md    # Main project overview   


---

## 🖥️ How to Run

1. Upload `Transmitter_control.ino` to the **joystick-side Arduino Nano**
2. Upload `Receiver_Control.ino` to the **tank-side Arduino Nano**
3. Connect RF transmitter/receiver modules
4. Wire motors and power using L298N motor driver
5. Connect joystick + potentiometer inputs
6. Power using a 12V 2A source
7. Start testing → use joystick to move and control turret

---

## 🧪 Future Enhancements

- Mobile app control via **MIT App Inventor**
- Add **metal detector**, **camera**, and **GPS**
- Enable **autonomous navigation** using IR or ultrasonic sensors
- Convert for **amphibious use** by redesigning the chassis
- Integrate **hybrid (ICE + electric) power** to reduce emissions

---

## 📄 Project Report

📄 [FINAL_BLACK_BOOK_2024-2025.pdf](FINAL_BLACK_BOOK_2024-2025.pdf)

---

## 👩‍🎓 Author

**Samriddhi Kurdekar**  
 

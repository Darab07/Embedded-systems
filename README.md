# RFID Access Control System – Arduino Uno

This repository contains the source code and documentation for an RFID-based access control system developed using an Arduino Uno, MFRC522 RFID reader, and a 16x2 I2C LCD display.

---

## 📁 Repository Structure

```
.
├── code/
│   ├── Code.ino                            # Main Arduino sketch
│   ├── Wire-master.zip                     # Backup of Wire I2C library
│   └── Arduino-LiquidCrystal-I2C.zip       # LCD library
├── diagrams/
│   ├── System Context Diagram.jpg          # System context overview
│   ├── Finite State Machine Diagram.png    # Finite state machine diagram
│   └── circuit_image.png                   # Schematic (circuit diagram)
│   └──UML Diagram.png                      # UML Diagram
├── README.md
```

---

## 🧰 Hardware Used

- Arduino Uno
- MFRC522 RFID reader module
- 16x2 character LCD with I2C backpack
- Jumper wires (no breadboard used)
- USB cable (for serial power + monitoring)

---

## 🔌 Wiring Summary

**RFID (MFRC522 via SPI):**

| RFID Pin | Arduino Pin |
|----------|-------------|
| SDA (SS) | D10         |
| SCK      | D13         |
| MOSI     | D11         |
| MISO     | D12         |
| RST      | D9          |
| VCC      | 3.3V        |
| GND      | GND         |

**LCD (I2C):**

| LCD Pin | Arduino Pin |
|---------|-------------|
| SDA     | A4          |
| SCL     | A5          |
| VCC     | 5V          |
| GND     | GND         |

---

## 🛠 Project Features

- RFID tag detection with UID reading
- UID comparison to predefined authorized UID
- LCD display feedback for access granted/denied
- Serial output for debugging UIDs
- Automatic LCD reset after delay

---

## 💾 Libraries Required

These are included in `/code` as `.zip` files:

- `MFRC522` – RFID reader support  
- `Wire` – I2C communication  
- `LiquidCrystal_I2C` – LCD display control

Install these using **Arduino IDE > Sketch > Include Library > Add .ZIP Library**.

---

## 📊 Development Versions

| Version | Feature Set |
|---------|-------------|
| v0.1    | RFID reader initialized, Serial UID output only |
| v0.2    | I2C LCD connected and displaying status |
| v1.0    | Complete logic: scan, match UID, display result, reset |

---

## ✅ Final UID (hardcoded)

```
B3 E1 52 19
```

Update this in `allowedUID[]` in `Code.ino` to authorize different cards.

---

## 📸 Diagrams

Refer to the `diagrams/` folder for:
- System context and data flow
- Finite state machine breakdown
- Hardware schematic
- UML Diagram

---

## 🔐 Notes

This project was developed as part of university coursework for module **6504SEPA – Embedded Systems**. Repository access is private and has been shared with module staff.



#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <MFRC522.h>

// LCD setup
LiquidCrystal_I2C lcd(0x27, 16, 2);  // Change if needed

// RFID setup
#define SS_PIN 10
#define RST_PIN 9
MFRC522 rfid(SS_PIN, RST_PIN);

// Allowed UID (B3E15219)
byte allowedUID[] = {0xB3, 0xE1, 0x52, 0x19};

void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();
  lcd.begin();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Scan a tag...");
}

bool compareUID(byte *uid, byte *allowed, byte size) {
  for (byte i = 0; i < size; i++) {
    if (uid[i] != allowed[i]) {
      return false;
    }
  }
  return true;
}

void loop() {
  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()) {
    return;
  }

  // Display UID in Serial Monitor
  Serial.print("Tag UID: ");
  String uidStr = "";
  for (byte i = 0; i < rfid.uid.size; i++) {
    Serial.print(rfid.uid.uidByte[i] < 0x10 ? "0" : "");
    Serial.print(rfid.uid.uidByte[i], HEX);

    uidStr += (rfid.uid.uidByte[i] < 0x10 ? "0" : "");
    uidStr += String(rfid.uid.uidByte[i], HEX);
  }
  Serial.println();

  // Check if UID matches the allowed one
  if (rfid.uid.size == 4 && compareUID(rfid.uid.uidByte, allowedUID, 4)) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Success!");
  } else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Access Denied");
  }

  delay(3000);  // Display result

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Scan a tag...");

  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
}

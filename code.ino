/*
    Program Bel Rumah dengan Blynk
*/

#define BLYNK_PRINT Serial  // Pendeklarasian Library
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "XXXX"; // masukkan kode autentikasi disini
char ssid[] = "Veendy-Suseno"; // nama wifi
char pass[] = "Admin12345"; // password

int buzzer = D1;  // Pemilihan Pin
int tomb = D0;

void setup() {  // Pengaturan Pin dan Variabel
    pinMode(buzzer, OUTPUT);
    pinMode(tomb, INPUT_PULLUP);
    Serial.begin(9600);
    Blynk.begin(auth, ssid, pass);
}

void loop() {  // Perulangan Program
    int push = digitalRead(tomb);
    if (push == LOW)  {  // Ketika tombol ditekan
        tone(buzzer, 1000, 200);
        Blynk.notify("Bel Berbunyi");
    } else  {
        noTone(buzzer);
    }
    delay(100);
    Blynk.run();
}

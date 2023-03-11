//GÖREV YÜKÜ GPS
#include <TinyGPS++.h>
//KÜTÜPHANENİN KULLANILACAĞI DEĞİŞKEN TANIMLAMA
TinyGPSPlus gps;
//Sensör sabitleri
static const uint32_t GPSBaud = 9600;
double boylam,enlem;
uint16_t gps_yil;
uint8_t gps_ay, gps_gun, gps_saat, gps_dakika, gps_saniye;
//Hardware serial için portlar
static const int RXPin = 15, TXPin = 14;
//millis fonksiyon sabitleri
unsigned long simdiki_zaman = 0;
unsigned long onceki_zaman = 0;
unsigned long aralik = 500;
void setup() 
{
  Serial.begin(9600);
	Serial3.begin(GPSBaud);
	Serial.println(F("GPS Verileri Aliniyor.."));
}

void loop()
{
  float payload_iki;
  simdiki_zaman = millis();
  if (simdiki_zaman - onceki_zaman >= aralik)
  {
  while (Serial3.available() > 0)

	if (gps.encode(Serial3.read())){
    if (gps.location.isValid())
    {
    double boylam = gps.location.lat();
    double enlem= gps.location.lng();
    Serial.print("P5,");//gorev yuku payload5
    Serial.print(enlem, 6);
    Serial.print(F(","));
    Serial.print(boylam, 6);
    }
  else
  {
    Serial.println("Konum Yok! ");
    
  }
	
}
}}

#include <ESP8266WiFi.h>

const char* ssid = "-----";  // SSID
const char* password = "---------"; // пароль

void startwifi(){
  delay(500);
  Serial.println();
  Serial.println("Connecting to: ");
  Serial.println(ssid);
  Serial.print("WiFi.");  

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password); // подключаемся к локальной wi-fi сети 
  IPAddress ip(000,000,000,000);  //желаемый статический IP
  IPAddress gateway(000,000,000,000);
  IPAddress subnet(000,000,000,000);
  WiFi.config(ip, gateway, subnet);
  
  while (WiFi.status() != WL_CONNECTED) // проверить, подключился ли wi-fi модуль к wi-fi сети
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("WiFi connected..!");
  Serial.print("Got IP: ");
  Serial.println(WiFi.localIP());

  //WiFi.printDiag(Serial); // информация о wifi
  Serial.print("Уровень сигнала WiFi: ");
  Serial.println(WiFi.RSSI());  // уровень сигнала точки доступа wifi
}

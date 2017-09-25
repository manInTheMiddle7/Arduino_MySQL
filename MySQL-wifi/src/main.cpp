// platformio device monitor -b 115200
#include <Arduino.h>
#include <ESP8266WiFi.h>
//#include <WiFi.h>
#include <MySQL_Packet.h>
#include <SPI.h>
#include <MySQL_Connection.h>
#include <MySQL_Cursor.h>

byte mac_addr[] = { 0x5C, 0xCF, 0x7F, 0x83, 0x14, 0x4A };

WiFiClient client;
MySQL_Connection conn((Client *)&client);

char ssid[] = "d58528";    // your SSID
char pass[] = "282456636";       // your SSID Password

IPAddress server_addr(192,168,0,12);  // IP of the MySQL *server* here
char user[] = "root";              // MySQL user login username
char password[] = "rootsecurity";        // MySQL user login password

// Sample query
char INSERT_SQL[] = "INSERT INTO test_arduino.hello_arduino (message) VALUES ('Hello, Arduino!')";

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, pass);
//   IPAddress ip = WiFi.localIP();
//   Serial.print("My IP address is: "); Serial.println(ip);


}

void loop() {    
  Serial.println("Connecting...");
  if (conn.connect(server_addr, 3306, user, password)) {
    Serial.println("Connect");
    delay(1000);
  }
  else{
    Serial.println("Connection failed.");
  } 
  
  conn.close();
}
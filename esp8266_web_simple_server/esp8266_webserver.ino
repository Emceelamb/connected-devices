// Include ESP8266 WiFi Libraries
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

// Wifi Credentials
const char* ssid = "Emceelamb";
const char* password = "guest123";

// Redefine Onboard LED
#define LED_BUILTIN 2

// Instantiate  server on port 80
ESP8266WebServer server(80);

// String for HTML
String page = "";

// turn led on
void ledOn(){
    server.send(200, "text/html", page);
    digitalWrite(LED_BUILTIN, LOW); // turns on LED
    delay(1000);
}

// turn led off
void ledOff(){
    server.send(200, "text/html", page);
    digitalWrite(LED_BUILTIN, HIGH); // turns off LED
    delay(1000);
}

void setup(){
    // HTML of page with inline style
    page = "<h1>ESP Web Server</h1><a href='/on'><button>LED on</button></a><a href='/off'><button>LED off</button></a>";
    
    // Open serial monitor
    Serial.begin(115200);
    
    // declare pinmode for onboard led
    pinMode(LED_BUILTIN, OUTPUT);

    // begin WiFi connection
    WiFi.begin(ssid, password);
    
    Serial.println("");
    
    // is connecting screen
    while(WiFi.status() != WL_CONNECTED){
        delay(500);
        Serial.print("#");
    }
    
    // Success and print IP address
    Serial.println("");
    Serial.print("Connected to: ");
    Serial.print(ssid);
    Serial.println("");
    Serial.print("IP address: ");
    Serial.print("http://");
    Serial.print(WiFi.localIP());
    Serial.println("/");
    
    // Serial.println(WiFi.localIP());
    
    // Create routes
    server.on("/", [](){
        server.send(200, "text/html", page);
    });
    
    server.on("/on", ledOn);
    server.on("/off",ledOff);

    // begin server and success message
    server.begin();
    Serial.println("Web server started!");
}


void loop(){
    server.handleClient(); // handles callback functions
}
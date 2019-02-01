// Include ESP8266 WiFi Libraries
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

// include servo header
#include <Servo.h>

// servo pins
int lrPin = 4;
int udPin = 2;

int lrPos=90;
int udPos=90;

#define D3 0

// create servos
Servo servoLR;
Servo servoUD;

// Wifi Credentials
const char* ssid = "Emceelamb";
const char* password = "guest123";

//  laser
const int laser = D3;

// Instantiate  server on port 80
ESP8266WebServer server(80);

// String for HTML
String page = "";

// turn led on
void ledOn(){
    server.send(200, "text/html", page);
    digitalWrite(laser, HIGH); // turns on LED
    delay(1000);
}

// turn led off
void ledOff(){
    server.send(200, "text/html", page);
    digitalWrite(laser, LOW); // turns off LED
    delay(1000);
}

void moveRight(){
    server.send(200, "text/html", page);
    lrPos-=2;
    servoLR.write(lrPos);
    delay(100);
}

void moveLeft(){
    server.send(200, "text/html", page);
    lrPos+=2;
    servoLR.write(lrPos);
    delay(100);
}

void moveDown(){
    server.send(200, "text/html", page);
    udPos-=2;
    servoUD.write(udPos);
    delay(100);
}

void moveUp(){
    server.send(200, "text/html", page);
    udPos+=2;
    servoUD.write(udPos);
    delay(100);
}

void setup(){

    // attach servos
    servoLR.attach(lrPin);
    servoUD.attach(udPin);

    // HTML of page with inline style
    page = "<h1>ESP Web Server</h1><a href='/on'><button>Laser On</button></a><a href='/off'><button>Laser off</button></a><a href='/left'><button>Left</button></a><a href='/up'><button>Up</button></a><a href='/down'><button>Down</button></a><a href='/right'><button>Right</button></a>  ";
    
    // Open serial monitor
    Serial.begin(115200);
    
    // declare pinmode for onboard led
    pinMode(laser, OUTPUT);

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

    server.on("/left",moveLeft);
    server.on("/right",moveRight);
    server.on("/up",moveUp);
    server.on("/down",moveDown);

    // begin server and success message
    server.begin();
    Serial.println("Web server started!");


}


void loop(){
    server.handleClient(); // handles callback functions
}
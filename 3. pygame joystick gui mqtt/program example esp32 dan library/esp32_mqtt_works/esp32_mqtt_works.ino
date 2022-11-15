#include <WiFi.h>
#include <PubSubClient.h>
#include <Wire.h>
#include <ESP32Servo.h> 

Servo myservo;
Servo myservo2; 

int servoPin = 18; 
int servoPin2 = 19;

int angle;
int angle2;

// Replace the next variables with your SSID/Password combination
const char* ssid = "Wokwi-GUEST";
const char* password = "";
const char* mqtt_server = "broker.emqx.io";

WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;
char msg[50];
int value = 0;


// LED Pin
const int led1_pin = 15;
const int led2_pin = 2;
const int led3_pin = 4;
const int led4_pin = 5;



void setup() {
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);

  pinMode(led1_pin, OUTPUT);
  pinMode(led2_pin, OUTPUT);
  pinMode(led3_pin, OUTPUT);
  pinMode(led4_pin, OUTPUT);

  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  ESP32PWM::allocateTimer(2);
  ESP32PWM::allocateTimer(3);
  myservo.setPeriodHertz(50);
  myservo.attach(servoPin, 500, 2400);  
  myservo2.attach(servoPin2, 500, 2400);   

  

}

void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* message, unsigned int length) {
  //Serial.print("Message arrived on topic: ");
  //Serial.print(topic);
  //Serial.print(". Message: ");
  String messageTemp;
  
  for (int i = 0; i < length; i++) {
    //Serial.print((char)message[i]);
    messageTemp += (char)message[i];
  }
  //Serial.println();

  
  if (String(topic) == "button1") {
    //Serial.print("Changing output to ");
    if(messageTemp == "on"){
      //Serial.println("ON");
      digitalWrite(led1_pin, HIGH);
    }
    else if(messageTemp == "off"){
      //Serial.println("OFF");
      digitalWrite(led1_pin, LOW);
    }
  }

  if (String(topic) == "button2") {
    //Serial.print("Changing output to ");
    if(messageTemp == "on"){
      //Serial.println("ON");
      digitalWrite(led2_pin, HIGH);
    }
    else if(messageTemp == "off"){
      //Serial.println("OFF");
      digitalWrite(led2_pin, LOW);
    }
  }

  if (String(topic) == "button3") {
    //Serial.print("Changing output to ");
    if(messageTemp == "on"){
      //Serial.println("ON");
      digitalWrite(led3_pin, HIGH);
    }
    else if(messageTemp == "off"){
      //Serial.println("OFF");
      digitalWrite(led3_pin, LOW);
    }
  }

  if (String(topic) == "button4") {
    //Serial.print("Changing output to ");
    if(messageTemp == "on"){
      //Serial.println("ON");
      digitalWrite(led4_pin, HIGH);
    }
    else if(messageTemp == "off"){
      //Serial.println("OFF");
      digitalWrite(led4_pin, LOW);
    }
  }
  

  if (String(topic) == "analog1_y") {
    //Serial.print("Changing output to ");
    angle = (messageTemp.toFloat() * 90) + 90;
    myservo.write(angle);   
  }

  if (String(topic) == "analog1_x") {
    //Serial.print("Changing output to ");
    angle2 = (messageTemp.toFloat() * 90) + 90;
    myservo2.write(angle2);   
  }

 


}



void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    if (client.connect("ESP32Client")) {
      Serial.println("connected");

      client.subscribe("button1");
      client.subscribe("button2");
      client.subscribe("button3");
      client.subscribe("button4");
      client.subscribe("analog1_y");
      client.subscribe("analog1_x");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}


void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();


  long now = millis();
  if (now - lastMsg > 1000) {
    lastMsg = now;
    
    



  }
}

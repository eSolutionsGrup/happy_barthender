#include <ESP8266WebServer.h>
#include <Wire.h>
#include <service/pump_service.h>
#include <PubSubClient.h>

ESP8266WebServer server(80);

PumpService gateService;

WiFiClient espClient;
PubSubClient client(espClient);
const char *mqttServer = "broker.hivemq.com";
const int mqttPort = 1883;
const char *mqttUser = "device";
const char *mqttPassword = "password";


void handlers() {
    server.on("/start1", HTTP_POST, [](){
        Serial.println("pump start");
        gateService.start1();
        server.send(200, "application/json", "ok");
    });

    server.on("/start2", HTTP_POST, [](){
        Serial.println("pump start");
        gateService.start2();
        server.send(200, "application/json", "ok");
    });

    server.on("/start3", HTTP_POST, [](){
        Serial.println("pump start");
        gateService.start3();
        server.send(200, "application/json", "ok");
    });

    server.on("/start4", HTTP_POST, [](){
        Serial.println("pump start");
        gateService.start4();
        server.send(200, "application/json", "ok");
    });

    server.on("/start5", HTTP_POST, [](){
        Serial.println("pump start");
        gateService.start5();
        server.send(200, "application/json", "ok");
    });

    server.on("/start6", HTTP_POST, [](){
        Serial.println("pump start");
        gateService.start6();
        server.send(200, "application/json", "ok");
    });

    server.on("/start7", HTTP_POST, [](){
        Serial.println("pump start");
        gateService.start7();
        server.send(200, "application/json", "ok");
    });

    server.on("/start8", HTTP_POST, [](){
        Serial.println("pump start");
        gateService.start8();
        server.send(200, "application/json", "ok");
    });

    server.on("/stop", HTTP_POST, [](){
        Serial.println("pump stop");
        gateService.stop1();
        gateService.stop2();
        gateService.stop3();
        gateService.stop4();
        server.send(200, "application/json", "ok");
    });

    server.on("/stop2", HTTP_POST, [](){
        Serial.println("pump stop");
        gateService.stop5();
        gateService.stop6();
        gateService.stop7();
        gateService.stop8();

        server.send(200, "application/json", "ok");
    });
}

//TODO: move it to mqtt
void callback(char *topic, byte *payload, unsigned int length) {
    Serial.println("received message");
    client.publish("hardware-response","fancy device message");
}


void setup() {
    Serial.begin(115200);
    WiFi.begin("", "");
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.println("Waiting for connection");
    }
    Serial.print("IP: ");
    Serial.println(WiFi.localIP().toString().c_str());
    Wire.begin();

    handlers();
    server.begin();
    gateService.begin();

    client.setServer(mqttServer, mqttPort);
    client.setCallback(callback);

    while (!client.connected()) {
        Serial.println("Connecting to MQTT...");
        if (client.connect("esp8266", mqttUser, mqttPassword)) {
            Serial.println("connected");
        } else {
            Serial.print("failed with state ");
            Serial.print(client.state());
            delay(2000);
        }
    }

    Serial.println("pinning");
    client.subscribe("/pour4me");
    Serial.println("subscribed");
}

void loop() {
    client.loop();
    server.handleClient();
}

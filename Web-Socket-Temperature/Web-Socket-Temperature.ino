#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <DHT.h>
#include <SPIFFS.h>

const char* ssid = "tempspot";
const char* password = "11111111";

AsyncWebServer server(80);
AsyncWebSocket ws("/ws");
DHT dht(26, DHT11); 

void notifyClients(float temperature, float humidity) {
  char msg[512];
  snprintf(msg, sizeof(msg), "{\"temperature\":%.2f,\"humidity\":%.2f}", temperature, humidity);
  ws.textAll(msg);
}

void onWsEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len) {
  if (type == WS_EVT_CONNECT) {
    Serial.println("Websocket client connection received");
    client->text("Connected");
  } else if (type == WS_EVT_DISCONNECT) {
    Serial.println("Client disconnected");
  }
}

String processor(const String& var){
  return String();
}

void setup() {
  Serial.begin(115200);
  dht.begin();

  WiFi.softAP(ssid, password);
  Serial.print("AP IP address: ");
  Serial.println(WiFi.softAPIP());

  ws.onEvent(onWsEvent);
  server.addHandler(&ws);

  server.on("/style.css", HTTP_GET, [](AsyncWebServerRequest *request) {
    if (SPIFFS.exists("/style.css")) {
      AsyncWebServerResponse *response = request->beginResponse(SPIFFS, "/style.css", "text/css");
      request->send(response);
    } else {
      request->send(404, "text/plain", "File not found");
    }
  });

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    Serial.println("Initializing SPIFFS...");
if (!SPIFFS.begin()) {
  Serial.println("Failed to mount file system");
  return;
}
Serial.println("SPIFFS initialized.");



Serial.println("Serving style.css...");
if (SPIFFS.exists("/style.css")) {
  Serial.println("style.css found.");
  
} else {
  Serial.println("style.css not found.");
  request->send(404, "text/plain", "File not found");
}
    if (SPIFFS.exists("/index.html")) {
      AsyncWebServerResponse *response = request->beginResponse(SPIFFS, "/index.html", "text/html");
      request->send(response);
    } else {
      request->send(404, "text/plain", "File not found");
    }
  });


  SPIFFS.begin();
  server.begin();
}

void loop() {
  static unsigned long lastTime = 0;
  unsigned long currentTime = millis();
  if (currentTime - lastTime > 2000) {
    lastTime = currentTime;
    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();
    if (!isnan(temperature) && !isnan(humidity)) { 
      notifyClients(temperature, humidity);
    }
  }
}

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

const char* ssid= "";
const char* password= "";

ESP8266WebServer server(80);

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status()!= WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("NodeMCU conectado no IP:");
  Serial.println(WiFi.localIP());
  Serial.print("Conectado ao WiFi");

  server.begin();
  Serial.println("webserver inicializado");
  delay(500);
  Serial.println("Acesse o endereço pelo: ");
  Serial.println(WiFi.localIP());

  server.on("/", [] (){
    server.send(200, "cabecalho", "bem vindo server nodeMCU");
  });

  server.on("/teste", [] (){
    server.send(200, "cabecalho", "bem vindo a pagina teste");
  });
 }

void loop() {

  server.handleClient();
    
}

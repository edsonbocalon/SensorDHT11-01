#include <WiFi.h>
#include "DHT.h"

// Configurações do DHT11
#define DHTPIN 4 // Pino de dados do DHT11 conectado ao GPIO 4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// Configurações Wi-Fi
const char* ssid = "SEU_SSID";       // Substitua pelo nome da sua rede Wi-Fi
const char* password = "SUA_SENHA"; // Substitua pela senha da sua rede

WiFiServer server(80); // Cria um servidor na porta 80

void setup() {
  Serial.begin(115200); // Inicializa o monitor serial
  dht.begin();

  // Conectando ao Wi-Fi
  Serial.print("Conectando ao Wi-Fi");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("\nWi-Fi conectado!");
  Serial.print("Endereço IP: ");
  Serial.println(WiFi.localIP());

  // Inicia o servidor
  server.begin();
}

void loop() {
  // Aguarda conexões de clientes
  WiFiClient client = server.available();
  if (client) {
    Serial.println("Cliente conectado!");

    // Lê temperatura e umidade
    float temperatura = dht.readTemperature();
    float umidade = dht.readHumidity();

    // Verifica erros de leitura
    if (isnan(temperatura) || isnan(umidade)) {
      Serial.println("Erro ao ler do sensor DHT11!");
      return;
    }

    // Envia resposta HTTP
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("Connection: close");
    client.println();
    client.println("<!DOCTYPE HTML>");
    client.println("<html>");
    client.println("<h1>Monitor de Temperatura e Umidade</h1>");
    client.printf("<p>Temperatura: %.2f &#8451;</p>", temperatura);
    client.printf("<p>Umidade: %.2f %%</p>", umidade);
    client.println("</html>");

    delay(1);
    client.stop();
    Serial.println("Cliente desconectado.");
  }
}

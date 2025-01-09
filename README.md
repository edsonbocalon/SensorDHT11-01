# Sensor de umidade e temperatura DHT11 com arduino esp32 com wifi

##### Usar o sensor DHT11 com ESP32 e Wi-Fi é uma ótima ideia para criar um projeto IoT que envie leituras de temperatura e umidade para a internet. Aqui está um exemplo que usa o protocolo HTTP para enviar os dados para um servidor ou monitorar via uma página web.

## Materiais Necessários
* ESP32
* Sensor DHT11
* Resistência de 10kΩ (opcional, para pull-up)
* Jumpers
* Protoboard

## Conexões
##### Conecte o DHT11 ao ESP32 conforme explicado anteriormente:
* VCC do DHT11 → 3.3V ou 5V no ESP32.
* Data do DHT11 → GPIO 4 no ESP32 (ou outro pino).
* GND do DHT11 → GND no ESP32.
Se necessário, use uma resistência de 10kΩ entre o VCC e o pino Data.

## Código no Arduino IDE
##### Certifique-se de instalar as bibliotecas:
* DHT sensor library (Adafruit).
* WiFi (já vem com o ESP32).

# Explicação do Código
##### 1. Conexão Wi-Fi:
* Configura o ESP32 para conectar-se à rede Wi-Fi.
* O endereço IP é mostrado no Monitor Serial.

##### 2. Servidor HTTP:
* O ESP32 atua como um servidor na porta 80.
* Um cliente (como um navegador) pode acessar o IP do ESP32 para visualizar os dados.

##### 3. Leitura do DHT11:
* O sensor fornece leituras de temperatura e umidade.
* Os dados são exibidos em uma página HTML gerada pelo ESP32.

# Configuração
##### 1. Substitua SEU_SSID e SUA_SENHA pelas credenciais da sua rede Wi-Fi.
##### 2. Faça o upload do código para o ESP32.
##### 3. Abra o Monitor Serial e anote o endereço IP exibido.
##### 4. Acesse o endereço IP no navegador para visualizar os dados.

#include "DHT.h"

#define DHTPIN 4     
#define DHTTYPE DHT22   
#define LDR_PIN 34   // LDR simulando o medidor de pH
#define RELAY_PIN 5  // Relé Azul (Bomba D'água)

#define BTN_N 25     // Botão Nitrogênio 
#define BTN_P 26     // Botão Fósforo 
#define BTN_K 27     // Botão Potássio 

DHT dht(DHTPIN, DHTTYPE);

bool vaiChover = false; // Controle da API do clima

void setup() {
  Serial.begin(115200);
  dht.begin();
  
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(BTN_N, INPUT_PULLUP); 
  pinMode(BTN_P, INPUT_PULLUP);
  pinMode(BTN_K, INPUT_PULLUP);
  
  digitalWrite(RELAY_PIN, LOW); // Bomba inicia desligada por segurança
  
  Serial.println("Iniciando Sistema FarmTech - Monitoramento de Soja");
}

void loop() {
  float umidadeSolo = dht.readHumidity();
  int valorLDR = analogRead(LDR_PIN);
  float pH = map(valorLDR, 0, 4095, 0, 14); // Mapeia a luz para escala de pH

  bool temN = (digitalRead(BTN_N) == LOW);
  bool temP = (digitalRead(BTN_P) == LOW);
  bool temK = (digitalRead(BTN_K) == LOW);

  if (Serial.available() > 0) {
    char comando = Serial.read();
    comando = toupper(comando); 

    if (comando == 'C') {
      vaiChover = true;
      Serial.println("Alerta de CHUVA! (Sistema de agua BLOQUEADO)");
    } else if (comando == 'S') {
      vaiChover = false;
      Serial.println("TEMPO SECO. (Sistema de agua LIBERADO)");
    }
    
    while(Serial.available() > 0) {
      Serial.read();
    }
  }

  // PH adequado da soja (Regra de Negócio da Soja) 
  bool phAdequado = (pH >= 5.5 && pH <= 7.5); 
  bool temNutriente = (temN || temP || temK); 
  
  // Fertirrigação: Se o pH está ruim, só recebe água se o produtor adicionou nutriente para ser dissolvido.
  bool terraProntaParaAgua = phAdequado || (!phAdequado && temNutriente);

  // A bomba liga se a terra estiver seca, SEM chuva prevista e pronta para receber água.
  if (umidadeSolo < 40.0 && !vaiChover && terraProntaParaAgua) {
    digitalWrite(RELAY_PIN, HIGH); 
  } else {
    digitalWrite(RELAY_PIN, LOW); 
  }

  // 4. Prints de Acompanhamento (Dashboard do Serial)
  Serial.print("Umidade Solo: "); Serial.print(umidadeSolo); Serial.print("% | ");
  Serial.print("pH (LDR): "); Serial.print(pH); Serial.print(" | ");
  Serial.print("NPK: ["); 
  Serial.print(temN ? "N" : "-"); Serial.print(temP ? "P" : "-"); Serial.print(temK ? "K" : "-"); 
  Serial.print("] | Bomba: ");
  Serial.println(digitalRead(RELAY_PIN) == HIGH ? "LIGADA" : "DESLIGADA");

  delay(2000); // 2s de leitura
}
const int pinoSensor = A0;  // Pino utilizado pelo sensor
const int pinoSensorChuva = 8;  // Pino digital conectado ao sensor de chuva

int valorLido;  // Variável que armazena o percentual de umidade do solo

int analogSoloSeco = 400;
;  // Valor medido com o solo seco (ajuste conforme necessário)
int analogSoloMolhado = 100;  // Valor medido com o solo molhado (ajuste conforme necessário)
int percSoloSeco = 0;  // Menor percentual do solo seco (0% - não alterar)
int percSoloMolhado = 100;  // Maior percentual do solo molhado (100% - não alterar)

void setup() {
  Serial.begin(9600);  // Inicializa a comunicação serial
  pinMode(pinoSensorChuva, INPUT);  // Configura o pino do sensor de chuva como entrada
  Serial.println("Lendo a umidade do solo e o sensor de chuva...");
  delay(1000);  // Intervalo de 1 segundo
}

void loop() {
  valorLido = constrain(analogRead(pinoSensor), analogSoloMolhado, analogSoloSeco);  // Mantém valorLido dentro do intervalo
  valorLido = map(valorLido, analogSoloMolhado, analogSoloSeco, percSoloMolhado, percSoloSeco);  // Executa a função "map" de acordo com os parâmetros passados

  int sensorChuva = digitalRead(pinoSensorChuva);  // Lê o valor do sensor de chuva

  Serial.print("Umidade do solo: ");
  Serial.print(valorLido);
  Serial.println("%");

  if (sensorChuva == HIGH) {
    //Serial.println("Chovendo");
    Serial.println("Chuva: 0");
  } else {
    //Serial.println("Sem chuva");
    Serial.println("Chuva: 1");
  }

  Serial.println();
  delay(1000);  // Intervalo de 1 segundo
}
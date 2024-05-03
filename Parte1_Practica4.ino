// Definir los pines de los interruptores
#define SWITCH1 2
#define SWITCH2 3
#define SWITCH3 4

// Definir los pines del decodificador CD4511
#define PIN_A 5
#define PIN_B 6
#define PIN_C 7
#define PIN_D 8

void setup() {
  // Configurar los pines de los interruptores como entrada
  pinMode(SWITCH1, INPUT_PULLUP);
  pinMode(SWITCH2, INPUT_PULLUP);
  pinMode(SWITCH3, INPUT_PULLUP);

  // Configurar los pines del decodificador CD4511 como salida
  pinMode(PIN_A, OUTPUT);
  pinMode(PIN_B, OUTPUT);
  pinMode(PIN_C, OUTPUT);
  pinMode(PIN_D, OUTPUT);
}

void loop() {
  // Leer el estado de los interruptores
  bool switch1 = digitalRead(SWITCH1) == LOW;
  bool switch2 = digitalRead(SWITCH2) == LOW;
  bool switch3 = digitalRead(SWITCH3) == LOW;

  // Determinar la velocidad de conteo
  int delayTime;
  if (switch1) {
    delayTime = 1000;  // 1 segundo
  } else if (switch2) {
    delayTime = 2000;  // 2 segundos
  } else if (switch3) {
    delayTime = 3000;  // 3 segundos
  } else {
    delayTime = 500;   // 500 milisegundos
  }

  // Realizar el conteo ascendente de 0 a 9
  for (int i = 0; i <= 9; i++) {
    // Convertir el número a binario y mostrarlo en el display de 7 segmentos
    digitalWrite(PIN_A, bitRead(i, 0));
    digitalWrite(PIN_B, bitRead(i, 1));
    digitalWrite(PIN_C, bitRead(i, 2));
    digitalWrite(PIN_D, bitRead(i, 3));
    
    delay(delayTime);
  }
}

// Definir los pines de los interruptores
#define SWITCH1 2
#define SWITCH2 3
#define SWITCH3 4

// Definir los pines de los LEDs
int leds[6] = {5, 6, 7, 8, 9, 10};

// Definir los pines del display de 7 segmentos
int display[7] = {11, A0, A1, A2, A3, A4, A5};

// Matriz para almacenar los códigos de las letras C, U, A, T, R, O
int letters[6][7] = {
  {0, 0, 0, 1, 1, 0, 1},  // C
  {0, 0, 1, 1, 1, 0, 0},  // U
  {1, 1, 1, 0, 1, 1, 1},  // A
  {0, 0, 0, 1, 1, 1, 1},  // T
  {0, 0, 0, 0, 1, 0, 1},  // R
  {0, 0, 1, 1, 1, 0, 1}   // O
};

void setup() {
  // Configurar los pines de los interruptores como entrada
  pinMode(SWITCH1, INPUT_PULLUP);
  pinMode(SWITCH2, INPUT_PULLUP);
  pinMode(SWITCH3, INPUT_PULLUP);

  // Configurar los pines de los LEDs como salida
  for (int i = 0; i < 6; i++) {
    pinMode(leds[i], OUTPUT);
  }

  // Configurar los pines del display de 7 segmentos como salida
  for (int i = 0; i < 7; i++) {
    pinMode(display[i], OUTPUT);
  }

  // Iniciar el monitor serial
  Serial.begin(9600);
}

void loop() {
  // Leer el estado de los interruptores
  bool switch1 = digitalRead(SWITCH1) == LOW;
  bool switch2 = digitalRead(SWITCH2) == LOW;
  bool switch3 = digitalRead(SWITCH3) == LOW;

  // Si se presionan el primer y tercer interruptor, imprimir el mensaje en el monitor serial
  if (switch1 && switch3) {
    Serial.println("Gracias por su atencion");
  }

  // Si se presiona el primer interruptor, imprimir el mensaje en el monitor serial
  if (switch1 && !switch3) {
    Serial.println("Practica No. 4 - su nombre");
  }

  // Si se presiona el segundo interruptor, realizar la secuencia del auto fantástico
  if (switch2) {
    for (int j = 0; j < 3; j++) {
      for (int i = 0; i < 6; i++) {
        digitalWrite(leds[i], HIGH);
        delay(500);
        digitalWrite(leds[i], LOW);
      }
    }
    // Hacer parpadear todos los LEDs 3 veces
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 6; j++) {
        digitalWrite(leds[j], HIGH);
      }
      delay(500);
      for (int j = 0; j < 6; j++) {
        digitalWrite(leds[j], LOW);
      }
      delay(500);
    }
  }

  // Si se presiona el tercer interruptor, mostrar la palabra "CUATRO" en el display de 7 segmentos
  if (switch3 && !switch1) {
    for (int i = 0; i < 6; i++) {
      for (int j = 0; j < 7; j++) {
        digitalWrite(display[j], letters[i][j]);
      }
      delay(2000);
    }
  }
}
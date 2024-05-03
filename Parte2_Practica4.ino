// Definiciones de los botones y las velocidades
#define BOTON_1 2 // Botón 1 conectado al pin 2
#define BOTON_2 3 // Botón 2 conectado al pin 3
#define VELOCIDAD_1 500 // Velocidad de secuencia para el botón 1
#define VELOCIDAD_2 VELOCIDAD_1 * 2 // Velocidad de secuencia para el botón 2
#define NUM_LEDS 9 // Número de LEDs

// Array que contiene los pines de los LEDs
int leds[NUM_LEDS] = {4, 5, 6, 7, 8, 9, 10, 11, 12};

// Función de configuración que se ejecuta una vez al inicio
void setup() {
  // Configuración de los pines de los botones como entradas
  pinMode(BOTON_1, INPUT);
  pinMode(BOTON_2, INPUT);

  // Configuración de los pines de los LEDs como salidas
  for (int i = 0; i < NUM_LEDS; i++) {
    pinMode(leds[i], OUTPUT);
  }

  // Inicio de la comunicación serial
  Serial.begin(9600);
}

// Función de bucle que se ejecuta continuamente
void loop() {
  // Velocidad de secuencia inicial
  int velocidad = 0;

  // Verificación de si los botones están presionados
  if (digitalRead(BOTON_1) == HIGH) {
    // Si el botón 1 está presionado, establece la velocidad a VELOCIDAD_1
    velocidad = VELOCIDAD_1;
    Serial.println("Secuencia - velocidad 1");
  } else if (digitalRead(BOTON_2) == HIGH) {
    // Si el botón 2 está presionado, establece la velocidad a VELOCIDAD_2
    velocidad = VELOCIDAD_2;
    Serial.println("Secuencia - velocidad 2");
  }

  // Si se ha seleccionado una velocidad
  if (velocidad > 0) {
    // Realiza la secuencia de izquierda a derecha y de derecha a izquierda tres veces
    for (int j = 0; j < 3; j++) {
      for (int i = 0; i < NUM_LEDS; i++) {
        digitalWrite(leds[i], HIGH); // Enciende el LED
        delay(velocidad); // Espera el tiempo correspondiente a la velocidad de secuencia
        digitalWrite(leds[i], LOW); // Apaga el LED
      }
      for (int i = NUM_LEDS - 1; i >= 0; i--) {
        digitalWrite(leds[i], HIGH); // Enciende el LED
        delay(velocidad); // Espera el tiempo correspondiente a la velocidad de secuencia
        digitalWrite(leds[i], LOW); // Apaga el LED
      }
    }

    // Realiza el parpadeo de todos los LEDs tres veces
    for (int j = 0; j < 3; j++) {
      for (int i = 0; i < NUM_LEDS; i++) {
        digitalWrite(leds[i], HIGH); // Enciende todos los LEDs
      }
      delay(velocidad); // Espera el tiempo correspondiente a la velocidad de secuencia
      for (int i = 0; i < NUM_LEDS; i++) {
        digitalWrite(leds[i], LOW); // Apaga todos los LEDs
      }
      delay(velocidad); // Espera el tiempo correspondiente a la velocidad de secuencia
    }
  }
}

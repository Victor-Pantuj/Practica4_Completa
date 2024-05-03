#define PIN_INCREMENTO 2 // Pin conectado al interruptor de asender
#define PIN_DECREMENTO 3 // Pin conectado al interruptor de desender

int conteo = 0; // Variable para almacenar el conteo
int estadoAnteriorIncremento = HIGH; // Estado anterior del botón de Asender
int estadoAnteriorDecremento = HIGH; // Estado anterior del botón de desender

void setup() {
  pinMode(PIN_INCREMENTO, INPUT_PULLUP); // Configura el pin como entrada con resistencia de pullup interna
  pinMode(PIN_DECREMENTO, INPUT_PULLUP); // Configura el pin como entrada con resistencia de pullup interna
  Serial.begin(9600); // Inicia la comunicación serial
}

void loop() {
  int estadoActualIncremento = digitalRead(PIN_INCREMENTO); // Lee el estado actual del botón de incremento
  int estadoActualDecremento = digitalRead(PIN_DECREMENTO); // Lee el estado actual del botón de decremento

  // Si el botón de incremento se presionó
  if (estadoAnteriorIncremento == HIGH && estadoActualIncremento == LOW) {
    if (conteo < 99) { // Si el conteo es menor a 99
      conteo++; // Incrementa el conteo
    } else { // Si el conteo es igual a 99
      conteo = 0; // Reinicia el conteo a cero
    }
    Serial.println(conteo); // Imprime el valor actual del conteo
  }

  // Si el botón de desender se presionó
  if (estadoAnteriorDecremento == HIGH && estadoActualDecremento == LOW) {
    if (conteo > 0) { // Si el conteo es mayor a 0
      conteo--; // Desiende el conteo
    } else { // Si el conteo es igual a 0
      conteo = 99; // Reinicia el conteo a 99
    }
    Serial.println(conteo); // Imprime el valor actual del conteo
  }

  // Actualiza los estados anteriores de los botones
  estadoAnteriorIncremento = estadoActualIncremento;
  estadoAnteriorDecremento = estadoActualDecremento;
}

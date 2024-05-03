//definir los pines de los botones
#define PIN_INCREMENTO 2 
#define PIN_DECREMENTO 3 

int conteo = 0; // Variable para almacenar el conteo
int estadoAnteriorIncremento = HIGH; // Estado anterior del botón 1
int estadoAnteriorDecremento = HIGH; // Estado anterior del botón 2

void setup() {
  // Configura el pin como entrada
  pinMode(PIN_INCREMENTO, INPUT_PULLUP); 
  pinMode(PIN_DECREMENTO, INPUT_PULLUP); 
  Serial.begin(9600); // Inicia la comunicación serial
}

void loop() {
  //Lee el estado actual del botón
  int estadoActualIncremento = digitalRead(PIN_INCREMENTO); 
  int estadoActualDecremento = digitalRead(PIN_DECREMENTO);

  // Si el botón de incremento se presionó
  if (estadoAnteriorIncremento == HIGH && estadoActualIncremento == LOW) {
    if (conteo < 99) { // Si el conteo es menor a 99
      conteo++; // Incrementa el conteo
    } else { // Si el conteo es igual a 99
      conteo = 0; // Reinicia el conteo a cero
    }
    Serial.println(conteo); // Imprime el valor actual del conteo
  }

  // Si el botón de decremento se presionó
  if (estadoAnteriorDecremento == HIGH && estadoActualDecremento == LOW) {
    if (conteo > 0) { // Si el conteo es mayor a 0
      conteo--; // Decrementa el conteo
    } else { // Si el conteo es igual a 0
      conteo = 99; // Reinicia el conteo a 99
    }
    Serial.println(conteo); // Imprime el valor actual del conteo
  }

  // Actualiza los estados anteriores de los botones
  estadoAnteriorIncremento = estadoActualIncremento;
  estadoAnteriorDecremento = estadoActualDecremento;
}

//Programa: Sensor Ultrasonico com motores

//Carrega a biblioteca do sensor ultrassonico
#include <Ultrasonic.h>

//Define os pinos para o trigger e echo
#define pino_trigger 8
#define pino_echo 9

//#define pino_trigger2 10
//#define pino_echo2 9

int Motor_D1 = 3;   //IN1
int Motor_D2 = 4;   //IN2
int Motor2_D1 = 5;  //IN3
int Motor2_D2 = 6;  //IN4

//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(pino_trigger, pino_echo);
//Ultrasonic ultrasonic2(pino_trigger2, pino_echo2);

void setup()
{
  Serial.begin(9600);
  Serial.println("Lendo dados do sensor...");
  pinMode(Motor_D1, OUTPUT);
  pinMode(Motor_D2, OUTPUT);
  pinMode(Motor2_D1, OUTPUT);
  pinMode(Motor2_D2, OUTPUT);
}

void loop()
{
  //Le as informacoes do sensor, em cm
  float cmMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);

  //  float cmMsec2;
  //  long microsec2 = ultrasonic2.timing();
  //  cmMsec2 = ultrasonic2.convert(microsec2, Ultrasonic::CM);

  //Exibe informacoes no serial monitor
  Serial.print("Distancia sensor 1 em cm: ");
  Serial.print(cmMsec);
  //  Serial.print(" - Distancia sensor 2 em cm: ");
  //  Serial.println(cmMsec2);
  delay(1000);

  if (cmMsec < 30) {

    digitalWrite(Motor_D1, LOW);
    digitalWrite(Motor_D2, HIGH);
    digitalWrite(Motor2_D1, HIGH);
    digitalWrite(Motor2_D2, LOW);
    Serial.println("Ambos ligados para frente");
    delay(250);
  } else {
    digitalWrite(Motor_D1, HIGH);
    digitalWrite(Motor_D2, LOW);
    digitalWrite(Motor2_D1, LOW);
    digitalWrite(Motor2_D2, HIGH);
    Serial.println("Ambos ligados para tras");
    delay(1000);
     digitalWrite(Motor_D1, HIGH);
    digitalWrite(Motor_D2, LOW);
    digitalWrite(Motor2_D1, HIGH);
    digitalWrite(Motor2_D2, LOW);
    Serial.println("Ambos ligados para esquerda");
    delay(1000);
    
    
  }

}

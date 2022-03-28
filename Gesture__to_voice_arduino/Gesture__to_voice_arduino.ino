const int flexPin1 = A0;      // Pin connected to voltage divider output
const int flexPin2 = A1;      // Pin connected to voltage divider output
const int flexPin3 = A2;      // Pin connected to voltage divider output
const int flexPin4 = A3;      // Pin connected to voltage divider output

// Change these constants according to your project's design
const float VCC = 5;      // voltage at Ardunio 5V line
const float R_DIV = 47000.0;  // resistor used to create a voltage divider

const float flatResistance1 = 25000.0; // resistance when flat
const float bendResistance1 = 100000.0;  // resistance at 90 deg

const float flatResistance2 = 25000.0; // resistance when flat
const float bendResistance2 = 100000.0;  // resistance at 90 deg

const float flatResistance3 = 25000.0; // resistance when flat
const float bendResistance3 = 100000.0;  // resistance at 90 deg

const float flatResistance4 = 25000.0; // resistance when flat
const float bendResistance4 = 100000.0;  // resistance at 90 deg

float sensor1();
float sensor2();
float sensor3();
float sensor4();

void setup() {
  Serial.begin(9600);
  pinMode(flexPin1, INPUT);
  pinMode(flexPin2, INPUT);
  pinMode(flexPin3, INPUT);
  pinMode(flexPin4, INPUT);
}

void loop() {

  float A = sensor1();
  //Serial.print("Sensor1:");
  //Serial.print(A);
  //Serial.print(",");

  float B = sensor2();
  //Serial.print("Sensor2:");
  //Serial.print(B);
  //Serial.print(",");

  float C = sensor3();
  //Serial.print("Sensor3:");
  //Serial.print(C);
  //Serial.print(",");

  float D = sensor4();
  //Serial.print("Sensor4:");
  //Serial.print(D);
  //Serial.println();

  //Serial.print(A,B,C,D);




  //G1
  if ((A <= 16) && (B >= 20) && (C >= 20) && (D >= 20)) {
    //Serial.println("need ");
     Serial.println(5);
  }

  //G2
 else if ((A <= 16) && (B <= 25) && (C >= 30) && (D >= 30)) {
    //Serial.println("need ");
     Serial.println(2);
  }

  //G3
 else if ((A <= 20) && (B <= 20) && (C <= 20) && (D >= 25)) {
    //Serial.println("need ");
     Serial.println(4);
  }


  //G4
  else if ((A >= 25) && (B >= 25) && (C >= 25) && (D >= 25)) {
    //Serial.println("need ");
     Serial.println(7);
  }

  //G5
   else if ((A >= 25) && (B <= 25) && (C <= 25) && (D <= 25)) {
    //Serial.println("need ");
     Serial.println(1);
  }

  //G6
 else if ((A >= 25) && (B >= 25) && (C <= 25) && (D <= 25)) {
    //Serial.println("need ");
     Serial.println(3);
  }



  //G7
  else if ((A >= 25) && (B >= 25) && (C >= 25) && (D <= 25)) {
    //Serial.println("need ");
     Serial.println(6);
  }




}

float sensor1() {

  // Read the ADC of Sensor 1, and calculate voltage and resistance from it
  int ADCflex1 = analogRead(flexPin1);
  float Vflex1 = ADCflex1 * VCC / 1023.0;
  float Rflex1 = R_DIV * (VCC / Vflex1 - 1.0);
  // Serial.println("Resistance1: " + String(Rflex1) + " ohms");

  //sensor 1 bend angle:
  float angle1 = map(Rflex1, flatResistance1, bendResistance1, 0, 90.0);
  //Serial.println("Bend1: " + String(angle1) + " degrees");
  //Serial.println();
  delay(500);
  return angle1;

}

float sensor2() {

  // Read the ADC of Sensor 2, and calculate voltage and resistance from it
  int ADCflex2 = analogRead(flexPin2);
  float Vflex2 = ADCflex2 * VCC / 1023.0;
  float Rflex2 = R_DIV * (VCC / Vflex2 - 1.0);
  //Serial.println("Resistance2: " + String(Rflex2) + " ohms");

  // sensor 2 bend angle:
  float angle2 = map(Rflex2, flatResistance2, bendResistance2, 0, 90.0);
  //Serial.println("Bend2: " + String(angle2) + " degrees");
  //Serial.println();
  delay(500);
  return angle2;
}

float sensor3() {

  // Read the ADC of Sensor 3, and calculate voltage and resistance from it
  int ADCflex3 = analogRead(flexPin3);
  float Vflex3 = ADCflex3 * VCC / 1023.0;
  float Rflex3 = R_DIV * (VCC / Vflex3 - 1.0);
  //Serial.println("Resistance3: " + String(Rflex3) + " ohms");

  // sensor 3 bend angle:
  float angle3 = map(Rflex3, flatResistance3, bendResistance3, 0, 90.0);
  //Serial.println("Bend3: " + String(angle3) + " degrees");
  //Serial.println();
  delay(500);
  return angle3;

}

float sensor4() {

  // Read the ADC of Sensor 4, and calculate voltage and resistance from it
  int ADCflex4 = analogRead(flexPin4);
  float Vflex4 = ADCflex4 * VCC / 1023.0;
  float Rflex4 = R_DIV * (VCC / Vflex4 - 1.0);
  //Serial.println("Resistance4: " + String(Rflex4) + " ohms");

  // sensor 3 bend angle:
  float angle4 = map(Rflex4, flatResistance4, bendResistance4, 0, 90.0);
  //Serial.println("Bend4: " + String(angle4) + " degrees");
  //Serial.println();
  delay(500);
  return angle4;


}

#include <Wire.h>


int buzzer = 3;
int DC = 9;
int smokesensor = 4;
int CTD1 = 5;
int CTD2 = 6;
int ct1 = 7;
int ct2 = 8;

void coi_quat1(){
  digitalWrite(DC, HIGH);
  digitalWrite(buzzer,HIGH);
}

void coi_quat2(){
  digitalWrite(DC, LOW);
  digitalWrite(buzzer,LOW);
}

void cua_mo(){
  digitalWrite(CTD1, HIGH);
  digitalWrite(CTD2, LOW);
}

void cua_dong(){
  digitalWrite(CTD1, LOW);
  digitalWrite(CTD2, HIGH);
}

void stop(){
  digitalWrite(CTD1, LOW);
  digitalWrite(CTD2, LOW);
}




void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(smokesensor,INPUT);
  pinMode(ct1,INPUT);
  pinMode(ct2,INPUT);
  pinMode(DC, OUTPUT);
  pinMode(CTD1, OUTPUT);
  pinMode(CTD2, OUTPUT);
}

void loop() {
  int smokevalue = digitalRead(smokesensor);
  int ctdung1 = digitalRead(ct1);
  int ctdung2 = digitalRead(ct2);

  if(smokevalue == 0 && ctdung2 == 1 ){
    coi_quat1();
    cua_mo();
  }else if(smokevalue == 1 && ctdung1 == 1){
    coi_quat2();
    cua_dong();
  }
  else stop();                           
}

#include<IRremote.h>
#define up 16601263
#define down 16584943
#define left 16589023
#define right 16605343
int recPin=12;
IRrecv irrecv(recPin);
decode_results results;
int lmotor=11;
int rmotor=9;
int lmotor2=10;
int rmotor2=8;
void setup()
{
 irrecv.enableIRIn();
 pinMode(lmotor, OUTPUT);
 pinMode(rmotor, OUTPUT);
 pinMode(lmotor2, OUTPUT);
 pinMode(rmotor2, OUTPUT);
}
void loop()
{
 if(irrecv.decode(&results)) {
 unsigned int value = results.value;
 switch(value){
 case left:
 digitalWrite(rmotor,HIGH);
 digitalWrite(lmotor,LOW);
 digitalWrite(rmotor2,LOW);
 digitalWrite(lmotor2,LOW);
 break;
 case right:
 digitalWrite(rmotor,LOW);
 digitalWrite(lmotor,HIGH);
 digitalWrite(rmotor2,LOW);
 digitalWrite(lmotor2,LOW);
 break;
 case up: 
 digitalWrite(rmotor,HIGH);
 digitalWrite(lmotor,HIGH);
 digitalWrite(rmotor2,LOW);
 digitalWrite(lmotor2,LOW);
 break;
 case down:
 digitalWrite(rmotor,LOW);
 digitalWrite(lmotor,LOW);
 digitalWrite(rmotor2,HIGH);
 digitalWrite(lmotor2,HIGH);
 }
 irrecv.resume();
 }
}
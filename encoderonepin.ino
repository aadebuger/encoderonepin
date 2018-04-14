int val; 
 int encoder0PinA = D7;
 int encoder0PinB = 6;
 int encoder0Pos = 0;
 int encoder0PinALast = LOW;
 int n = LOW;
unsigned long newtime;
unsigned long oldtime = 0;
long count = 0; //计数值
 void setup() { 
   pinMode (encoder0PinA,INPUT);

 //  pinMode(encoder0PinA,INPUT_PULLUP);
   
  // pinMode (encoder0PinB,INPUT);
   Serial.begin (9600);
   Serial.println("hello pin 5");
   pinMode(BUILTIN_LED, OUTPUT); 
   oldtime= millis();
   attachInterrupt(encoder0PinA, blinkA, RISING);
 } 

 void loop() { 
   val = digitalRead(encoder0PinA);
    digitalWrite(BUILTIN_LED, val); 
   if (val == HIGH) {//上升沿
    
       encoder0Pos++;
   //  Serial.print (encoder0Pos);
   //  Serial.print ("/");
     
     }
      newtime = millis();
      if ( (newtime-oldtime)>5000)
    {

       Serial.print (encoder0Pos);
     Serial.print ("#");
       Serial.print (count);
     Serial.print ("/");
     oldtime = newtime;

    }
    delay(100);
   /*
   if ((encoder0PinALast == LOW) && (n == HIGH)) {//上升沿
     if (digitalRead(encoder0PinB) == LOW) {
       encoder0Pos--;
     } else {
       encoder0Pos++;
     }
     Serial.print (encoder0Pos);
     Serial.print ("/");
   } 
   encoder0PinALast = n;
   */
 } 
 void blinkA()
{
  if(digitalRead(encoder0PinA)==1)
       { count ++;}
 // if(digitalRead(3)==1)
   //   { count3 ++;}
    //   if(digitalRead(2)==0)
    //   {count--;}
}


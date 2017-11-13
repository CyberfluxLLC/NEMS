
#define helloPin 3
#define hiPin 4
#define byePin 5
#define kachifoPin 6

boolean helloState = false;
boolean hiState = false;
boolean byeState = false;
boolean kachifoState = false;

String rxdata;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  
  pinMode(helloPin,OUTPUT);
  digitalWrite(helloPin,LOW);

  pinMode(hiPin,OUTPUT);
  digitalWrite(hiPin,LOW);

  pinMode(byePin,OUTPUT);
  digitalWrite(byePin,LOW);

  pinMode(kachifoPin,OUTPUT);
  digitalWrite(kachifoPin,LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0){

    //read the string sent from the esp8266
    rxdata = Serial.readStringUntil('\n');
    
    if(rxdata.equals("Hello") ){

      //toggle the state and activate the pin
      helloState = !helloState;
      digitalWrite(helloPin, helloState);

      if(helloState) 
        Serial.println("H1");
      else 
        Serial.println("H0");

     } // end if(rxdata.equals("Hello") 
    
    if(rxdata.equals("Hi") ){

      //toggle the state and activate the pin
      hiState = !hiState;
      digitalWrite(hiPin, hiState);

       if(hiState) 
        Serial.println("h1");
      else 
        Serial.println("h0");
      
      } // end if(rxdata.equals("Hi") )
      
    if(rxdata.equals("Bye") ){

      //toggle the state and activate the pin
      byeState = !byeState;
      digitalWrite(byePin, byeState);

      if(byeState) 
        Serial.println("B1");
      else 
        Serial.println("B0"); 
      
      } // end if(rxdata.equals("Bye") ) 

    if(rxdata.equals("Kachifo") ){

      //toggle the state and activate the pin
      kachifoState = !kachifoState;
      digitalWrite(kachifoPin, kachifoState);

      if(kachifoState) 
        Serial.println("K1");
      else 
        Serial.println("K0");  
      
      } //end if(rxdata.equals("Kachifo") )
      
    }   // end if(Serial.available()>0)
}

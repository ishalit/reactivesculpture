/*
read values from sensors and send via serial port
*/

int x = 0;                              // a place to hold pin values
int ledpin = 13;
int y = 0;

void setup()
{
  Serial.begin(115200);               // 115200 is the default Arduino Bluetooth speed
  digitalWrite(13,HIGH);              ///startup blink
  delay(600);
  digitalWrite(13,LOW);
  pinMode(13,INPUT);
}

void loop()
{ 

y = analogRead(3);
if (y < 994) {
  tone(12, 200);
  delay(500);
  noTone(12);
}

if (Serial.available() > 0){         // Check serial buffer for characters
        
    if (Serial.read() == 'r') {       // If an 'r' is received then read the pins
    
for (int pin= 0; pin<=4; pin++){      // Read and send analog pins 0-5
    x = analogRead(pin);
    sendValue (x);
    }

for (int pin= 2; pin<=13; pin++){     // Read and send digital pins 2-13
    x = digitalRead(pin);
    sendValue(x);
    }
  
    Serial.println();                 // Send a carriage returnt to mark end of pin data. 
    delay (5);                        // add a delay to prevent crashing/overloading of the serial port
  
  }
 }
}

void sendValue (int x){              // function to send the pin value followed by a "space". 
 Serial.print(x);
 Serial.write(32); 
}

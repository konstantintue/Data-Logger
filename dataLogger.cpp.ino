#include <SPI.h> 
#include <SD.h>  

const char* filename = "Light.csv";

File file;

void setup() {
  Serial.begin(9600);
 
  pinMode(10, OUTPUT); 
  
  if (!SD.begin(10)) {
    Serial.println("Error : Push the reset button");
    for (;;); 
  }
  
  file = SD.open(filename, FILE_WRITE);
 
  if (file.size() == 0) {
    file.println("Brightness value per seconds");
    file.flush();
  }
}

void loop() { 
    measure();
    delay(600000);
}

void measure() {
  int lightvalue = analogRead(A0); 
  Serial.println(lightvalue);
  file.println(lightvalue);
  file.flush();
}

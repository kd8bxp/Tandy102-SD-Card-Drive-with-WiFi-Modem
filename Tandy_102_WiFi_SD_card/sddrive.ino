void SDsetup(){
  


  if(!SD.begin(5)){
  //OLED Display Card Ready/Not Ready
    //Serial.println("SD Card Not Found");
    display.drawString(0,0,"SD Card Not Found.");
    display.drawString(0,50,"Power OFF before inserting card.");
    display.display();
    delay(5000);
    ESP.restart();
  } else {
    //Serial.println("SD Card Found");
    display.drawString(0,0,"Ready.");
    display.display();
  }
  delay(100);
 SDloop();
}


void SDloop() {

while(digitalRead(BUTTON) != LOW) {

  char cInChar;

  while (Serial.available()) {
    cInChar = (char)Serial.read();
    InOut.SerialIn(cInChar);
  }

  InOut.NoDataIn();
}
}

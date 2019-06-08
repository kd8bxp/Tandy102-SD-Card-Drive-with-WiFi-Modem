void FTPsetup(){
  WiFi.begin(FTPssid, FTPpassword);
  Serial.println("");
  display.clear();
   while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
display.clear();
display.drawString(32,0,"FTP Server");
display.drawString(0,10,"IP: ");
//display.drawString(16, 10, (String)WiFi.localIP());
display.drawString(16,10, WiFi.localIP().toString().c_str());
display.drawString(0,20,"Username: esp32");
display.drawString(0,30,"Password: esp32");
//display.display();
  /////FTP Setup, ensure SD is started before ftp;  /////////
  
  if (SD.begin(5)) {
      Serial.println("SD opened!");
       display.drawString(0,53,"Ready....");
      display.display();
      ftpSrv.begin("esp32","esp32");    //username, password for ftp.  set ports in ESP32FtpServer.h  (default 21, 50009 for PASV)
  }   else {
    Serial.println("SD Not Ready.");
    display.drawString(0,53,"Error - Reboot");
    display.display();
    delay(5000);
    ESP.restart(); 
  }
  FTPloop();
  
}

void FTPloop() {
  while(digitalRead(BUTTON) != LOW) {
    ftpSrv.handleFTP();        //make sure in loop you call handleFTP()!! 
    yield();  
  }
}

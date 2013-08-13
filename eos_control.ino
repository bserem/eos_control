/*
 The following sketch controls focus and shutter on Canon EOS Digital cameras.
 In order to make sure that you don't damage your camera you need a relay (or an optocoupler).
 
 EOS Remotes work by shot-circuiting the focus/shutter pins on the camera.
 The camera PROVIDES the power for anything to work. DO NOT provide any power to the camera.
 This is where the relays come in, you control them by arduino and they short-circuit the camera pins.
 
 In my case I used an EDR201A0500. There might be better options out there but this easily available
 in my city (and only one of them sadly, so I can control either focus or shutter+focus at the moment).
 
 NOT TO BE CONNECTED TO AN ACTUAL EOS CAMERA WITHOUT PROPER PRECAUTIONS
 
 Information: http://doc-diy.net/photo/eos_wired_remote/
 Inspiration: http://doc-diy.net/photo/smatrig21/ (excellent little tool, thnx Luc)
 */

int focusPin = 9;
int shutterPin = 8;
int LED = 13;

int counter = 0;

void setup() {
  pinMode(focusPin, OUTPUT);
  pinMode(shutterPin, OUTPUT);
  pinMode(LED, OUTPUT);
}

void focus() {
  digitalWrite(focusPin, HIGH);
  delay(2000); //not sure if it is enough for camera to establish focus
  digitalWrite(focusPin, LOW);
}

void shoot() {
  digitalWrite(shutterPin, HIGH);
  digitalWrite(LED, HIGH);  //light on board led when shooting and 5sec afterwords
  delay(2000); //fires 5 shots on my EOS5D in burst (of course only one in no burst)
  digitalWrite(shutterPin, LOW);
  delay(5000);
  digitalWrite(LED, LOW);
}

void takePhoto() {
  focus();
  shoot();
}

//by modifying the loop() function you can experiment with time-lapse photography
//future updates will allow for HDR photography too
void loop() {
  if (counter == 0) {
    takePhoto();
    counter = 1; //run only once, since this is a project under development
  }
}

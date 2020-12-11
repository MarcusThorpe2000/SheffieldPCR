void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}

boolean holdConstTemp(long targetTime, double targetTemp){
  int cycleDelay = 200 //ms pause between cycle
  int heatDelay = 100
  int coolDelay = 80
  tolerance = 0.5 // +/- allows passive cooling to prevent fan causing undershoot
  long initalTime = millis(); // Time passed
  long elapsedTime = millis() - initialTime // time from start
  while (elapsedTime < targetTime){
    currentTemp = resistor.readCelsius();
    printTemp(initialTime);
    if(currentTep < targetTemp){
      digitalWrite(heatPin, HIGH)// turns on heating
      delay(heatDelay); // holds heating for 0.1s
      digitalWrite(heatPin, HIGH) // turns of heating
    }else if(currentTep > (targetTemp)+tolerance){
      digitalWrite(fanPin, HIGH) // turns on fan
      delay(coolDelay); // holds cooling for 0.1s
      digitalWrite(fanPin, HIGH) // turns of fan
    }
    delay(cycleDelay)
    elapsedTime = millis() - initialTime  // time from start
  }
  return null; 
}

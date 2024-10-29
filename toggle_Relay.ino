void toggleRelayWithBreak(int pin, int interval, int pin2 = -1) {  //pin2 should only be given a value when you want to toggle 2 pins at the same time
  static unsigned long previousMillis = 0;  // Track the last time the relay was toggled
  static bool relayState = HIGH;           // Keep track of the relay's state

  unsigned long currentMillis = millis();  //Gets the current time since the program started running

  if (currentMillis - previousMillis >= interval) {  //Checks to see if the time since last togggle is >= to the interval
    previousMillis = currentMillis; // Reset the timer
    relayState = !relayState;       // Toggle the relay state
    digitalWrite(pin, relayState ? LOW : HIGH); // Update relay state (active-low logic)
    if(pin2 != -1){
      digitalWrite(pin2, relayState ? LOW : HIGH); // Update relay state if there is a second relay (active-low logic)
    }
  }

}

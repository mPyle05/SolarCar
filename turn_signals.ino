void turnSignal(int signalPin, int switchPin) {
  while (digitalRead(switchPin) == HIGH) { // Stay in loop while the switch is active
    toggleRelayWithBreak(signalPin, tick);  // Toggle the relay with a 500ms cycle    

    highHeadState = digitalRead(highHeadSwitch);      //Check the headlight switchs to be able toggle headlights concurently with active hazards 
    lowHeadState = digitalRead(lowHeadSwitch);
    handleHeadlights();

    if (digitalRead(hazSwitch) == HIGH) {     // Allow loop exit by checking hazard switch state mid-operation
      digitalWrite(signalPin, HIGH);        //Turns off light that was being manipulated 
      return;                              // Exit if hazard switch is turned on
    }
  }

  // Ensure the signal is off when exiting
  digitalWrite(signalPin, HIGH);
}
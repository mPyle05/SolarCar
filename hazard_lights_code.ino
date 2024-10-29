void hazardsOn() {
  while (digitalRead(hazSwitch) == HIGH) { // Checks each loop to see if the hazard switch is still on

    toggleRelayWithBreak(relay[4], tick, relay[5]); // Toggles Back Left and Right signal with a 500ms delay
    
    highHeadState = digitalRead(highHeadSwitch);      //Check the headlight switchs to be able toggle headlights concurently with active hazards 
    lowHeadState = digitalRead(lowHeadSwitch);
    handleHeadlights();
    }

  // Turn off both signals when exiting
  digitalWrite(relay[4], HIGH);
  digitalWrite(relay[5], HIGH);
}
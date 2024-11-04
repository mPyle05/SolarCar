void hazardsOn() {
  while (digitalRead(hazSwitch) == HIGH) { // Checks each loop to see if the hazard switch is still on

    toggleRelayWithBreak(relay[2], tick, relay[3]); // Toggles Back Left and Right signal with a 500ms delay
    
    highHeadState = digitalRead(highHeadSwitch);      //Check the headlight switchs to be able toggle headlights concurently with active hazards 
    lowHeadState = digitalRead(lowHeadSwitch);
    handleHeadlights();
    }

  // Turn off both signals when exiting
  digitalWrite(relay[2], HIGH);
  digitalWrite(relay[3], HIGH);
}
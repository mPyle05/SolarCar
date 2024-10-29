void handleHeadlights() {
  digitalWrite(relay[2], highHeadState == HIGH ? LOW : HIGH); // Turns on Left bright headlight if switch is on and vice versa
  digitalWrite(relay[3], highHeadState == HIGH ? LOW : HIGH); // Turns off Right bright headlight if switch is off and vice versa

  digitalWrite(relay[0], lowHeadState == HIGH ? LOW : HIGH); // Turns on Left dim headlight if switch is on and vice versa
  digitalWrite(relay[1], lowHeadState == HIGH ? LOW : HIGH); // Turns off Right dim headlight if switch is off and vice versa
}
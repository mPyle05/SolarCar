void handleHeadlights() {
  digitalWrite(relay[1], highHeadState == HIGH ? LOW : HIGH); // Turns on dim headlight if switch is on and vice versa

  digitalWrite(relay[0], lowHeadState == HIGH ? LOW : HIGH); // Turns on bright headlight if switch is on and vice versa
}
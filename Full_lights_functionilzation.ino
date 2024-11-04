/*
Relay List:
0 = Bright head light
1 = Dim head light
2 = Back left turn signal
3 = Back right turn signal
*/ 
int relay[]{10, 12, 3, 4};

int LSwitch {7}; // set up all the switch pins
int RSwitch {8};
int hazSwitch {5};
int lowHeadSwitch{2};
int highHeadSwitch{6};

int tick{500};  // flicker rate of turn signals and hazards

int LState; // set up all of these as global variables
int RState;
int hazState;
int lowHeadState;
int highHeadState;

void toggleRelayWithBreak(int,int,int); //Declares the toggleRelay function so that it may be used in all functions

void setup() {
  pinMode(LSwitch, INPUT);  // Sets up all switch pins is inputs (acording to documentation not necessary, just a precaution)
  pinMode(RSwitch, INPUT);
  pinMode(hazSwitch, INPUT);
  pinMode(highHeadSwitch, INPUT);
  pinMode(lowHeadSwitch, INPUT);
  
  for(int i = 0; i <= 5; i++){  
    pinMode(relay[i], OUTPUT);    // Sets up all relay pins are outputs
    digitalWrite(relay[i], HIGH); // turns all relays off just a precaution, shouldn't really be necessary
  } 
}


void loop() {

  lowHeadState = digitalRead(lowHeadSwitch);  //Reads all of the switches 
  highHeadState = digitalRead(highHeadSwitch);
  LState = digitalRead(LSwitch);
  RState = digitalRead(RSwitch);
  hazState = digitalRead(hazSwitch);

  handleHeadlights(); //Handles the headlight based off of the headState variables
  
  // Check for hazard lights switch
  if (digitalRead(hazSwitch) == HIGH) {
    hazardsOn();
  }

  if (digitalRead(LSwitch) == HIGH) {
    turnSignal(relay[2], LSwitch); // Left turn signal
  }
  
  if (digitalRead(RSwitch) == HIGH) {
    turnSignal(relay[3], RSwitch); // Right turn signal
  }
}
// Hardware setup:
// Attach a rotary encoder with output pins to A2 and A3.
// The common contact should be attached to ground.


// Used RotaryEncoder library by Matthias Hartel for rotary encoder (volume )

#include <RotaryEncoder.h>

// definitions signifies digital pin numbers
#define MUTE 2
#define NEXT_SONG 3
#define PREV_SONG 6
#define PLAYPAUSE 5
#define SPOTIFY 11

// Setup a RoraryEncoder for pins A2 and A3:
RotaryEncoder encoder(A2, A3);

int muteState=1;
int nextState=1;
int prevState=1;
int playpauseState=1;
int spotifyState=1;

void setup()
{
  Serial.begin(9600);

  //Buttons connected between digital pin and ground
  pinMode(MUTE,INPUT_PULLUP);
  pinMode(NEXT_SONG,INPUT_PULLUP);
  pinMode(PREV_SONG,INPUT_PULLUP);
  pinMode(PLAYPAUSE,INPUT_PULLUP);
  pinMode(SPOTIFY,INPUT_PULLUP);
} 

void loop()
{
  static int pos = 0;
  encoder.tick();
  if(checkButton(MUTE,muteState)){
    muteState = !muteState;
    if(muteState==1)
      Serial.println("mute");
  }else if(checkButton(NEXT_SONG,nextState)){
    nextState = !nextState;
    if(nextState==1)
      Serial.println("nextSong");
  }else if(checkButton(PREV_SONG,prevState)){
    prevState = !prevState;
    if(prevState==1)
      Serial.println("prevSong");
  }else if(checkButton(PLAYPAUSE,playpauseState)){
    playpauseState = !playpauseState;
    if(playpauseState==1)
      Serial.println("playpause");
  }else if(checkButton(SPOTIFY,spotifyState)){
    spotifyState = !spotifyState;
    if(spotifyState==1)
      Serial.println("spotify");
  }

  //print to serial when position changed
  int newPos = encoder.getPosition();
  if(pos != newPos){
    Serial.print(newPos);
    Serial.println();
    pos = newPos;
  }
}

//check if button is pressed, 
boolean checkButton(int pin,int state){
  if(state!=digitalRead(pin)){
    delay(10);
    if(state!=digitalRead(pin)){
      state=digitalRead(pin);
      return true;
    }
  }
  return false;
}

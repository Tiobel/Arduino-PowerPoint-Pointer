#include <IRremote.h>
#include "Keyboard.h"

int RECV_PIN = 2;

IRrecv irrecv(RECV_PIN);

decode_results results;
int key_pressed;
int last_key_pressed;

void setup()
{

  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  Keyboard.begin();

}

void loop() {

  if (irrecv.decode(&results)) {
    key_pressed = results.value;
    Serial.println(key_pressed);
    irrecv.resume(); // Receive the next value
  }

  if (key_pressed == last_key_pressed) key_pressed = 0;

  if (key_pressed == 18105) { //Number from Code 1
    Keyboard.press(KEY_RIGHT_ARROW);
    Keyboard.releaseAll();

  }

  if (key_pressed == -22951) { //Number from Code 1
    Keyboard.press(KEY_LEFT_ARROW );
    Keyboard.releaseAll();

  }

  last_key_pressed = key_pressed;


}

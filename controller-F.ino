// Limits
const int knobs = 6;
const int channels = 6;

// Pins
const int channel_switch_pin = 13;
const int red_pin = 9;
const int green_pin = 10;
const int blue_pin = 11;

// Color indexes
const int red = 0;
const int green = 1;
const int blue = 2;

// channel indicator colors.
int colors[6][3] = {
 { 255,    32,    0 },
 {   0,   255,   32 },
 {  32,     0,  255 },
 { 255,   255,    0 },
 { 255,     0,  255 },
 {   0,   255,  255 },
};

// Vars
int values[knobs];
int value_times[knobs];
int threshold = 2;
int channel = 0;
int prev_switch_value = LOW;

void setup() {
  Serial.begin(9600);
  int now = micros();

  for (int i = 0; i < knobs; i++) {
    value_times[i] = now;
    values[i] = 0;
  }
  
  updateChannelColor();
}

void loop() {
  // Check each knob
  for (int i = 0; i < knobs; i++) {
    int value = analogRead(i);
    int midi_value = value / 8; // map analog values (0..1023) to midi values (0..127)
    
    // Avoid sending repeated messages: analog controls gives some oscillation and repeated values when read. 
    // Check the threshold is surpassed and the value to be sent is different from the one sent before   
    // Store the previous analog read value, but compare the midi value. 
    // That gives a smooth sequence of not repeated values with no definition loss 
    // (every value from 0 to 127 is sent while driving the potentiometer).
    if ( abs(value - values[i]) > threshold && midi_value != values[i] / 8 ) {
      values[i] = value;
      // send cc message using control value ranging 22..28
      sendControlMessage(channel, i + 22, midi_value);
    }
  }
  
  // Check if the channel switch is released
  int value = digitalRead(channel_switch_pin);
  if ( prev_switch_value == HIGH && value == LOW ) {
    channel = (channel % 6) + 1; //channel cicles in 1..6
    updateChannelColor();
  }

  prev_switch_value = value;
}

void updateChannelColor() {
  analogWrite(red_pin,   colors[channel][red]);
  analogWrite(green_pin, colors[channel][green]);
  analogWrite(blue_pin,  colors[channel][blue]);
}


void sendControlMessage(byte channel, byte control, byte value) {
  // 0xB0 is the first of 16 control change channels. Subtract one to go from MIDI's 1-16 channels to 0-15
  channel += 0xB0 - 1;
  
  // Ensure we're between channels 1 and 16 for a CC message
  if (channel >= 0xB0 && channel <= 0xBF) {
    Serial.write(channel);
    Serial.write(control);
    Serial.write(value);
  }
}

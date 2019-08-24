int red = 22;
int green = 23;
int blue = 24;
int t = 10; // Time for delay

void setup(){
    pinMode(red, OUTPUT);
    pinMode(green, OUTPUT);
    pinMode(blue, OUTPUT);
}
void Fade(){
  for( int i = 0; i <= 255; i++){
    analogWrite(red, i); // fade up 
    analogWrite(green, 255 - i); // fade down
    analogWrite(blue, 0); // do nothing
    delay(t);
  }
  for( int i = 0; i <= 255; i++){
    analogWrite(red, 255 - i); // fade down
    analogWrite(green, 0); // do nothing
    analogWrite(blue, i); // fade up 
    delay(t);
  }
    for( int i = 0; i <= 255; i++){
    analogWrite(red, 0); // do nothing
    analogWrite(green, i); // fade up
    analogWrite(blue, 255 - i); // fade down 
    delay(t);
  }
} 
void loop(){
Fade();
}

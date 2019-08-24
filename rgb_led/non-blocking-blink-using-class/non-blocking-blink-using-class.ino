class Flasher{
  int led_pin;
  int led_state;
  int on_time;
  int off_time;
  unsigned long prev_time;

  public:
  Flasher(int pin, int on, int off){
    led_pin = pin;
    pinMode(led_pin, OUTPUT);
    digitalWrite(led_pin, 1);

    on_time = on;
    off_time = off;
    led_state = 1;
    prev_time = 0;
  }

  void update(){
    unsigned long current_time = millis();
    if ((led_state == 1) && (current_time-prev_time>off_time)){
      led_state = 0;
      prev_time = current_time;
      digitalWrite(led_pin, led_state);
    }
    else if ((led_state == 0) && (current_time-prev_time>on_time)){
      led_state = 1;
      prev_time = current_time;
      digitalWrite(led_pin, led_state);
    }
  }
};

Flasher red_led(22, 100, 500);
Flasher green_led(23, 150, 666);
Flasher blue_led(24, 150, 130);


void setup() {
  // put your setup code here, to run once:

}

void loop() {
  red_led.update();
  green_led.update();
  blue_led.update();
}

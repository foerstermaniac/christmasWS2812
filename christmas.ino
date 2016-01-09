#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN   12
#define NUMPIXELS   180

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int array[3][6];
int width = 2;
long green = 0x009900;
long red = 0xff0000;

void setup() {
  pixels.begin();
  for(int i=0;i<NUMPIXELS;i++)
    pixels.setPixelColor(i, green);
  pixels.show();
}

void loop() {
  push();
  fadeout();
  fadein();
  delay(random(800,2000));
}

void fadein(){
  long c = green; //0x009900 to 0xff0000
  while(c < 0x999900){
    c = c+0x110000;
    //hier ausgeben
    for(int i=0; i<6; i++){
    pixels.setPixelColor(array[0][i]*width, c);
    pixels.setPixelColor(array[0][i]*width+1, c);
    pixels.show();
    }
  }
  while(c > 0x990000){
    c = c-0x001100;
    //hier ausgeben
    for(int i=0; i<6; i++){
    pixels.setPixelColor(array[0][i]*width, c);
    pixels.setPixelColor(array[0][i]*width+1, c);
    pixels.show();
    }
  }
  while(c < 0xff0000){
    c = c+0x110000;
    //hier ausgeben
    for(int i=0; i<6; i++){
    pixels.setPixelColor(array[0][i]*width, c);
    pixels.setPixelColor(array[0][i]*width+1, c);
    pixels.show();
    }
  }
}

void fadeout(){
  long c = red; //0xff0000 to 0x009900
  while(c > 0x990000){
    c = c-0x110000;
    //hier ausgeben
    for(int i=0; i<6; i++){
    pixels.setPixelColor(array[2][i]*width, c);
    pixels.setPixelColor(array[2][i]*width+1, c);
    pixels.show();
    }
  }
  while(c < 0x999900){
    c = c+0x001100;
    //hier ausgeben
    for(int i=0; i<6; i++){
    pixels.setPixelColor(array[2][i]*width, c);
    pixels.setPixelColor(array[2][i]*width+1, c);
    pixels.show();
    }
  }
  while(c > 0x009900){
    c = c-0x110000;
    //hier ausgeben
    for(int i=0; i<6; i++){
    pixels.setPixelColor(array[2][i]*width, c);
    pixels.setPixelColor(array[2][i]*width+1, c);
    pixels.show();
    }
  }
}

void push(){
  for(int i=0; i<6; i++){
    array[2][i] = array [1][i];
    array[1][i] = array [0][i];
    array[0][i] = random((NUMPIXELS-1)/width);
  }
}

void turnon(){
  for(int i=0; i<6; i++){
    pixels.setPixelColor(array[0][i]*width, red);
    pixels.setPixelColor(array[0][i]*width+1, red);
  }
  pixels.show();
}
void turnoff(){
  for(int i=0; i<6; i++){
    pixels.setPixelColor(array[2][i]*width, green);
    pixels.setPixelColor(array[2][i]*width+1, green);
  }
  pixels.show();
}

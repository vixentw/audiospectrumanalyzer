        #include <Wire.h>
#include <PCA9635.h>
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            6

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      210

int strobe = 2; // strobe pins on digital 2
int res = 3; // reset pins on digital 3
int bands[7]; // store band values in these arrays
//////////////////////////////////////////////////////////////////////////////////////
const int average = 5;

int band_1_avg[average];
int xxx = 0;

int band_2_avg[average];
int yyy = 0;

int band_3_avg[average];
int zzz = 0;

int band_4_avg[average];
int ddd = 0;

int band_5_avg[average];
int ccc = 0;

int band_6_avg[average];
int ttt = 0;

int band_7_avg[average];
int qqq = 0;



int band;


/////////////////////////////////////////////////////////////////////////////////////////
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
void setup()
{
  Wire.begin();
  pixels.begin(); // This initializes the NeoPixel library.
  Serial.begin(115200);
  pinMode(res, OUTPUT); // reset
  pinMode(strobe, OUTPUT); // strobe
  digitalWrite(res, LOW); // reset low
  digitalWrite(strobe, HIGH); //pin 5 is RESET on the shield
}

void clearLEDs()
{
  for (int i = 0; i < NUMPIXELS; i++)
  {
    pixels.setPixelColor(i, 0);
  }
}

void readMSGEQ7()
// Function to read 7 band equalizers
{
  digitalWrite(res, HIGH);
  digitalWrite(res, LOW);
  for (band = 0; band < 7; band++)
  {
    digitalWrite(strobe, LOW); // strobe pin on the shield - kicks the IC up to the next band
    delayMicroseconds(30); //
    bands[band] = analogRead(0); // store band reading
    digitalWrite(strobe, HIGH);
  }
}

void loop()
{
  readMSGEQ7();
 
  float x;

  band_1_avg[xxx] = bands[0];
  xxx++;
  if (xxx >=average)
    xxx = 0;

  x = 0;
  for (int i = 0; i <average; i++)
  {

    x += band_1_avg[i];

  }
  x /=average;
    clearLEDs();

    
  float numLights0 = ((1.0 * x) / 1024.0) * (15 + 1);
  float brightness0 = 255 * (1.0) * numLights0 * numLights0 / (3600.0);
    if (brightness0 > 254)
      brightness0 = 254;

       float y;

  band_2_avg[yyy] = bands[1];
  yyy++;
  if (yyy >=average)
    yyy = 0;

  y = 0;
  for (int i = 0; i <average; i++)
  {

    y += band_2_avg[i];

  }
  y /=average;

  
  float numLights1 = ((1.0 * y) / 1024.0) * (15 + 1);
  float brightness1 = 255 * (1.0) * numLights1 * numLights1 / (3600.0);
    if (brightness1 > 254)
      brightness1 = 254;

        float z;

  band_3_avg[zzz] = bands[2];
  zzz++;
  if (zzz >=average)
    zzz = 0;

  z = 0;
  for (int i = 0; i <average; i++)
  {

    z += band_3_avg[i];

  }
  z /=average;


  float numLights2 = ((1.0 * z) / 1024.0) * (15 + 1);
  float brightness2 = 255 * (1.0) * numLights2 * numLights2 / (3600.0);
    if (brightness2 > 254)
      brightness2 = 254;

      float d;

  band_4_avg[ddd] = bands[3];
  ddd++;
  if (ddd >=average)
    ddd = 0;

  d = 0;
  for (int i = 0; i <average; i++)
  {

    d += band_4_avg[i];

  }
  d /=average;
  
  
  
  
  float numLights3 = ((1.0 * d) / 1024.0) * (15 + 1);
  float brightness3 = 255 * (1.0) * numLights3 * numLights3 / (3600.0);
    if (brightness3 > 254)
      brightness3 = 254;

        float c;

  band_5_avg[ccc] = bands[4];
  ccc++;
  if (ccc >=average)
    ccc = 0;

  c = 0;
  for (int i = 0; i <average; i++)
  {

    c += band_5_avg[i];

  }
  c /=average;

  
  float numLights4 = ((1.0 * c) / 1024.0) * (15 + 1);
  float brightness4 = 255 * (1.0) * numLights4 * numLights4 / (3600.0);
    if (brightness4 > 254)
      brightness4 = 254;

       float t;

  band_6_avg[ttt] = bands[5];
  ttt++;
  if (ttt >=average)
    ttt = 0;

  t = 0;
  for (int i = 0; i <average; i++)
  {

    t += band_6_avg[i];

  }
  t /=average;


  float numLights5 = ((1.0 * t) / 1024.0) * (15 + 1);
  float brightness5 = 255 * (1.0) * numLights5 * numLights5 / (3600.0);
    if (brightness5 > 254)
      brightness5 = 254;
 
  float q;

  band_7_avg[qqq] = bands[6];
  qqq++;
  if (qqq >=average)
    qqq = 0;

  q = 0;
  for (int i = 0; i <average; i++)
  {

    q += band_7_avg[i];

  }
  q /=average;

  
  float numLights6 = ((1.0 * q) / 1024.0) * (15 + 1);
  float brightness6 = 255 * (1.0) * numLights6 * numLights6 / (3600.0);
    if (brightness6 > 254)
      brightness6 = 254;
  

  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 

      
  pixels.setPixelColor(15, pixels.Color(25, 25, 25));
  for (int i = 16; i < (14+ numLights0); i++)
  {
    pixels.setPixelColor(i, pixels.Color(44, 0, 0));
  }
  
 for (int i = 14; i > (16-numLights6); i--)
  {
    pixels.setPixelColor(i, pixels.Color(44, 0, 0));
  }
  
/////////////////////////////////////////////////////////////////////////////////////////////

      
  pixels.setPixelColor(45, pixels.Color(25, 25, 25));
  for (int i = 46; i < (44+ numLights1); i++)
  {
    pixels.setPixelColor(i, pixels.Color(44, 22, 0));
  }
  
 for (int i = 44; i > (46-numLights5); i--)
  {
    pixels.setPixelColor(i, pixels.Color(44, 22, 0));
  }
  
  
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

      
  pixels.setPixelColor(75, pixels.Color(25, 25, 25));
  for (int i = 76; i < (74+ numLights2); i++)
  {
    pixels.setPixelColor(i, pixels.Color(0, 44, 0));
  }
  
 for (int i = 74; i > (76-numLights4); i--)
  {
    pixels.setPixelColor(i, pixels.Color(0, 44, 0));
  }
  
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
  
  
      
  pixels.setPixelColor(105, pixels.Color(25, 25, 25));
  for (int i = 106; i < (104+ numLights3); i++)
  {
    pixels.setPixelColor(i, pixels.Color(0, 44, 22));
  }
  
 for (int i = 104; i > (106-numLights3); i--)
  {
    pixels.setPixelColor(i, pixels.Color(0, 44, 22));
  }
  
/////////////////////////////////////////////////////////////////////////////////////////////
  

      
  pixels.setPixelColor(135, pixels.Color(25, 25, 25));
  for (int i = 136; i < (134+ numLights4); i++)
  {
    pixels.setPixelColor(i, pixels.Color(0, 0, 44));
  }
  
 for (int i = 134; i > (136-numLights2); i--)
  {
    pixels.setPixelColor(i, pixels.Color(0, 0, 44));
  }
  
  
/////////////////////////////////////////////////////////////////////////////////////////////

  
  pixels.setPixelColor(165, pixels.Color(25, 25, 25));
  for (int i = 166; i < (164+ numLights5); i++)
  {
    pixels.setPixelColor(i, pixels.Color(44, 44, 10));
  }
  
 for (int i = 164; i > (166-numLights1); i--)
  {
    pixels.setPixelColor(i, pixels.Color(44, 44, 10));
  }
  
  
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
      
  pixels.setPixelColor(195, pixels.Color(25, 25, 25));
  for (int i = 196; i < (194+ numLights6); i++)
  {
    pixels.setPixelColor(i, pixels.Color(44, 10, 10));
  }
  
 for (int i = 194; i > (196-numLights0); i--)
  {
    pixels.setPixelColor(i, pixels.Color(44, 10, 10));
  }

    
  pixels.show();
}

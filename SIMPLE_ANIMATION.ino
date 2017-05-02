
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
const int average = 1;

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
////////////////////////////////////////////////////////////////////////////////////////

        


     
int  numLights0 = 0,
     currentRead0 = 0,
     storedRead0 = 0,
     numLights1 = 0,
     currentRead1 = 0,
     storedRead1 = 0,
     numLights2 = 0,
     currentRead2 = 0,
     storedRead2 = 0,
     numLights3 = 0,
     currentRead3 = 0,
     storedRead3 = 0,
     numLights4 = 0,
     currentRead4 = 0,
     storedRead4 = 0,
     numLights5 = 0,
     currentRead5 = 0,
     storedRead5 = 0,
     numLights6 = 0,
     currentRead6 = 0,
     storedRead6 = 0;

int topLight0,
    topLight1,
    topLight2,
    topLight3,
    topLight4,
    topLight5,
    topLight6 = 0;
long checkTime0,
     checkTime1,
     checkTime2,
     checkTime3,
     checkTime4,
     checkTime5,
     checkTime6;
unsigned long topLightTimer0,
              topLightTimer1,
              topLightTimer2,
              topLightTimer3,
              topLightTimer4,
              topLightTimer5,
              topLightTimer6;

     int testLoop = 0;

/////////////////////////////////////////////////////////////////////////////////////////
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
void setup()
{
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
  
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
  
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

  float numLights0 = ((1.0 * x) / 1024.0) * (30);
  
      
  float brightness0 = ((numLights1)/30) * 255;
  if (brightness0 > 254)
      brightness0 = 254;
 
  pixels.setPixelColor(0, pixels.Color(5, 5, 5));
  
  for (int i = 1; i < numLights0; i++)
  {
      pixels.setPixelColor(i, pixels.Color(44, 0, 0));
  }

//=========================================================================== Band 2 =========================================================
  
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

  
  float numLights1 = ((1.0 * y) / 1024.0) * (30);
  
      
 
  numLights1 +=30;
  
 float brightness1 = ((numLights1-30)/30) * 255;
    if (brightness1 > 254)
      brightness1 = 254;
  pixels.setPixelColor(30, pixels.Color(5, 5, 5));
  
  for (int i = 31; i < numLights1; i++)
  {
      pixels.setPixelColor(i, pixels.Color(44, 22, 0));
  }

//======================================================================= Band 3 ====================================================
  
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

  float numLights2 = ((1.0 * z) / 1024.0) * (30);
  
  numLights2 += 60;

 
  float brightness2 = ((numLights1-60)/30) * 255;
    if (brightness2 > 254)
      brightness2 = 254;
  pixels.setPixelColor(60, pixels.Color(5, 5, 5));
  
  for (int i = 61; i < numLights2; i++)
  {
      pixels.setPixelColor(i, pixels.Color(0, 44, 0));
  }

  //=============================================================================== Band 4 ==========================================
 
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
  
  float numLights3 = ((1.0 * d) / 1024.0) * (30);
  numLights3 += 90;

 
  
  float brightness3 = ((numLights1-90)/30) * 255;
    if (brightness3 > 254)
      brightness3 = 254;
      
  
  pixels.setPixelColor(90, pixels.Color(5, 5, 5));
  
  for (int i = 91; i < numLights3; i++)
  {
      pixels.setPixelColor(i, pixels.Color(0, 44, 22));
  }

  

//=========================================================================================== Band 5 =============================  
  
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

  float numLights4 = ((1.0 * c) / 1024.0) * (30);
  numLights4 += 120;

  
  float brightness4 = ((numLights1-120)/30) * 255;
    if (brightness4 > 254)
      brightness4 = 254;
    
 
  pixels.setPixelColor(120, pixels.Color(5, 5, 5));
  
  for (int i = 121; i < numLights4; i++)
  {
      pixels.setPixelColor(i, pixels.Color(0, 0, 44));
  }

  
  //====================================================== Band 6 ==================================================================

  
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
  
  float numLights5 = ((1.0 * t) / 1024.0) * (30);
  numLights5 += 150;

  
  float brightness5 = ((numLights1-150)/30) * 255;
    if (brightness5 > 254)
      brightness5 = 254;
      
  
  pixels.setPixelColor(150, pixels.Color(5, 5, 5));
  
  for (int i = 151; i < numLights5; i++)
  {
      pixels.setPixelColor(i, pixels.Color(44, 44, 10));
  }


//============================================================ Band 7 ========================================================

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

  float numLights6 = ((1.0 * q) / 1024.0) * (30);
  numLights6 += 180;

 
  
  float brightness6 = ((numLights1-180)/30) * 255;
    if (brightness6 > 254)
      brightness6 = 254;
      
  pixels.setPixelColor(180, pixels.Color(5, 5, 5));
  
  for (int i = 181; i < numLights6; i++)
  {
      pixels.setPixelColor(i, pixels.Color(44, 10, 10));
  }
  pixels.show();
  
}

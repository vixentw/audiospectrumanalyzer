
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
const int average = 3;

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

int red, green, blue = 0;





     
int  lights0 = 0,
     currentRead0 = 0,
     storedRead0 = 0,
     lights1 = 0,
     currentRead1 = 0,
     storedRead1 = 0,
     lights2 = 0,
     currentRead2 = 0,
     storedRead2 = 0,
     lights3 = 0,
     currentRead3 = 0,
     storedRead3 = 0,
     lights4 = 0,
     currentRead4 = 0,
     storedRead4 = 0,
     lights5 = 0,
     currentRead5 = 0,
     storedRead5 = 0,
     lights6 = 0,
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
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  

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
  unsigned long timer = millis();
  unsigned long delta = 50;   //-----------------------------------------------------------------------------Rate in which the LEDs fall    


  
  
  
  readMSGEQ7();

  red = analogRead(1);
  green = analogRead(2);
  blue = analogRead(3);
  Serial.print("Red: ");
  Serial.println(red);
  Serial.print("Green: ");
  Serial.println(green);
  Serial.print("Blue: ");
  Serial.println(blue);
  float r = ((red*1.0)/1024)*255;
  float g = ((green*1.0)/1024)*255;
  float b = ((blue*1.0)/1024)*255;
  if( r < 5)
  {
    r = 0;
  }
  if( g < 5)
  {
    g = 0;
  }
  if( b < 5)
  {
    b = 0;
  }
  if( r > 255)
  {
    r = 255;
  }
  if( g > 255)
  {
    g = 255;
  }
  if( b > 255)
  {
    b = 255;
  }
  Serial.print("R: ");
  Serial.println(r);
  Serial.print("G: ");
  Serial.println(g);
  Serial.print("B: ");
  Serial.println(b);
  
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
  
      
      currentRead0 = numLights0;
 


  if(currentRead0 > storedRead0)
  {
    storedRead0 = currentRead0;
    lights0 = storedRead0; 
    checkTime0 = millis()+delta*3;
  } 
  else if((currentRead0 < storedRead0) && (timer > checkTime0 && (lights0 > 0)))
  {
    
    storedRead0-- ;
    lights0 = storedRead0;
    checkTime0+=delta/4;
  }
  else
  {
    //nothing
  }
 

  //---------------------------------------------------------------------------------------Top Light that rides the LEDs has a longer fall rate
  if (currentRead0>topLight0)
  {
    topLight0 = lights0+1;
  }
  else if ((currentRead0 <= topLight0) && (timer > topLightTimer0) && topLight0 > lights0 && topLight0 > 1)
  {
    topLight0--;
    topLightTimer0 += delta*4;
  }
  else
  {
    // nothing goes here
  }

  float brightness0 = 255 * (1.0) * topLight0 * topLight0 / (3600.0);
  if (brightness0 > 254)
      brightness0 = 254;
 
  pixels.setPixelColor(0, pixels.Color(25, 25, 25));
  
  for (int i = 1; i < lights0; i++)
  {
      pixels.setPixelColor(i, pixels.Color(r, g, b));
  }
  pixels.setPixelColor(topLight0, pixels.Color(25, 25, 25));
  


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

  
  float numLights1 = ((1.0 * y) / 1024.0) * (31);
  
      
 
  numLights1 +=29;
  currentRead1 = numLights1;
 


  if(currentRead1 > storedRead1)
  {
    storedRead1 = currentRead1;
    lights1 = storedRead1; 
    checkTime1 = millis()+delta*3;
  } 
  else if((currentRead1 < storedRead1) && (timer > checkTime1) && (lights1 > 30))
  {
    
    storedRead1-- ;
    lights1 = storedRead1;
    checkTime1+=delta/4;
  }
  else
  {
    //nothing
  }

  //---------------------------------------------------------------------------------------Top Light that rides the LEDs has a longer fall rate
  if (currentRead1>topLight1)
  {
    topLight1 = lights1+1;
  }
  else if ((currentRead1 <= topLight1) && (timer > topLightTimer1) && (topLight1 > lights1) && (topLight1 > 31))
  {
    topLight1--;
    topLightTimer1 += delta*4;
  }
  else
  {
    // nothing goes here
  }
 float brightness1 = 255 * (1.0) * numLights1 * numLights1 / (3600.0);
    if (brightness1 > 254)
      brightness1 = 254;
      
  pixels.setPixelColor(30, pixels.Color(25, 25, 25));
  
  for (int i = 31; i < lights1; i++)
  {
      pixels.setPixelColor(i, pixels.Color(r, g, b));
  }
  pixels.setPixelColor(topLight1, pixels.Color(25, 25, 25));
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

  currentRead2 = numLights2;
 


  if(currentRead2 > storedRead2)
  {
    storedRead2 = currentRead2;
    lights2 = storedRead2; 
    checkTime2 = millis()+delta*3;
  } 
  else if((currentRead2 < storedRead2) && (timer > checkTime2) && (currentRead2 > 60))
  {
    
    storedRead2-- ;
    lights2 = storedRead2;
    checkTime2+=delta/4;
  }
  else
  {
    //nothing
  }

  //---------------------------------------------------------------------------------------Top Light that rides the LEDs has a longer fall rate
  if (currentRead2>topLight2)
  {
    topLight2 = lights2+1;
  }
  else if ((currentRead2 <= topLight2) && (timer > topLightTimer2) && (topLight2 > lights2) && (topLight2 > 61))
  {
    topLight2--;
    topLightTimer2 += delta*4;
  }
  else
  {
    // nothing goes here
  }
  
  float brightness2 = 255 * (1.0) * numLights2 * numLights2 / (3600.0);
    if (brightness2 > 254)
      brightness2 = 254;
  pixels.setPixelColor(60, pixels.Color(25, 25, 25));
  
  for (int i = 61; i < lights2; i++)
  {
      pixels.setPixelColor(i, pixels.Color(r, g, b));
  }
  pixels.setPixelColor(topLight2, pixels.Color(25, 25, 25));
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
  
  float numLights3 = ((1.0 * d) / 1024.0) * (31);
  numLights3 += 89;

  currentRead3 = numLights3;
 


  if(currentRead3 > storedRead3)
  {
    storedRead3 = currentRead3;
    lights3 = storedRead3; 
    checkTime3 = millis()+delta*3;
  } 
  else if((currentRead3 < storedRead3) && (timer > checkTime3) && (currentRead3 > 90))
  {
    
    storedRead3-- ;
    lights3 = storedRead3;
    checkTime3+=delta/4;
  }
  else
  {
    //nothing
  }

  //---------------------------------------------------------------------------------------Top Light that rides the LEDs has a longer fall rate
  if (currentRead3>topLight3)
  {
    topLight3 = lights3+1;
  }
  else if ((currentRead3 <= topLight3) && (timer > topLightTimer3) && (topLight3 > lights3) && (topLight3 > 91))
  {
    topLight3--;
    topLightTimer3 += delta*4;
  }
  else
  {
    // nothing goes here
  }
  
  float brightness3 = 255 * (1.0) * numLights3 * numLights3 / (3600.0);
    if (brightness3 > 254)
      brightness3 = 254;
      
  
  pixels.setPixelColor(90, pixels.Color(25, 25, 25));
  
  for (int i = 91; i < lights3; i++)
  {
      pixels.setPixelColor(i, pixels.Color(r, g, b));
  }
  pixels.setPixelColor(topLight3, pixels.Color(25, 25, 25));
  

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

  float numLights4 = ((1.0 * c) / 1024.0) * (32);
  numLights4 += 118;

  currentRead4 = numLights4;
 


  if(currentRead4 > storedRead4)
  {
    storedRead4 = currentRead4;
    lights4 = storedRead4; 
    checkTime4 = millis()+delta*3;
  } 
  else if((currentRead4 < storedRead4) && (timer > checkTime4) && (currentRead4 > 118))
  {
    
    storedRead4-- ;
    lights4 = storedRead4;
    checkTime4+=delta/4;
  }
  else
  {
    //nothing
  }

  //---------------------------------------------------------------------------------------Top Light that rides the LEDs has a longer fall rate
  if (currentRead4>topLight4)
  {
    topLight4 = lights4+1;
  }
  else if ((currentRead4 <= topLight4) && (timer > topLightTimer4) && (topLight4 > lights4) && (topLight4 > 121))
  {
    topLight4--;
    topLightTimer4 += delta*4;
  }
  else
  {
    // nothing goes here
  }

  float brightness4 = 255 * (1.0) * numLights4 * numLights4 / (3600.0);
    if (brightness4 > 254)
      brightness4 = 254;
    
 
  pixels.setPixelColor(120, pixels.Color(25, 25, 25));
  
  for (int i = 121; i < lights4; i++)
  {
      pixels.setPixelColor(i, pixels.Color(r, g, b));
  }
  pixels.setPixelColor(topLight4, pixels.Color(25, 25, 25));
  
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
  
  float numLights5 = ((1.0 * t) / 1024.0) * (32);
  numLights5 += 148;

  currentRead5 = numLights5;
 


  if(currentRead5 > storedRead5)
  {
    storedRead5 = currentRead5;
    lights5 = storedRead5; 
    checkTime5 = millis()+delta*3;
  } 
  else if((currentRead5 < storedRead5) && (timer > checkTime5) && (currentRead5 > 148))
  {
    
    storedRead5-- ;
    lights5 = storedRead5;
    checkTime5+=delta/4;
  }
  else
  {
    //nothing
  }

  //---------------------------------------------------------------------------------------Top Light that rides the LEDs has a longer fall rate
  if (currentRead5>topLight5)
  {
    topLight5 = lights5+1;
  }
  else if ((currentRead5 <= topLight5) && (timer > topLightTimer5) && (topLight5 > lights5) && (topLight5 > 151))
  {
    topLight5--;
    topLightTimer5 += delta*5;
  }
  else
  {
    // nothing goes here
  }

  
  float brightness5 = 255 * (1.0) * numLights5 * numLights5 / (3600.0);
    if (brightness5 > 254)
      brightness5 = 254;
      
  
  pixels.setPixelColor(150, pixels.Color(25, 25, 25));
  
  for (int i = 151; i < lights5; i++)
  {
      pixels.setPixelColor(i, pixels.Color(r, g, b));
  }
  pixels.setPixelColor(topLight5, pixels.Color(25, 25, 25));

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

  float numLights6 = ((1.0 * q) / 1024.0) * (33);
  numLights6 += 177;

  currentRead6 = numLights6;
 


  if(currentRead6 > storedRead6)
  {
    storedRead6 = currentRead6;
    lights6 = storedRead6; 
    checkTime6 = millis()+delta*3;
  } 
  else if((currentRead6 < storedRead6) && (timer > checkTime6) && (currentRead6 > 177))
  {
    
    storedRead6-- ;
    lights6 = storedRead6;
    checkTime6+=delta/4;
  }
  else
  {
    //nothing
  }

  //---------------------------------------------------------------------------------------Top Light that rides the LEDs has a longer fall rate
  if (currentRead6>topLight6)
  {
    topLight6 = lights6+1;
  }
  else if ((currentRead6 <= topLight6) && (timer > topLightTimer6) && (topLight6 > lights6) && (topLight6 > 181))
  {
    topLight6--;
    topLightTimer6 += delta*5;
  }
  else
  {
    // nothing goes here
  }

  
  float brightness6 = 255 * (1.0) * numLights6 * numLights6 / (3600.0);
    if (brightness6 > 254)
      brightness6 = 254;
      
  pixels.setPixelColor(180, pixels.Color(25, 25, 25));
  
  for (int i = 181; i < lights6; i++)
  {
      pixels.setPixelColor(i, pixels.Color(r, g, b));
  }
  pixels.setPixelColor(topLight6, pixels.Color(25, 25, 25));

  pixels.show();
  
}

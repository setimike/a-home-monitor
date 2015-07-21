/* Monitor project sketch
 *
 * Project to read from various environmental sensors and save the
 *  data back to a server for remote access.
 *
 * 120603 - first draft, setting up environment variables.
 * 120705 - read from photocell and dht11, print to serial.
 * 130930 - first draft for csv output.
 *  - removed Celsius reading
 *  - take light reading only once per second same as temp/humidity.
 *  - only record motion once per second. Motion is tested for every quarter second.
 *  - removed code for leds
 * 131122 - Added code for TMP36 temperature sensor, commented out printing of DHT11 temp.
*/

#include "DHT.h"

/* global variables */
/* leds */

/* sensors */
int photocellPin = 5;	// the cell and 10K pulldown are connected to a5
int photocellReading;   // the analog reading from the sensor divider
int pirPin = 2;		// the PIR motion sensor data line is connected to d2
int pirState = LOW;
int val = 0;
int dhtPin = 3;		// the DHT11, digital temp and humidity sensor is
			//  connected to d3
#define DHTTYPE DHT11   // DHT 11
int t36Pin = 4;         // TMP36 temperature sensor connected to a4

int loopCount = 0;
int motionDetected = 0; // Flag for tracking motion
/* end of variables */

/* Create dht interface */
DHT dht(dhtPin, DHTTYPE);

void setup()
{
	/* Set outputs */

	/* Set digital inputs */
	pinMode(pirPin, INPUT);
	pinMode(dhtPin, INPUT);

	/* Start serial output */
	Serial.begin(9600);
        /* serial test header */
        Serial.println("Output started");
        dht.begin();
}

void loop()
{
    /* Check motion sensor each time through */
    val = digitalRead(pirPin);  /* read input value */
    if (val == HIGH) {
      if (pirState == LOW) {
        /* we just turned on */
        /* Motion detected! */
        motionDetected = 1;
        pirState = HIGH;
      }
    } else {
      if (pirState == HIGH) {
        /* Motion ended */
        motionDetected = 0;
        pirState = LOW;
      }
    }

    if (loopCount == 0) {
      	/* Get light data */
	photocellReading = analogRead(photocellPin);
	/* Send light data to serial */
        Serial.print(photocellReading);
        Serial.print(", ");
        
        /* Get temperature data from TMP36 */
        int t36reading = analogRead(t36Pin);
        float t36voltage = t36reading * 5.0;
        t36voltage /= 1024;
        float t36T = (t36voltage - 0.5) * 100;
        float t36fT = ((t36T * 1.8) + 32);
        
        /* Get humidity and temp data */
        float h = dht.readHumidity();
        float t = dht.readTemperature();
        float ft;
        ft = ((t * 1.8) + 32);      // Temperature in Fahrenheit
        // check if returns are valid, if they are NaN (not a number) then something went wrong!
        if (isnan(t) || isnan(h)) {
              Serial.println("Failed to read from DHT");
        } else {
          /* Output light, humidity, and temperature in csv format */
          Serial.print(h); 
          Serial.print(", ");
          Serial.print(t36fT); /* temperature value from TMP36 above */
          Serial.print(", "); 
          
          /* motion status is only output once per second with light/temp/humidity */
          Serial.print(motionDetected);
          Serial.print("\n");
        }
    }
   
    /* Increment loop */
    if (loopCount > 2) {
      loopCount = 0;
    } else {
      loopCount = loopCount+1;
    }
  delay(250);

}



#include <SPI.h>
#include <SdFat.h>

#define SD_CS 10

SdFat sd;
SdFile file;

void setup() {
  Serial.begin(115200);
  while (!Serial) {}

  if (!sd.begin(SD_CS, SD_SCK_MHZ(50)) {
     Serial.println("Init failed");
	    return;
  }

  Serial.println("Init success");
}

void loop() {
  if (!file.open("test.txt") {
    file.println("Hello world!");
	  file.close();
  }

  delay(500);
}

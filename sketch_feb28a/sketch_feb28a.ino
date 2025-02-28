#include <SPI.h>
#include <SdFat.h>

#define SD_CS 10  // Chip Select pin

SdFat sd;
SdFile logFile;

void setup() {
    Serial.begin(115200);
    while (!Serial) {}

    if (!sd.begin(SD_CS, SD_SCK_MHZ(50))) {
        Serial.println("SD initialization failed!");
        return;
    }
    
    Serial.println("SD card initialized.");

    // Open file (create if not exists, append if exists)
    if (!logFile.open("datalog.txt", O_WRONLY | O_CREAT | O_APPEND)) {
        Serial.println("File open failed!");
        return;
    }

    logFile.println("Logging started...");
    logFile.close();
}

void loop() {
    if (!logFile.open("datalog.txt", O_WRONLY | O_APPEND)) {
        Serial.println("File open failed!");
        return;
    }

    logFile.println("New data entry...");
    logFile.close();

    delay(1000);
}

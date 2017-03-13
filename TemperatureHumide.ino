/* Capteur Temperature et humidite*/
//#define FTP_DEBUG
//#define DEBUG_ESP
#define DEBUG_INIT
#include "PersonnalData.h"
#include <DHT.h>
#include <ServerManager.h> // personnalData
ServerManager serverManager;
#include <WifiManager.h> // personnalData

void pixelRequest(); // To assign one color on one LED and show animation
void handleRequestOnFile() {
	serverManager.handleRequestFile();
}

// what digital pin we're connected to
DHT dht(DHTPIN, DHT11);
long i = 0;
String sH = "";
String sT = "";

void setup(void) {
	Serial.begin(BAUDRATE);
	DEBUG_INIT_PRINTLN("\nindex;H_min;H_max;h;T_min;T_max;t;");
	dht.begin();

	initWIFI(nbSSID, SSIDs, passewords);
	serverManager.initDnsHttpFtpOtaTelnetServers(hostName, hostName, passeWord,
			hostName, passeWord);

	serverManager.httpServer.onNotFound(handleRequestOnFile);
	serverManager.httpServer.on("/pixel", HTTP_GET, pixelRequest);
}
void loop() {
	serverManager.updateServers();
	float h = dht.readHumidity();
	float t = dht.readTemperature();
	if (isnan(h) || isnan(t)) {
		Serial.println("Failed to read from DHT sensor!");
		return;
	}

	i++;
	sH = String(h);
	sH.replace(".", ",");
	sT = String(t);
	sT.replace(".", ",");
	String msg = String(i) + ";35;45;" + sH + ";18;20;" + sT + ";";
	Serial.println(msg);

	// Wait a few seconds between measurements.
	delay(30000);

}
void pixelRequest() {

}

/* Capteur Temperature et humidite*/
//#define FTP_DEBUG
//#define DEBUG_ESP
//#define DEBUG_INIT

#include "PersonnalData.h"
#include <Aspect.h>
#include <ServersWeb.h> // personnalData
#include <WifiManager.h> // personnalData
#include "PagesWeb.h"

void setup(void) {
  Serial.begin(BAUDRATE);

  pinMode( led, OUTPUT);
  digitalWrite( led, 0);
  strip.rgbBlink();

  initWIFI();
  hasDebugDelay(15);
  artnet.setArtDmxCallback(onDmxFrame);
  artnet.begin();
  initDnsHttpFtpServers();
  httpServer.on("/pixel", HTTP_GET, pixelRequest);
  hasDebugDelay(20);

  showIP(WiFi.localIP());
  digitalWrite( led, 1);
}
void loop() {
  updateServers();
  artnet.read();
  if (animate == true) {
    startShow(showType);
    animate = false;
  }
}

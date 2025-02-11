/**************************************************************

    "iSpindel"
    changes by S.Lang <universam@web.de>

 **************************************************************/

#ifndef _SENDER_H_
#define _SENDER_H_

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>
#include <PubSubClient.h>

class SenderClass
{
public:
  SenderClass();
  String sendTCP(String server, uint16_t port = 80);
  bool sendGenericPost(String server, String url, uint16_t port = 80);
  bool sendInfluxDB(String server, uint16_t port, String db, String name, String username, String password);
  bool sendPrometheus(String server, uint16_t port, String job, String instance);
  bool sendUbidots(String token, String name);
  bool sendMQTT(String server, uint16_t port, String username, String password, String name, String baseTopic);
  bool sendFHEM(String server, uint16_t port, String name);
  bool sendTCONTROL(String server, uint16_t port);
  void add(String id, float value);
  void add(String id, String value);
  void add(String id, int32_t value);
  void add(String id, uint32_t value);
  void stopclient();
  void mqttCallback(char *topic, byte *payload, unsigned int length);
  // ~SenderClass();

private:
  WiFiClient _client;
  PubSubClient _mqttClient;
  StaticJsonDocument<1024> _doc;
};

#endif

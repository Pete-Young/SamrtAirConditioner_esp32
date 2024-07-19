#include <Arduino.h>
#include "infrared.h"
#include "mqtt.h"
#include "dht11_owner.h"
// put function declarations here:

// #define Ir_Serial Serial1

extern PubSubClient client;
void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  Ir_Serial.begin(115200, SERIAL_8N1, 9, 10);

  initMQTTClient();
}

void loop()
{
  // 举个例子，上报温度、湿度和光照强度的值,值是固定的
  const char *properties[] = {"temperature", "humidity", "light_intensity"};
  int values[] = {25, 60, 1000}; // 这里的值是示例，你需要根据实际情况进行修改
  reportDeviceValues("esp32", properties, values, 3);
  delay(1000);
}
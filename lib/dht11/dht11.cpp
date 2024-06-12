#include "dht11_owner.h"
#include "infrared.h"
DHT dht(DHTPIN, DHTTYPE);

// void setup()
// {
//     Serial.begin(115200);
//     dht.begin();
// }

// void loop()
// {
// // 等待几秒钟之间的读数。
//   delay(2000);

  // 读取温度或湿度采取大约250毫秒！
  // 传感器读数也可以达到2秒（这是传感器刷新速度的极限）。

// 读取湿度
float gettemp()
{
  float t = dht.readTemperature();
  return t;
}

float gethum()
{
  float h = dht.readHumidity();
  return h;
}

float hum = dht.readHumidity();

// 读取温度，摄氏度（默认）
float tem = dht.readTemperature();


// 检查是否任何读数失败，并退出早期（尽快重新开始）。

// if(isnan(h) || isnan(t) || isnan(f)) 
// {
//   Serial.println(F("Failed to read from DHT sensor!"));
//   return;
// }


//   Serial.print(F("Humidity: "));
//   Serial.print(h);
//   Serial.print(F("%  Temperature: "));
//   Serial.print(t);
//   Serial.print(F("°C "));
//   Serial.print(f);
//   Serial.println(F("°F"));
// }

/*
*  自动制冷制热
*/
void react_on()
{
  if(tem > react_tem)
  {
    AC_cool();
    Serial.println("制冷");
  }
  else
  {
    // AC_heat();
    Serial.println("制热");
  }
}


#include <DHT.h>

#define DHTPIN 4       // Chân DATA của DHT11 nối GPIO4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();

  Serial.println("Khoi dong DHT11...");
}

void loop() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature(); // °C

  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Doc DHT11 that bai!");
    delay(1000);
    return;
  }

  Serial.print("Nhiet do: ");
  Serial.print(temperature);
  Serial.print(" °C\t");

  Serial.print("Do am: ");
  Serial.print(humidity);
  Serial.println(" %");

  delay(1000); // DHT11 đọc tối đa khoảng 1 lần/giây
}
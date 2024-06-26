#include <DeneyapKartQRCodeReader.h>   // https://github.com/alvarowolfx/ESP32QRCodeReader Source codes were taken from here and adapted to Deneyap Kart.

DKQRCodeReader reader(DK_Kamera);

void onQrCodeTask(void *pvParameters){
  struct QRCodeData qrCodeData;

  while (true){
    if (reader.receiveQrCode(&qrCodeData, 100)){
      Serial.println("Found QRCode");
      if (qrCodeData.valid){
        Serial.print("Payload: ");
        Serial.println((const char *)qrCodeData.payload);
      }
      else{
        Serial.print("Invalid: ");
        Serial.println((const char *)qrCodeData.payload);
      }
    }
    vTaskDelay(100 / portTICK_PERIOD_MS);
  }
}
void setup(){
  Serial.begin(115200);
  Serial.println();
  reader.setup();
  Serial.println("Setup QRCode Reader");
  reader.beginOnCore(1);
  Serial.println("Begin on Core 1");
  xTaskCreate(onQrCodeTask, "onQrCode", 4 * 1024, NULL, 4, NULL);
}

void loop(){
  delay(100);
}

#ifndef DK_QR_CODE_ARDUINO_H_  // https://github.com/alvarowolfx/ESP32QRCodeReader Source codes were taken from here and adapted to Deneyap Kart.
#define DK_QR_CODE_ARDUINO_H_

#include "Arduino.h"
#include "DKCameraPins.h"
#include "esp_camera.h"

#ifndef QR_CODE_READER_STACK_SIZE
#define QR_CODE_READER_STACK_SIZE 40 * 1024
#endif

#ifndef QR_CODE_READER_TASK_PRIORITY
#define QR_CODE_READER_TASK_PRIORITY 5
#endif

enum QRCodeReaderSetupErr
{
  SETUP_OK,
  SETUP_NO_PSRAM_ERROR,
  SETUP_CAMERA_INIT_ERROR,
};

/* This structure holds the decoded QR-code data */
struct QRCodeData
{
  bool valid;
  int dataType;
  uint8_t payload[1024];
  int payloadLen;
};

class DKQRCodeReader
{
private:
  TaskHandle_t qrCodeTaskHandler;
  CameraPins pins;
  framesize_t frameSize;

public:
  camera_config_t cameraConfig;
  QueueHandle_t qrCodeQueue;
  bool begun = false;
  bool debug = false;

  // Constructor
  DKQRCodeReader();
  DKQRCodeReader(CameraPins pins);
  DKQRCodeReader(CameraPins pins, framesize_t frameSize);
  DKQRCodeReader(framesize_t frameSize);
  ~DKQRCodeReader();

  // Setup camera
  QRCodeReaderSetupErr setup();

  void begin();
  void beginOnCore(BaseType_t core);
  bool receiveQrCode(struct QRCodeData *qrCodeData, long timeoutMs);
  void end();

  void setDebug(bool);
};

#endif // ESP32_QR_CODE_ARDUINO_H_

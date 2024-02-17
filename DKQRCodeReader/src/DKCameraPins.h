#ifndef DK_CAMERA_PINS_H_   // https://github.com/alvarowolfx/ESP32QRCodeReader Source codes were taken from here and adapted to Deneyap Kart.
#define DK_CAMERA_PINS_H_

struct CameraPins
{
  int PWDN_GPIO_NUM;
  int RESET_GPIO_NUM;
  int XCLK_GPIO_NUM;
  int SIOD_GPIO_NUM;
  int SIOC_GPIO_NUM;
  int Y9_GPIO_NUM;
  int Y8_GPIO_NUM;
  int Y7_GPIO_NUM;
  int Y6_GPIO_NUM;
  int Y5_GPIO_NUM;
  int Y4_GPIO_NUM;
  int Y3_GPIO_NUM;
  int Y2_GPIO_NUM;
  int VSYNC_GPIO_NUM;
  int HREF_GPIO_NUM;
  int PCLK_GPIO_NUM;
};

#define CAMERA_MODEL_DENEYAP_KART \
  {                             \
    .PWDN_GPIO_NUM = -1,        \
    .RESET_GPIO_NUM = -1,       \
    .XCLK_GPIO_NUM = CAMXC,        \
    .SIOD_GPIO_NUM = CAMSD,        \
    .SIOC_GPIO_NUM = CAMSC,        \
    .Y9_GPIO_NUM = CAMD9,          \
    .Y8_GPIO_NUM = CAMD8,          \
    .Y7_GPIO_NUM = CAMD7,          \
    .Y6_GPIO_NUM = CAMD6,          \
    .Y5_GPIO_NUM = CAMD5,          \
    .Y4_GPIO_NUM = CAMD4,          \
    .Y3_GPIO_NUM = CAMD3,           \
    .Y2_GPIO_NUM = CAMD2,           \
    .VSYNC_GPIO_NUM = CAMV,       \
    .HREF_GPIO_NUM = CAMH,        \
    .PCLK_GPIO_NUM = CAMPC,        \
  }

#endif //DK_CAMERA_PINS_H_
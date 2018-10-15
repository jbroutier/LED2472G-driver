#ifndef LED2472G_H
#define LED2472G_H

#include <stdexcept>

#include <fcntl.h>
#include <string.h>
#include <unistd.h>

#include <sys/ioctl.h>
#include <linux/i2c-dev.h>

static constexpr auto LED2472G_DEVICE_ADDRESS = 0X46;

class LED2472G
{
public:
    explicit LED2472G(const char* devicePath, uint8_t deviceAddress = LED2472G_DEVICE_ADDRESS);
    virtual ~LED2472G();

    void clear();
    void update();

    void setPixel(uint8_t x, uint8_t y, uint16_t color);
    void setPixelRGB(uint8_t x, uint8_t y, uint8_t r, uint8_t g, uint8_t b);

private:
    int device;
    uint8_t pixels[192] = { 0 };
};

#endif // #ifndef LED2472G_H
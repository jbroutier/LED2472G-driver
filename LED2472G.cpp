#include "LED2472G.h"

LED2472G::LED2472G(const char* devicePath, uint8_t deviceAddress)
{
    if ((device = open(devicePath, O_RDWR)) < 0) {
        throw std::runtime_error("Failed to open the I2C bus.");
    }

    if (ioctl(device, I2C_SLAVE_FORCE, deviceAddress) < 0) {
        close(device);
        throw std::runtime_error("Failed to configure the I2C device.");
    }
}

void LED2472G::clear()
{
    for (uint8_t pixel = 0; pixel < 192; pixel++) {
        i2c_smbus_write_byte_data(device, pixel, 0);
    }
}

void LED2472G::setPixel(uint8_t x, uint8_t y, uint16_t color)
{
    uint8_t pixel = (uint8_t)(x * 24 + y);

    pixels[pixel]      = (uint8_t)((color >> 10) & 0x3E);
    pixels[pixel + 8]  = (uint8_t)((color >> 5)  & 0x3F);
    pixels[pixel + 16] = (uint8_t)((color << 1)  & 0x3E);
}

void LED2472G::setPixelRGB(uint8_t x, uint8_t y, uint8_t r, uint8_t g, uint8_t b)
{
    uint16_t r16 = (r >> 3) & 0x1F;
    uint16_t g16 = (g >> 2) & 0x3F;
    uint16_t b16 = (b >> 3) & 0x1F;

    uint16_t color = static_cast<uint16_t>((r16 << 11) + (g16 << 5) + b16);

    setPixel(x, y, color);
}

void LED2472G::update()
{
    for (uint8_t pixel = 0; pixel < 192; pixel++) {
        uint8_t color = pixels[pixel];
        i2c_smbus_write_byte_data(device, pixel, color);
    }
}

LED2472G::~LED2472G()
{
    close(device);
}
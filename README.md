# LED2472G driver

## Description

A C++ driver for the LED2472G 24 channel LED matrix driver manufactured by STMicroelectronics and used in the
RaspberryPi Sense Hat board.

## License

This piece of software is available under the terms of the [MIT License](LICENSE).

## Changelog

**r1.0.0**

* Initial release.

## Example

```cpp
#include "LED2472G.h"
#include <iostream>

int main(int argc, char** argv)
{
    LED2472G ledMatrix("/dev/i2c-1");

    // Turns on the LED on the first row, first column, in red.
    ledMatrix.setPixelRGB(0,0,255,0,0);
    ledMatrix.update();

    return 0;
}
```

## Documentation

### `LED2472G::LED2472G(const char* devicePath, uint8_t deviceAddress = LED2472G_DEVICE_ADDRESS)`
Creates a LED2472G object.

The *devicePath* parameter corresponds to the path of the I2C bus on the system.  
The optional parameter *deviceAddress* allows you to override the address of the device, in case you are using a
standalone device or a modified version of the Sense Hat board.

Throws an `std::runtime_error` exception if the communication with the device fails for any reason.

___
### `LED2472G::~LED2472G()`
Destroys the object, closing the connection to the device.

___
### `void LED2472G::clear()`
Turns off all the LEDs of the matrix.

___
### `void LED2472G::setPixel(uint8_t x, uint8_t y, uint16_t color)`
Sets the color of a LED.

The *x* parameter represents the row of the LED in the range 0-8.  
The *y* parameter represents the column of the LED in the range 0-8.  
The *color* parameter represents the color encoded in RGB565 format.

The color of the LED won't be updated until the `update()` method is called.

___
### `void LED2472G::setPixelRGB(uint8_t x, uint8_t y, uint8_t r, uint8_t g, uint8_t b)`
Sets the color of a LED.

The *x* parameter represents the row of the LED in the range 0-8.  
The *y* parameter represents the column of the LED in the range 0-8.  
The *r* parameter represents the red component of the color in the range 0-255.  
The *g* parameter represents the green component of the color in the range 0-255.  
The *b* parameter represents the blue component of the color in the range 0-255.

The color of the LED won't be updated until the `update()` method is called.

___
### `void LED2472G::update()`
Updates the LEDs.

## Useful resources

[LED2472G datasheet](https://www.st.com/resource/en/datasheet/led2472g.pdf)

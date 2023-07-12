

#include "mbed.h"

InterruptIn button(D8, PullUp);
DigitalOut led(D9);

volatile bool buttonPressed = false;

void handleButtonPress()
{
    buttonPressed = true;
}

int main()
{
    button.rise(&handleButtonPress);

    while (1) {
        if (buttonPressed) {
            led = !led;
            printf("handle\n");
            buttonPressed = false;
        }
    }
}






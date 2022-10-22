#include <stdio.h>
#include <stdint.h>

#define PIN0 0
#define PIN1 1 
#define PIN2 2 
#define PIN3 3 
#define PIN4 4 
#define PIN5 5 
#define PIN6 6 
#define PIN7 7
#define HIGH 1
#define LOW  0
uint8_t PORTA = 0b00000000;

void blinkLed(){
    PORTA = PORTA | 0b00100000;
}

void setBit(uint8_t status){
    PORTA = PORTA | (0x80 >> status);
}

void resetBit(uint8_t status){
    PORTA = PORTA & ~(0x80 >> status);
}

void digitalWrite(uint8_t PIN, uint8_t STATUS){
    if (STATUS == HIGH)
    {
        PORTA = PORTA | (0x80 >> PIN);
    }else{
        PORTA = PORTA & ~(0x80 >> PIN);   
    }   
}
int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}

/*
 * File:   newmain.c
 * Author: peri
 *
 * Created on November 15, 2019, 7:38 PM
 */
// PIC16F1937 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1
#pragma config FOSC = ECH       // Oscillator Selection (ECH, External Clock, High Power Mode (4-32 MHz): device clock supplied to CLKIN pin)
#pragma config WDTE = OFF       // Watchdog Timer Enable (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable (PWRT disabled)
#pragma config MCLRE = ON       // MCLR Pin Function Select (MCLR/VPP pin function is MCLR)
#pragma config CP = OFF         // Flash Program Memory Code Protection (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Memory Code Protection (Data memory code protection is disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable (Brown-out Reset enabled)
#pragma config CLKOUTEN = OFF   // Clock Out Enable (CLKOUT function is disabled. I/O or oscillator function on the CLKOUT pin)
#pragma config IESO = ON        // Internal/External Switchover (Internal/External Switchover mode is enabled)
#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enable (Fail-Safe Clock Monitor is enabled)

// CONFIG2
#pragma config WRT = OFF        // Flash Memory Self-Write Protection (Write protection off)
#pragma config VCAPEN = OFF     // Voltage Regulator Capacitor Enable (All VCAP pin functionality is disabled)
#pragma config PLLEN = ON       // PLL Enable (4x PLL enabled)
#pragma config STVREN = ON      // Stack Overflow/Underflow Reset Enable (Stack Overflow or Underflow will cause a Reset)
#pragma config BORV = LO        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (Vbor), low trip point selected.)
#pragma config LVP = ON         // Low-Voltage Programming Enable (Low-voltage programming enabled)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.


#include <xc.h>
//#include <pic16f1937.h>

#define _XTAL_FREQ 16000000
#define f262 1908
#define f294 1700
#define f330 1515
#define f349 1432
#define f440 1136
#define f466 1072
#define f523 956


void play_note(int note) {
    switch (note) {
        case 262:
            RB5 = 1;
            __delay_us(f262);
            RB5 = 0;
            __delay_us(f262);
            break;
        case 294:
            RB5 = 1;
            __delay_us(f294);
            RB5 = 0;
            __delay_us(f294);
            break;

        case 330:
            RB5 = 1;
            __delay_us(f330);
            RB5 = 0;
            __delay_us(f330);
            break;
        case 349:
            RB5 = 1;
            __delay_us(f349);
            RB5 = 0;
            __delay_us(f349);
            break;
        case 440:
            RB5 = 1;
            __delay_us(f440);
            RB5 = 0;
            __delay_us(f440);
            break;
        case 466:
            RB5 = 1;
            __delay_us(f466);
            RB5 = 0;
            __delay_us(f466);
            break;
        case 523:
            RB5 = 1;
            __delay_us(f523);
            RB5 = 0;
            __delay_us(f523);
            break;
    }
}

void main(void) {
    SCS1 = 1;
    SCS0 = 0;

    IRCF3 = 1;
    IRCF2 = 1;
    IRCF1 = 1;
    IRCF0 = 1;

    /*                       Hap  py  Birth Day  to  you,  Hap py   birth day  to
                             C4   C4   D4   C4   F4   E4   C4   C4   D4   C4   G4 */
    unsigned int notes[] = {262, 262, 294, 262, 349, 330, 262, 262, 294, 262, 392,

        /*you, Hap py  Birth Day  dear  xxxx      Hap  py   birth
          F4   C4   C4   C5   A4   F4   E4   D4   B4b  B4b  A4 */
        349, 262, 262, 523, 440, 349, 330, 294, 466, 466, 440,

        /* day  to  you
           F4   G4   F4   */
        349, 392, 349};

    unsigned short interval[] = {4, 4, 8, 8, 8, 10, 4, 4, 8, 8, 8, 10, 4, 4, 8, 8, 8,
        8, 8, 4, 4, 8, 8, 8, 12};

    TRISB5 = 0;
    RB5 = 0;

    int j;
    int k;
    while (1) {

        for (j = 0; j < 25; j++) {
            for (k = 0; k < interval[j] * 25; k++) {
                play_note(notes[j]);
            }
            __delay_us(1000);
        }

        __delay_ms(1000);

    }
    return;
}

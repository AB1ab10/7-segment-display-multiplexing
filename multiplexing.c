/*
 * File:   7seg.c
 * Author: Alex
 *
 * Created on March 23, 2022, 11:45 AM
 */

//MUltiplexing technique for interfacing PIC16F877A with 2 7seg Displays
#include <xc.h>


#define _XTAL_FREQ 20000000
#define Segment_ON 0
#define Segment_OFF 1

#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = ON         // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)


unsigned char number = 78;
unsigned char i, j;
unsigned char seg[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};

void main(void) {
    

    
    TRISB = 0x00; //all portB pins as output
    TRISC = 0x00; //all portC pins as output
    
    while(1)
    {
        i = number / 10;  //First digit in i
        j = number % 10;  //Second digit in j
        
        PORTCbits.RC0 = Segment_ON; //Turn on first display
        PORTCbits.RC1 = Segment_OFF; //Turn off second display
        
        PORTB = seg[i];
        __delay_ms(10);
        
        PORTCbits.RC0 = Segment_OFF; //Turn on first display
        PORTCbits.RC1 = Segment_ON; //Turn off second display
        
        PORTB = seg[j];
        __delay_ms(10);
    }
    return;
}

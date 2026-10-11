#include <stdint.h>
unsigned int value;

__irq void PWM_ISR (void)
{
    if ( PWMIR & 0x0001 ) PWMIR = 0x0001;
    if ( PWMIR & 0x0002 ) PWMIR = 0x0002;
    if ( PWMIR & 0x0004 ) PWMIR = 0x0004;
    if ( PWMIR & 0x0008 ) PWMIR = 0x0008;
    VICVectAddr = 0x00000000;
}

void PWM_main(unsigned int value)
{
    value = 1;
    VPBDIV = 0x00000001;
    PINSEL0 = PINSEL0 | 0x00000008;
    VICVectAddr0 = (unsigned) PWM_ISR;
    VICVectCntl0 = (0x00000020 | 8);
    VICIntEnable = VICIntEnable | 0x00000100;
    VICIntSelect = VICIntSelect | 0x00000000;
    PWMTCR = 0x02;
    PWMPR = 0x3B;
    PWMMR0 = 1000;
    PWMMR3 = value;
    PWMMCR = 0x00000203;
    PWMLER = 0x09;
    PWMPCR = 0x0800;
    PWMTCR = 0x09;
}

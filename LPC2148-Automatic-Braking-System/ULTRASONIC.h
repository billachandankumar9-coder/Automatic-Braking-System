#define trig (1<<11)
#define echo (IO0PIN&(1<<9))
void ultrasonic_init();
void send_pulse();
unsigned int get_range();
void ultrasonic_init()
{
    IO0DIR|=trig;
    T0CTCR=0;
    T0PR=59;
}
void send_pulse()
{
    T0TC=T0PC=0;
    IO0SET=trig;
    timer1delay(10);
    IO0CLR=trig;
}
unsigned int get_range()
{
    unsigned int get=0;
    send_pulse();
    while(!echo);
    T0TCR=0x01;
    while(echo);
    T0TCR=0;
    get=T0TC;
    get=get/59;
    return get;
}

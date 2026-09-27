//DAC
// 7-ex 주기가 250Hz인 사인파 출력
/*
#include  <LPC17XX.h>
#include <math.h>

void delay_a(unsigned int a)
{
	for (a; a > 0; a--);

}

int main(void)
{
	float PI = 4.0 * atan(1.0);
	float ts = 2.0 * PI * 250000.0 / 50000.0;
	float t = 0;
	uint32_t dac_value;

	LPC_PINCON->PINSEL1 &= ~(3UL << ((26 - 16) * 2));
	LPC_PINCON->PINSEL1 |= 2UL << ((26 - 16) * 2);
	LPC_DAC->DACR = (1024 / 2) << 6;
	LPC_DAC->DACR &= ~(1 << 16);
	LPC_DAC->DACCTRL = 1UL << 1;

	while (1)
	{
		dac_value = 512 + 100.0 * sin(t);
		LPC_DAC->DACR = (dac_value & 0x3FF) << 6;
		delay_a(50);
		t += ts;
	}
}
*/

//7-1 주파수가 250Hz인 펄스를 출력
/*
#include <LPC17XX.h>
#include <math.h>
#include "ahn.lib.h"

int main(void)
{
	float PI = 4.0 * atan(1.0);
	float ts = 2.0 * PI * 250000.0 / 50000.0;
	float t = 0.0;
	uint32_t dac_value;

	LPC_PINCON->PINSEL1 &= ~(3UL << ((26 - 16) * 2));
	LPC_PINCON->PINSEL1 |= 2UL << ((26 - 16) * 2);
	LPC_DAC->DACR = (1024 / 2) << 6;
	LPC_DAC->DACR &= ~(1 << 16);
	LPC_DAC->DACCTRL = 1UL << 1;

	while (1)
	{
		dac_value = 128;
		LPC_DAC -> DACR = (dac_value & 0x3FF) << 6;
		delay_ms(2);

		dac_value = 0;
		LPC_DAC->DACR = (dac_value & 0x3FF) << 6;
		delay_ms(2);
	}
}
*/

//7-2 주파수가 250Hz인 톱니파 출력
/*
#include <LPC17XX.h>
#include <math.h>

void delay_a(unsigned int a)
{
	for (a; a > 0; a--);
}

int main(void)
{
	float PI = 4.0 * atan(1.0);
	float ts = 2.0 * PI * 250000.0 / 50000.0;
	float t = 0.0;
	uint32_t dac_value;

	LPC_PINCON->PINSEL1 &= ~(3UL << ((26 - 16) * 2));
	LPC_PINCON->PINSEL1 |= 2UL << ((26 - 16) * 2);
	LPC_DAC->DACR = (1024 / 2) << 6;
	LPC_DAC->DACR &= ~(1 << 16);
	LPC_DAC->DACCTRL = 1UL << 1;

	int iteration = 5000;

	while (1)
	{
		for (int i = 0; i < 256; i++) {
			dac_value = i;
			LPC_DAC->DACR = (dac_value & 0x3FF) << 6;
			delay_a(10);
		}
	}
}
*/

//7-3  주파수가 250Hz인 사인파 출력
/*
#include <LPC17XX.h>
#include <math.h>

void delay_a(unsigned int a)
{
	for (a; a > 0; a--);
}

int main(void)
{
	float PI = 4.0 * atan(1.0);
	float ts = 2.0 * PI * 250000.0 / 50000.0;
	float t = 0.0;
	uint32_t dac_value;

	LPC_PINCON->PINSEL1 &= ~(3UL << ((26 - 16) * 2));
	LPC_PINCON->PINSEL1 |= 2UL << ((26 - 16) * 2);
	LPC_DAC->DACR = (1024 / 2) << 6;
	LPC_DAC->DACR &= ~(1 << 16);
	LPC_DAC->DACCTRL = 1UL << 1;

    #define SAMPLES 50
	float sin_lookup[SAMPLES];

	for (int i = 0; i < SAMPLES; i++) {
		sin_lookup[i] = sin(2 * PI / SAMPLES * i);
	}

	while(1)
		for (int i = 0; i < SAMPLES; i++) {
			dac_value = 512 + 512 * sin_lookup[i];
			LPC_DAC->DACR = (dac_value & 0x3FF) << 6;
			delay_a(100);
		}
}
*/

//7-4  주파수가 100Hz에서 1kHz까지 증가하는 펄스 풀력(싸이렌)
/*
#include <LPC17XX.h>
#include <math.h>

int main(void)
{
	float PI = 4.0 * atan(1.0);
	float ts = 2.0 * PI * 250000.0 / 50000.0;
	float t = 0.0;
	uint32_t dac_value;

	LPC_PINCON->PINSEL1 &= ~(3UL << ((26 - 16) * 2));
	LPC_PINCON->PINSEL1 |= 2UL << ((26 - 16) * 2);
	LPC_DAC->DACR = (1024 / 2) << 6;
	LPC_DAC->DACR &= ~(1 << 16);
	LPC_DAC->DACCTRL = 1UL << 1;

	int iteration = 0;

	while (1)
	{
		dac_value = 128;
		LPC_DAC->DACR = (dac_value & 0x3FF) << 6;
		delay_a(10000 - iteration);

		dac_value = 0;
		LPC_DAC->DACR = (dac_value & 0x3FF) << 6;
		delay_a(10000 - iteration);

		iteration++;

		if (iteration > 9000) iteration = 0;
	}
}
*/

//UART
//8-ex  터미널로 LED1을 켜고 끈다.
/*
#include "../Ahn_Library/ahn_lib.h"
#include <stdio.h>

uint8_t menu[] = "\r\nEnter 1=LED_ON or 0=LED_OFF or h=hello\r\n";
uint8_t hello[] = "Welcome to Korea!\r\n";

void main(void)
{
	uint8_t ch;

	init_LED();
	init_UART0(9600);
	send_Message(LPC_UART0, menu, sizeof(menu));

	while (1)
	{
		ch = receive_Byte(LPC_UART0);
		if (ch == 0) continue;
		send_Byte(LPC_UART0, ch);

		if (ch == '\r');
		{
			send_Byte(LPC_UART0, ch);
		}
		else if (ch == '1')
		{
			set_LED(LED_1, LED_ON);
		}
		else if (ch == '0')
		{
			set_LED(LED_1, LED_OFF);
		}
		else if (ch == 'h')
		{
			send_Message(LPC_UART0, hello, sizeof(hello));
		}
	}


}
*/

//8-1  터미널에 'a'를 입력하면 LED1이 켜지고, 다시 '1'을 입력하면 LED1이 꺼진다.
/*
#include "..Ahn_Library/ahn_lib.h"

uint8_t menu[] = "\\r\n a = LED_ON or c = LED_OFF\r\\n";

void_main(void)
{
	uint8_t ch;
	init_LED();
	init_UART0(9600);

	while (1)
	{
		ch = receive_Byte(LPC_UART0);
		if (ch == 0) continue;
		send_Byte(LPC_UART0, ch);

		if (ch == '\r')
		{
			ch = '\n';
			send_Byte(LPC_UART0, ch);
		}
		else if (ch == 'a')
		{
			set_LED(LED_1, LED_ON);
			set_LED(LED_2, LED_ON);
			set_LED(LED_3, LED_ON);
		}
		else if (ch == 'c')
		{
			set_LED(LED_1, LED_OFF);
			set_LED(LED_2, LED_OFF);
			set_LED(LED_3, LED_OFF);
		}
	}
}
*/

//8-2  터미널에 '1'을 입력하면 LED1이 켜지고, 다시 '1'을 누르면 LED1이 꺼진다.
/*
#include "..Ahn_Library/ahn_lib.h"

uint8_t menu[] = "\\r\nEnter a = LED_ON or c = LED_OFF\r\\n";

int main(void)
{
	uint8_t ch;

	init_LED();
	init_UART0(9600);
	send_Message(LPC_UART0, menu, sizeof(menu));

	while (1)
	{
		ch = receive_Byte(LPC_UART0);
		if (ch == 0) continue;
		send_Byte(LPC_UART0, ch);

		if (ch == '\r')
		{
			ch = '\n';
			send_Byte(LPC_UART0, ch);
		}

		else if (ch == '1')
		{
			set_LED(LED_1, LED_TOGGLE);
		}
	}
}
*/

//8-3  LED의 상태를 터미널에 표시
/*
#include "..Ahn_Library/ahn_lib.h"

uint8_t menu[] = "\r\nEnter 1=LED_ON or 2=LED_OFF\n";
uint8_t LEDall_ON[] = "\r\nLED : 1 =ON, 2 = ON, 3 = ON\n"; 
uint8_t LEDall_OFF[] = "\r\nLED : 1 =OFF, 2 = OFF, 3 = OFF\n"; 

int main(void)
{
	uint8_t ch;

	init_LED();
	init_UART0(9600);
	send_Message(LPC_UART0, menu, sizeof(menu));

	while (1)
	{
		ch = receive_Byte(LPC_UART0);
		if (ch == 0) continue;
		send_Byte(LPC_UART0, ch);

		if (ch == '\r')
		{
			ch = '\n';
			send_Byte(LPC_UART0, ch);
		}
		if (ch == '1')
		{
			set_LED(LED_1, LED_ON);
			set_LED(LED_2, LED_ON);
			set_LED(LED_3, LED_ON);
			send_Message(LPC_UART0, LEDall_ON, sizeof(LEDall_ON));
		}
		else if (ch == '2')
		{
			set_LED(LED_1, LED_OFF);
			set_LED(LED_2, LED_OFF);
			set_LED(LED_3, LED_OFF);
			send_Message(LPC_UART0, LEDall_OFF, sizeof(LEDall_OFF));
		}

	}
}
*/

//8-4  터미널에 숫자를 입력하면 제곱값을 화면에 표시
/*
#include "../Ahn_Library/ahn_lib.h"
#include <stdio.h> 

int main(void)
{
	uint8_t ch;
	init_LED();
	init_UART0(9600);

	while (1)
	{
		ch = receive_Byte(LPC_UART0);	
		if (ch == 0) continue;				
		send_Byte(LPC_UART0, ch);	

		if (ch == '\r')
		{
			ch = '\n';		
			send_Byte(LPC_UART0, ch);	
		}
		if (ch >= 0 && ch &= 100)
		{
			int num = ch - '0';
			int square = num * num;
			char result_str[100] = { 0, };

			sprintf((char*)res, "\n\r%d * %d = %d\n\r", num, num, num * num);
			send_Message(LPC_UART0, res, strlen(res));
		}
		
	}
}
*/

//타이머
//9-ex-1 LED를 0.5초 켰다가 0.5초 끄는것을 반복
/*
#include "../Ahn_Library/ahn_lib.h";

int main(void)
{
	SystemInit();
	select_Pin(1, 25, 3, 0, 0);
	LPC_SC->PCONP |= (1 << 2);
	LPC_SC->PCLKSEL0 &= ~(3 << 4);

	LPC_TIM1->CTCR = 0x000; 
	LPC_TIM1->PR = (25000 - 1); 
	LPC_TIM1->MR1 = 500; 
	LPC_TIM1->MCR = 0 << 3; 
	LPC_TIM1->MCR |= 1 << 4; 
	LPC_TIM1->MCR &= ~(1 << 5); 
	LPC_TIM1->EMR |= (3 << 6);
	LPC_TIM1->TC = 0; 
	LPC_TIM1->PC = 0; 
	LPC_TIM1->TCR = 1 << 1; 
	LPC_TIM1->TCR = 1 << 0; 
	while (1)
	{
		// do nothing ...
	}
}

}
*/

//9-ex-3  1ms 지연하는 함수 만들기
/*
#include "../Ahn_Library/ahn_lib.h";

void init_delay_MS();
{
	LPC_SC->PCONP |= (1 << 1); // enable power up Timer0 (default)
	LPC_SC->PCLKSEL0 &= ~(3 << 2); // 00=default (PCLK=CCLK/4=25MHz) for Timer 0
	LPC_TIM0->CTCR = 0x00; // 00=Timer mode (default)
	LPC_TIM0->PR = (25000 – 1); // prescale = 25000 clocks (1ms)
	LPC_TIM0->MCR = 0 << 0; // 0=disable interrupt on MR0 Match
	LPC_TIM0->MCR = 0 << 1; // 0=no reset on MR0 Match
	LPC_TIM0->MCR = 0 << 2; // 0=no stop on MR0 Match
	LPC_TIM0->TCR = 0x00; // disable timer
}
void delay_MS(unsigned long milliseconds)
{
	LPC_TIM0->TC = 0; // clear timer counter
	LPC_TIM0->PC = 0; // clear prescale counter
	LPC_TIM0->TCR = 1 << 1; // reset Timer
	LPC_TIM0->TCR = 1 << 0; // enable Timer
	while (LPC_TIM0->TC < milliseconds); // wait until the desired delay
	LPC_TIM0->TCR = 0x00; // 0=disable timer
}
int main(void)
{
	SystemInit(); //called by Startup Code before main(), hence no need to call again.
	init_LED();
	init_delay_MS();
	while (1)
	{
		set_LED(LED_1, LED_TOGGLE);
		delay_MS(500);
	}
}
*/

//9-1  1초 단위로 지연하는 함수 delay_sec(int nSec)만들기
/*
#include "..Ahn_Library/ahn_lib.h"

void delay_sec(unsigned int nSec)
{
	LPC_TIM0->TCR = 0x02;
	LPC_TIM0->TCR = 0x01;

	while (LPC_TIM0->TC < nSec);

	LPC_TIM0->TCR = 0x00;
}

int main(void)
{
	SysyemInit();

	LPC_SC->PCONP |= (1 << 1);
	LPC_SC->PCLKSEL0 &= ~(3 << 2);
	LPC_TIM0->CTCR = 0x0;
	LPC_TIM0->PR = (25000 - 1);
	LPC_TIM0->TCR = 0x02;

	LPC_GPI01->TCR = 0x02;

	while (1)
	{
		LPC_GPI01->FIOSET = (1 << 25);
		delay_sec(1000);
		LPC_GPI01->FIOCLR = (1 << 25);
		delay_sec(1000);
	}
}
*/

//9-2  delay_ms(500)과 delay_MS(500)의 시간차 표시
/*
#include "../Ahn_Library/ahn_lib.h"
#include <stdio.h>
#include <string.h>

int passed_milliseconds1;

void init_delay_MS()
{
	LPC_SC->PCONP |= (1 << 1); // enable power up Timer0 (default)
	LPC_SC->PCLKSEL0 &= ~(3 << 2); // 00=default (PCLK=CCLK/4=25MHz) for Timer 0
	LPC_TIM0->CTCR = 0x00; // 00=Timer mode (default)
	LPC_TIM0->PR = (25000 - 1); // prescale = 25000 clocks (1ms)
	LPC_TIM0->MCR = 0 << 0; // 0=disable interrupt on MR0 Match
	LPC_TIM0->MCR = 0 << 1; // 0=no reset on MR0 Match
	LPC_TIM0->MCR = 0 << 2; // 0=no stop on MR0 Match
	LPC_TIM0->TCR = 0x00; // disable timer
}

void delay_MS(unsigned long milliseconds)
{
	LPC_TIM0->TC = 0; // clear timer counter
	LPC_TIM0->PC = 0; // clear prescale counter
	LPC_TIM0->TCR = 1 << 1; // reset Timer
	LPC_TIM0->TCR = 1 << 0; // enable Timer
	while (LPC_TIM0->TC < milliseconds);
	LPC_TIM0->TCR = 0x00; // 0=disable timer
}

int main(void)
{
	uint8_t ch;

	init_UART0(9600);
	init_delay_MS();

	char res[100] = { 0, };

	while (1)
	{
		LPC_TIM0->TCR = 1 << 1; // reset Timer
		LPC_TIM0->TCR = 1 << 0; // enable Timer
		delay_ms(500);
		passed_milliseconds1 = LPC_TIM0->TC;
		LPC_TIM0->TCR = 0x00;

		sprintf((char*)res, "\n\r%d - %d = %d\n\r", passed_milliseconds1, 500, passed_milliseconds1 - 500);
		send_Message(LPC_UART0, res, strlen(res));
	}
}
*/

//9-3   3초간 알람 울리기
/*
#include <LPC17xx.h>
#include <math.h>
#include "ahn_lib.h"

void init_time()
{
	LPC_SC->PCONP |= (1 << 1); // enable power up Timer0 (default)
	LPC_SC->PCLKSEL0 &= ~(3 << 2); // 00=default (PCLK=CCLK/4=25MHz) for Timer 0
	LPC_TIM0->CTCR = 0x00; // 00=Timer mode (default)
	LPC_TIM0->PR = (25000 - 1); // prescale = 25000 clocks (1ms)
	LPC_TIM0->MCR = 0 << 0; // 0=disable interrupt on MR0 Match
	LPC_TIM0->MCR = 0 << 1; // 0=no reset on MR0 Match
	LPC_TIM0->MCR = 0 << 2; // 0=no stop on MR0 Match
	LPC_TIM0->TCR = 0x00; // disable timer
}

void time(unsigned long milliseconds)
{
	LPC_TIM0->TC = 0; // clear timer counter
	LPC_TIM0->PC = 0; // clear prescale counter
	LPC_TIM0->TCR = 1 << 1; // reset Timer
	LPC_TIM0->TCR = 1 << 0; // enable Timer
	LPC_TIM0->TC; // < milliseconds; // wait until the desired delay
	LPC_TIM0->TCR = 0x00; // 0=disable timer
}

int main(void)
{
	SystemInit();
	init_time();

	float PI = 4.0 * atan(1.0);
	float ts = 2.0 * PI * 250000.0 / 50000.0;
	float t = 0.0;
	uint32_t dac_value;

	LPC_PINCON->PINSEL1 &= ~(3UL << ((26 - 16) * 2)); // 0=P0.26
	LPC_PINCON->PINSEL1 |= 2UL << ((26 - 16) * 2); // 2=AOUT
	LPC_DAC->DACR = (1024 / 2) << 6; // value = 1024/2
	LPC_DAC->DACR &= ~(1 << 16); // bias : 0=1us/700uA, 1=2.5us/350uA
	LPC_DAC->DACCTRL = 1UL << 1; // 1=double buffering, 0=direct conversion

	while (1)
	{
		int timeset = LPC_TIM0->TC;

		if (timeset <= 3000)
		{
			dac_value = 128;
			LPC_DAC - DACR = (dac_value & 0x3FF) << 6;
			delay_ms(2);

			dac_value = 0;
			LPC_DAC - DACR = (dac_value & 0x3FF) << 6;
			delay_ms(2);
		}
		else {
			//do nothing
		}
	}
}
*/

//9-4  터미널의 화면에 자연수를 0부터 1초마다 1씩 증가
/*
#include "../Ahn_Library/ahn_lib.h"
#include <stdio.h>
#include <string.h>

int passed_milliseconds1;

void init_delay_MS()
{
	LPC_SC->PCONP |= (1 << 1); // enable power up Timer0 (default)
	LPC_SC->PCLKSEL0 &= ~(3 << 2); // 00=default (PCLK=CCLK/4=25MHz) for Timer 0
	LPC_TIM0->CTCR = 0x00; // 00=Timer mode (default)
	LPC_TIM0->PR = (25000 - 1); // prescale = 25000 clocks (1ms)
	LPC_TIM0->MCR = 0 << 0; // 0=disable interrupt on MR0 Match
	LPC_TIM0->MCR = 0 << 1; // 0=no reset on MR0 Match
	LPC_TIM0->MCR = 0 << 2; // 0=no stop on MR0 Match
	LPC_TIM0->TCR = 0x00; // disable timer
}
void delay_MS(unsigned long milliseconds)
{
	LPC_TIM0->TC = 0; // clear timer counter
	LPC_TIM0->PC = 0; // clear prescale counter
	LPC_TIM0->TCR = 1 << 1; // reset Timer
	LPC_TIM0->TCR = 1 << 0; // enable Timer
	while (LPC_TIM0->TC < milliseconds);
	LPC_TIM0->TCR = 0x00; // 0=disable timer
}

void delay_sec(unsigned int nSec)
{
	LPC_TIM0->TCR = 0x02; // reset Timer
	LPC_TIM0->TCR = 0x01; // enable timer

	while (LPC_TIM0->TC < nSec); // wait until the desired delay

	LPC_TIM0->TCR = 0x00; // disable timer
}

int main(void)
{
	uint8_t ch;
	init_UART0(9600);
	init_delay_MS();

	char res[100] = { 0, };

	int number = 0;

	while (1)
	{
		LPC_SC->PCONP |= (1 << 1); 		// enable power up Timer0 and Timer1.
		LPC_SC->PCLKSEL0 &= ~(3 << 2);// 00=25MHz (PCLK=CCLK/4)
		LPC_TIM0->CTCR = 0x0;
		LPC_TIM0->PR = (25000 - 1); // prescale = 25000 clocks = 1ms
		LPC_TIM0->TCR = 0x02; 			// reset Timer

		sprintf((char*)res, "\n\r%d \n\r", number);
		send_Message(LPC_UART0, res, strlen(res));
		number++; //number 1씩 증가
		delay_sec(1000); //1초 delay
	}
}
*/

//MCPWM
//10-1  밝기 단계를 4단계로 한다
/*
#include "C:/uVision/Ahn_Library-v0.9/ahn_lib.h"
#include "C:/uVision/Ahn_Library-v0.9/ahn_lib.c"
#include "C:/uVision/Ahn_Library-v0.9/LCD.h"
#include "C:/uVision/Ahn_Library-v0.9/LCD.c"

uint32_t PWMValue = 0;
uint32_t PeriodValue = 300;

void init_delay_MS()
{
	LPC_SC->PCONP |= (1 << 1); // enable power up Timer0 (default)
	LPC_SC->PCLKSEL0 &= ~(3 << 2); // 00=default (PCLK=CCLK/4=25MHz) for Timer 0
	LPC_TIM0->CTCR = 0x00; // 00=Timer mode (default)
	LPC_TIM0->PR = (25000 - 1); // prescale = 25000 clocks (1ms)
	LPC_TIM0->MCR = 0 << 0; // 0=disable interrupt on MR0 Match
	LPC_TIM0->MCR = 0 << 1; // 0=no reset on MR0 Match
	LPC_TIM0->MCR = 0 << 2; // 0=no stop on MR0 Match
	LPC_TIM0->TCR = 0x00; // disable timer
}
void delay_MS(unsigned long milliseconds)
{
	LPC_TIM0->TC = 0; // clear timer counter
	LPC_TIM0->PC = 0; // clear prescale counter
	LPC_TIM0->TCR = 1 << 1; // reset Timer
	LPC_TIM0->TCR = 1 << 0; // enable Timer
	while (LPC_TIM0->TC < milliseconds); // wait until the desired delay
	LPC_TIM0->TCR = 0x00; // 0=disable timer
}

int main()
{
	SystemInit();
	init_delay_MS();
	select_Pin(1, 25, 1, 0, 0); // 0=P1.25, 1=MC1A (LED1)
	LPC_SC->PCONP |= 1 << 17;

	LPC_MCPWM->MCCON_CLR = 1 << 9; // 0=EDGE_MODE
	LPC_MCPWM->MCCON_CLR = 1 << 10; // 0=PASSIVE_LO polarity
	LPC_MCPWM->MCCON_CLR = 1 << 11; // 0=disable Dead Time
	LPC_MCPWM->MCCON_CLR = 1 << 12; // 0=enable Update
	LPC_MCPWM->MCPER1 = PeriodValue; // Period Value;
	LPC_MCPWM->MCPW1 = PWMValue; // Pulse width Value;
	LPC_MCPWM->MCTIM1 = 0; // Timer counter Value
	LPC_MCPWM->MCCAP_CLR = 7 << 0; // disable CAPn
	LPC_MCPWM->MCINTEN_CLR = 7 << 4; // disable interrupt flag
	LPC_MCPWM->MCINTFLAG_CLR = 7 << 4; // clear interrupt flag
	LPC_MCPWM->MCCON_SET = 1 << 8; // 1=start conversion

	while (1)
	{
		delay_MS(1000);
		PWMValue = 0;
		LPC_MCPWM->MCPER1 = PeriodValue;
		LPC_MCPWM->MCPW1 = PWMValue;

		delay_MS(1000);
		PWMValue = 100;
		LPC_MCPWM->MCPER1 = PeriodValue;
		LPC_MCPWM->MCPW1 = PWMValue;

		delay_MS(1000);
		PWMValue = 200;
		LPC_MCPWM->MCPER1 = PeriodValue;
		LPC_MCPWM->MCPW1 = PWMValue;

		delay_MS(1000);
		PWMValue = 300;
		LPC_MCPWM->MCPER1 = PeriodValue;
		LPC_MCPWM->MCPW1 = PWMValue;
	}
}
*/

//10-2  밝기 단계를 2단계
/*
#include "C:/uVision/Ahn_Library-v0.9/ahn_lib.h"
#include "C:/uVision/Ahn_Library-v0.9/ahn_lib.c"
#include "C:/uVision/Ahn_Library-v0.9/LCD.h"
#include "C:/uVision/Ahn_Library-v0.9/LCD.c"

uint32_t PWMValue = 0;
uint32_t PeriodValue = 300;


void init_delay_MS()
{
	LPC_SC->PCONP |= (1 << 1); // enable power up Timer0 (default)
	LPC_SC->PCLKSEL0 &= ~(3 << 2); // 00=default (PCLK=CCLK/4=25MHz) for Timer 0
	LPC_TIM0->CTCR = 0x00; // 00=Timer mode (default)
	LPC_TIM0->PR = (25000 - 1); // prescale = 25000 clocks (1ms)
	LPC_TIM0->MCR = 0 << 0; // 0=disable interrupt on MR0 Match
	LPC_TIM0->MCR = 0 << 1; // 0=no reset on MR0 Match
	LPC_TIM0->MCR = 0 << 2; // 0=no stop on MR0 Match
	LPC_TIM0->TCR = 0x00; // disable timer
}
void delay_MS(unsigned long milliseconds)
{
	LPC_TIM0->TC = 0; // clear timer counter
	LPC_TIM0->PC = 0; // clear prescale counter
	LPC_TIM0->TCR = 1 << 1; // reset Timer
	LPC_TIM0->TCR = 1 << 0; // enable Timer
	while (LPC_TIM0->TC < milliseconds); // wait until the desired delay
	LPC_TIM0->TCR = 0x00; // 0=disable timer
}

int main()
{
	SystemInit();
	init_delay_MS();
	select_Pin(1, 25, 1, 0, 0); // 0=P1.25, 1=MC1A (LED1)
	LPC_SC->PCONP |= 1 << 17; // power on MCPWM
	// initialize MCPWM channel 1
	LPC_MCPWM->MCCON_CLR = 1 << 9; // 0=EDGE_MODE
	LPC_MCPWM->MCCON_CLR = 1 << 10; // 0=PASSIVE_LO polarity
	LPC_MCPWM->MCCON_CLR = 1 << 11; // 0=disable Dead Time
	LPC_MCPWM->MCCON_CLR = 1 << 12; // 0=enable Update
	LPC_MCPWM->MCPER1 = PeriodValue; // Period Value;
	LPC_MCPWM->MCPW1 = PWMValue; // Pulse width Value;
	LPC_MCPWM->MCTIM1 = 0; // Timer counter Value
	LPC_MCPWM->MCCAP_CLR = 7 << 0; // disable CAPn
	LPC_MCPWM->MCINTEN_CLR = 7 << 4; // disable interrupt flag
	LPC_MCPWM->MCINTFLAG_CLR = 7 << 4; // clear interrupt flag
	LPC_MCPWM->MCCON_SET = 1 << 8; // 1=start conversion

	while (1)
	{
		delay_MS(1000);
		PWMValue = 100;
		LPC_MCPWM->MCPER1 = PeriodValue;
		LPC_MCPWM->MCPW1 = PWMValue;

		delay_MS(1000);
		PWMValue = 200;
		LPC_MCPWM->MCPER1 = PeriodValue;
		LPC_MCPWM->MCPW1 = PWMValue;
	}
}
*/

//10-3  밝기의 반복 주기를 2초
/*
#include "C:/uVision/Ahn_Library-v0.9/ahn_lib.h"
#include "C:/uVision/Ahn_Library-v0.9/ahn_lib.c"
#include "C:/uVision/Ahn_Library-v0.9/LCD.h"
#include "C:/uVision/Ahn_Library-v0.9/LCD.c"

uint32_t PWMValue = 0;
uint32_t PeriodValue = 300;


void init_delay_MS()
{
	LPC_SC->PCONP |= (1 << 1); // enable power up Timer0 (default)
	LPC_SC->PCLKSEL0 &= ~(3 << 2); // 00=default (PCLK=CCLK/4=25MHz) for Timer 0
	LPC_TIM0->CTCR = 0x00; // 00=Timer mode (default)
	LPC_TIM0->PR = (25000 - 1); // prescale = 25000 clocks (1ms)
	LPC_TIM0->MCR = 0 << 0; // 0=disable interrupt on MR0 Match
	LPC_TIM0->MCR = 0 << 1; // 0=no reset on MR0 Match
	LPC_TIM0->MCR = 0 << 2; // 0=no stop on MR0 Match
	LPC_TIM0->TCR = 0x00; // disable timer
}
void delay_MS(unsigned long milliseconds)
{
	LPC_TIM0->TC = 0; // clear timer counter
	LPC_TIM0->PC = 0; // clear prescale counter
	LPC_TIM0->TCR = 1 << 1; // reset Timer
	LPC_TIM0->TCR = 1 << 0; // enable Timer
	while (LPC_TIM0->TC < milliseconds); // wait until the desired delay
	LPC_TIM0->TCR = 0x00; // 0=disable timer
}

int main()
{
	SystemInit();
	init_delay_MS();
	select_Pin(1, 25, 1, 0, 0); // 0=P1.25, 1=MC1A (LED1)
	LPC_SC->PCONP |= 1 << 17; // power on MCPWM
	// initialize MCPWM channel 1
	LPC_MCPWM->MCCON_CLR = 1 << 9; // 0=EDGE_MODE
	LPC_MCPWM->MCCON_CLR = 1 << 10; // 0=PASSIVE_LO polarity
	LPC_MCPWM->MCCON_CLR = 1 << 11; // 0=disable Dead Time
	LPC_MCPWM->MCCON_CLR = 1 << 12; // 0=enable Update
	LPC_MCPWM->MCPER1 = PeriodValue; // Period Value;
	LPC_MCPWM->MCPW1 = PWMValue; // Pulse width Value;
	LPC_MCPWM->MCTIM1 = 0; // Timer counter Value
	LPC_MCPWM->MCCAP_CLR = 7 << 0; // disable CAPn
	LPC_MCPWM->MCINTEN_CLR = 7 << 4; // disable interrupt flag
	LPC_MCPWM->MCINTFLAG_CLR = 7 << 4; // clear interrupt flag
	LPC_MCPWM->MCCON_SET = 1 << 8; // 1=start conversion

	while (1)
	{
		delay_MS(2000);
		PWMValue = 100;
		LPC_MCPWM->MCPER1 = PeriodValue;
		LPC_MCPWM->MCPW1 = PWMValue;

		delay_MS(2000);
		PWMValue = 200;
		LPC_MCPWM->MCPER1 = PeriodValue;
		LPC_MCPWM->MCPW1 = PWMValue;
	}
}
*/

//10-4  BUT2을 누를 때마다 LED1이 점점 밝아진다.
/*
#include "C:/uVision/Ahn_Library-v0.9/ahn_lib.h"
#include "C:/uVision/Ahn_Library-v0.9/ahn_lib.c"
#include "C:/uVision/Ahn_Library-v0.9/LCD.h"
#include "C:/uVision/Ahn_Library-v0.9/LCD.c"

uint32_t PWMValue = 0;
uint32_t PeriodValue = 300;

void init_delay_MS()
{
	LPC_SC->PCONP |= (1 << 1); // enable power up Timer0 (default)
	LPC_SC->PCLKSEL0 &= ~(3 << 2); // 00=default (PCLK=CCLK/4=25MHz) for Timer 0
	LPC_TIM0->CTCR = 0x00; // 00=Timer mode (default)
	LPC_TIM0->PR = (25000 - 1); // prescale = 25000 clocks (1ms)
	LPC_TIM0->MCR = 0 << 0; // 0=disable interrupt on MR0 Match
	LPC_TIM0->MCR = 0 << 1; // 0=no reset on MR0 Match
	LPC_TIM0->MCR = 0 << 2; // 0=no stop on MR0 Match
	LPC_TIM0->TCR = 0x00; // disable timer
}
void delay_MS(unsigned long milliseconds)
{
	LPC_TIM0->TC = 0; // clear timer counter
	LPC_TIM0->PC = 0; // clear prescale counter
	LPC_TIM0->TCR = 1 << 1; // reset Timer
	LPC_TIM0->TCR = 1 << 0; // enable Timer
	while (LPC_TIM0->TC < milliseconds); // wait until the desired delay
	LPC_TIM0->TCR = 0x00; // 0=disable timer
}

int main()
{
	bool btn1_pressed = 0;
	SystemInit();
	init_delay_MS();
	select_Pin(1, 25, 1, 0, 0);
	LPC_SC->PCONP |= 1 << 17;

	LPC_MCPWM->MCCON_CLR = 1 << 9; // 0=EDGE_MODE
	LPC_MCPWM->MCCON_CLR = 1 << 10; // 0=PASSIVE_LO polarity
	LPC_MCPWM->MCCON_CLR = 1 << 11; // 0=disable Dead Time
	LPC_MCPWM->MCCON_CLR = 1 << 12; // 0=enable Update
	LPC_MCPWM->MCPER1 = PeriodValue; // Period Value;
	LPC_MCPWM->MCPW1 = PWMValue; // Pulse width Value;
	LPC_MCPWM->MCTIM1 = 0; // Timer counter Value
	LPC_MCPWM->MCCAP_CLR = 7 << 0; // disable CAPn
	LPC_MCPWM->MCINTEN_CLR = 7 << 4; // disable interrupt flag
	LPC_MCPWM->MCINTFLAG_CLR = 7 << 4; // clear interrupt flag
	LPC_MCPWM->MCCON_SET = 1 << 8; // 1=start conversion

	while (1)
	{
		bool btn1_current_state = get_BUTTON(BUT1);

		if (btn1_current_state && !btn1_pressed) {
			btn1_pressed = true;
			PWMValue += 50;
			LPC_MCPWM->MCPER1 = PeriodValue;
			LPC_MCPWM->MCPW1 = PWMValue;
		}
		else if (!btn1_current_state) {
			btn1_pressed = false;
		}
	}
}
*/

//10-5  1초마다 LED3가 3단계로 밝아진다
/*
#include "../Ahn_Library/ahn_lib.h"
uint32_t duty = 0;

void init_PWM1(void)
{
	LPC_PINCON->PINSEL3 |= (2 << 4);

	LPC_PWM1->PCR = 0x0; // single Edge PWM (default)
	LPC_PWM1->PR = 25 - 1; // clocks = 25MHz * 1us
	LPC_PWM1->MR0 = 1000; // Toff + Ton = 1000us = 1ms
	LPC_PWM1->MR1 = 500; // Toff = 500us (duty=50%)
	LPC_PWM1->MCR = (0 << 0) | (1 << 1) | (0 << 2);

	LPC_PWM1->CTCR = 0; // 00=timer mode (default)
	LPC_PWM1->LER = (1 << 0) | (1 << 1); // load MR0, MR1 immediately
	LPC_PWM1->PCR |= (1 << 9); // enable MR1 output
	LPC_PWM1->TCR = (1 << 1); // reset TC & prescale counter
	LPC_PWM1->TCR = (1 << 0) | (1 << 3);

	int main(void)
	{
		init_PWM1();
		int count = 1;
		while (1)
		{
			LPC_PWM1->MR1 = 1000 - 250 * count;
			LPC_PWM1->LER = (1 << 1);
			delay_ms(1000);
			count++;
			if (count == 4) count = 1;
		}
	}
}
*/

//10-6  BUT1를 누를 때마다 LED3의 밝기가 점점 밝아졌다가 어두워진다
/*
#include "ahn_lib.h"

int duty = 0;

void init_PWM1(void)
{
	LPC_PINCON->PINSEL3 |= (2 << 4); // 2=PWM1.1, 0=P1.18(USB_UP_LED)
	//LPC_SC->PCONP |= (1<<6); // enable clock of PWM1 (default)
	//LPC_SC->PCLKSEL0 &= ~(3<<12); // 00=CCLK/4(default)
	LPC_PWM1->PCR = 0x0; // single Edge PWM (default)
	LPC_PWM1->PR = 25 - 1; // clocks = 25MHz * 1us
	LPC_PWM1->MR0 = 1000; // Toff + Ton = 1000us = 1ms
	LPC_PWM1->MR1 = 1000 - duty; // Toff = 500us (duty=50%)
	LPC_PWM1->MCR = (0 << 0) | (1 << 1) | (0 << 2);// 010=no interrupt, reset TC,
	// no stop on MR0 match
	LPC_PWM1->CTCR = 0; // 00=timer mode (default)
	LPC_PWM1->LER = (1 << 0) | (1 << 1); // load MR0, MR1 immediately
	LPC_PWM1->PCR |= (1 << 9); // enable MR1 output
	LPC_PWM1->TCR = (1 << 1); // reset TC & prescale counter
	LPC_PWM1->TCR = (1 << 0) | (1 << 3); // enable counters and PWM output
}

int main(void)
{
	init_PWM1();
	int count = 1;
	int pin;

	while (1)
	{
		pin = get_BUTTON(BUT1);
		if (pin == 1)
		{
			if (count <= 3) duty += 100;
			else duty -= 100;

			LPC_PWM1->MR1 = 1000 - duty;
			LPC_PWM1->LER = (1 << 1);

			count++;
			if (count == 7) count = 1;

			delay_ms(500);
		}
	}
}
*/

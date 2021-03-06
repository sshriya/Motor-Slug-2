/* ******************** Digital Input/Output *****************************************
 * Tiva - TM4C123
 * Author : Shriya Shah
 * Date: 3/20/2017
 * ***********************************************************************************
 * INPUT: PF0, PF4
 * OUTPUT: PF1, PF2, PF3
 * ***********************************************************************************
 * */

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"

#define Red_led  GPIO_PIN_1
#define Green_led GPIO_PIN_3
#define Blue_led GPIO_PIN_2

#define SW2 GPIO_PIN_0 //requires unlocking
#define SW1 GPIO_PIN_4

int main(void)
{
    // 1. Clock Setup @50 MHZ (200/4)`
    SysCtlClockSet(SYSCTL_SYSDIV_4|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|
                    SYSCTL_OSC_MAIN);

    // 2. Enable Port as GPIO
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF))
    {
    }

    // 3. Configure pin as output
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, Red_led|Green_led|Blue_led);

    // 3. Configure pin as input
    GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, SW1);
    GPIOPadConfigSet(GPIO_PORTF_BASE, SW1, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);


    while(1)
    {
    	int ch;
    	// Read ch which is 0 when switch is pressed and 1 when released
    	ch = GPIOPinRead(GPIO_PORTF_BASE, SW1)&SW1;

    	// when switch not pressed
    	if(ch){

    		//Turn off all other leds
    		GPIOPinWrite(GPIO_PORTF_BASE, Blue_led, ~(Blue_led));

            //Turn On
            GPIOPinWrite(GPIO_PORTF_BASE, Red_led, Red_led);

            //Wait
            SysCtlDelay(2000000);

            // Turn Off
            GPIOPinWrite(GPIO_PORTF_BASE, Red_led, ~(Red_led));

            // Wait
            SysCtlDelay(2000000);

    	}else{

    		//Turn off other leds
    		GPIOPinWrite(GPIO_PORTF_BASE, Red_led, ~(Red_led));

    		//Turn on Blue
    		GPIOPinWrite(GPIO_PORTF_BASE, Blue_led, Blue_led);
    	}
    }
}

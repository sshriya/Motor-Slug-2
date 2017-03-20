/*
 ************************* Digital I/O **********************************************
 * Author : Shriya Shah
 * Date: 3/20/2017
 * ***********************************************************************************
 * OUTPUT: PF1,2,3
 * INPUT: PF0, 4
 * ***********************************************************************************
 *  */

#include<stdio.h>
#include<stdint.h>
#include<stdbool.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"

#define led1 GPIO_PIN_1

int main(void) {
	
	// 1. Clock
	SysCtlClockSet(SYSCTL_SYSDIV_4|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);
	return 0;
}

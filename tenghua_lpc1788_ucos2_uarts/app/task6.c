// task6
// ËïÐÂ»¢
// 20110217


#include <string.h>
#include <stdio.h>
#include "lpc177x_8x.h"
#include "ucos_ii.h"
#include "uart.h"
#include "task6.h"


void task6(void *p)
{ 
    printf("this is task6..\r\n");
    
    while(1) {
        
        OSTimeDly(OS_TICKS_PER_SEC * 6);
    }
}

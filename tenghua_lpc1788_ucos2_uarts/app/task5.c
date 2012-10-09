// task5
// ËïÐÂ»¢
// 20110217


#include <string.h>
#include <stdio.h>
#include "lpc177x_8x.h"
#include "ucos_ii.h"
#include "uart.h"
#include "task5.h"


void task5(void *p)
{ 
    printf("this is task5..\r\n");
    
    while(1) {
        
        OSTimeDly(OS_TICKS_PER_SEC * 5);
    }
}

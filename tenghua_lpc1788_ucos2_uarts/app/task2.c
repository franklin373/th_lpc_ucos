// task2
// ËïÐÂ»¢
// 20110217

// udisk 

#include <string.h>
#include <stdio.h>
#include "lpc177x_8x.h"
#include "ucos_ii.h"

#include "uart.h"
#include "task2.h"


void task2(void *p)
{ 
    printf("this is task2..\r\n");
    
    while(1) {
        
        OSTimeDly(OS_TICKS_PER_SEC * 2);
    }
}

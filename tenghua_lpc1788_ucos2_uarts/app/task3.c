// task3
// 孙新虎
// 20110217

// 20110513 本任务用于lwip


#include <string.h>
#include <stdio.h>
#include "lpc177x_8x.h"
#include "ucos_ii.h"

#include "uart.h"
#include "task3.h"


void task3(void *p)
{ 
    printf("this is task3..\r\n");
    
    while(1) {
        
        OSTimeDly(OS_TICKS_PER_SEC * 3);
    }
}

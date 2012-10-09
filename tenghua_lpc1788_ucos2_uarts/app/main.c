// main
// 腾华电子上海代表处
// 孙新虎
// 20110217

#include <stdio.h>
#include <string.h>

#include "system_lpc177x_8x.h"
#include "lpc177x_8x_systick.h"
#include "lpc177x_8x_gpio.h"

#include "ucos_ii.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// task config

#define TASK2_ENABLE    1
#define TASK3_ENABLE    1
#define TASK4_ENABLE    1
#define TASK5_ENABLE    1
#define TASK6_ENABLE    1
#define TASK7_ENABLE    1

#include "task1.h"

#if TASK2_ENABLE > 0
#include "task2.h"
#endif

#if TASK3_ENABLE > 0
#include "task3.h"
#endif

#if TASK4_ENABLE > 0
#include "task4.h"
#endif

#if TASK5_ENABLE > 0
#include "task5.h"
#endif

#if TASK6_ENABLE > 0
#include "task6.h"
#endif

#if TASK7_ENABLE > 0
#include "task7.h"
#endif

// task stack

#pragma location="AHB_RAM_MEMORY"
static OS_STK os_task1_stk[1024];

#if TASK2_ENABLE > 0
#pragma location="AHB_RAM_MEMORY"
static OS_STK os_task2_stk[1024];
#endif

#if TASK3_ENABLE > 0
#pragma location="AHB_RAM_MEMORY"
static OS_STK os_task3_stk[512];
#endif

#if TASK4_ENABLE > 0
#pragma location="AHB_RAM_MEMORY"
static OS_STK os_task4_stk[256];
#endif

#if TASK5_ENABLE > 0
#pragma location="AHB_RAM_MEMORY"
static OS_STK os_task5_stk[256];
#endif

#if TASK6_ENABLE > 0
#pragma location="AHB_RAM_MEMORY"
static OS_STK os_task6_stk[256];
#endif

#if TASK7_ENABLE > 0
#pragma location="AHB_RAM_MEMORY"
static OS_STK os_task7_stk[256];
#endif


static uint16_t OSStkFree(uint8_t *p, uint16_t size)
{
    uint16_t i;
    for(i=(size/1); i; i--) {
        if(*p++!=0xa4)
            break;
    }
    return (size - (i * 1));
}

void OSStkChk(void)
{
    uint16_t stk_free;
    
    printf("tasks\tfree\ttotal\r\n");
    
    // task1
    stk_free = OSStkFree((void *)os_task1_stk, sizeof(os_task1_stk));
    printf("task1:\t%d\t%d\r\n", stk_free, sizeof(os_task1_stk));

    
#if TASK2_ENABLE > 0
    // task2
    stk_free = OSStkFree((void *)os_task2_stk, sizeof(os_task2_stk));
    printf("task2:\t%d\t%d\r\n", stk_free, sizeof(os_task2_stk));
#endif
    
#if TASK3_ENABLE > 0
    // task3
    stk_free = OSStkFree((void *)os_task3_stk, sizeof(os_task3_stk));
    printf("task3:\t%d\t%d\r\n", stk_free, sizeof(os_task3_stk));
#endif
    
#if TASK4_ENABLE > 0
    // task4
    stk_free = OSStkFree((void *)os_task4_stk, sizeof(os_task4_stk));
    printf("task4:\t%d\t%d\r\n", stk_free, sizeof(os_task4_stk));
#endif
    
#if TASK5_ENABLE > 0
    // task5
    stk_free = OSStkFree((void *)os_task5_stk, sizeof(os_task5_stk));
    printf("task5:\t%d\t%d\r\n", stk_free, sizeof(os_task5_stk));
#endif
    
#if TASK6_ENABLE > 0
    // task6
    stk_free = OSStkFree((void *)os_task6_stk, sizeof(os_task6_stk));
    printf("task6:\t%d\t%d\r\n", stk_free, sizeof(os_task6_stk));
#endif
    
#if TASK7_ENABLE > 0
    // task7
    stk_free = OSStkFree((void *)os_task7_stk, sizeof(os_task7_stk));
    printf("task7:\t%d\t%d\r\n", stk_free, sizeof(os_task7_stk));
#endif    

    // task idle
    stk_free = OSStkFree((void *)OSTaskIdleStk, sizeof(OSTaskIdleStk));
    printf("idle:\t%d\t%d\r\n", stk_free,sizeof(OSTaskIdleStk));

}

// task prio
enum {
    os_task1_prio = 0,
    os_task3_prio,
    os_task2_prio,
    os_task4_prio,
    os_task5_prio,
    os_task6_prio,
    os_task7_prio,
};

// create task 2 to task 14
void create_tasks(void)
{
#if TASK2_ENABLE > 0
    memset(os_task2_stk, 0xa4, sizeof(os_task2_stk));
    OSTaskCreate(task2, (void *)0, &os_task2_stk[sizeof(os_task2_stk)/sizeof(os_task2_stk[0]) - 1], os_task2_prio);
#endif

#if TASK3_ENABLE > 0
    memset(os_task3_stk, 0xa4, sizeof(os_task3_stk));
    OSTaskCreate(task3, (void *)0, &os_task3_stk[sizeof(os_task3_stk)/sizeof(os_task3_stk[0]) - 1], os_task3_prio);
#endif
    
#if TASK4_ENABLE > 0
    memset(os_task4_stk, 0xa4, sizeof(os_task4_stk));
    OSTaskCreate(task4, (void *)0, &os_task4_stk[sizeof(os_task4_stk)/sizeof(os_task4_stk[0]) - 1], os_task4_prio);
#endif
    
#if TASK5_ENABLE > 0
    memset(os_task5_stk, 0xa4, sizeof(os_task5_stk));
    OSTaskCreate(task5, (void *)0, &os_task5_stk[sizeof(os_task5_stk)/sizeof(os_task5_stk[0]) - 1], os_task5_prio);
#endif
    
#if TASK6_ENABLE > 0
    memset(os_task6_stk, 0xa4, sizeof(os_task6_stk));
    OSTaskCreate(task6, (void *)0, &os_task6_stk[sizeof(os_task6_stk)/sizeof(os_task6_stk[0]) - 1], os_task6_prio);
#endif
    
#if TASK7_ENABLE > 0    
    memset(os_task7_stk, 0xa4, sizeof(os_task7_stk));
    OSTaskCreate(task7, (void *)0, &os_task7_stk[sizeof(os_task7_stk)/sizeof(os_task7_stk[0]) - 1], os_task7_prio);
#endif

}

int main(void)
{
    //SystemInit();   // init system core clock
    SystemCoreClockUpdate();// get SystemCoreClock
    SYSTICK_InternalInit((uint32_t)(1000.0F / (float)OS_TICKS_PER_SEC)); // init os tick timer
    SYSTICK_IntCmd(ENABLE);	// enable os tick timer interrupt
    SYSTICK_Cmd(ENABLE);    // enable os tick timer counter

    memset(OSTaskIdleStk, 0xa4, sizeof(OSTaskIdleStk));
    
    OSInit();    // init uc/os-ii

    memset(os_task1_stk, 0xa4, sizeof(os_task1_stk));
    
    // create tasks
    OSTaskCreate(task1, (void *)0, &os_task1_stk[sizeof(os_task1_stk)/sizeof(os_task1_stk[0]) - 1], os_task1_prio);
    
    // lets go now
    OSStart(); 
}

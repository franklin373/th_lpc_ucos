// task1
// ���»�
// �ڻ������Ϻ�����
// 20110217

// task1 ���ڳ�ʼ��BSP����������

#include <string.h>
#include <stdio.h>
#include "lpc177x_8x.h"
#include "system_lpc177x_8x.h"
#include "ucos_ii.h"

#include "uart.h"
#include "task1.h"

void task1(void *p)
{ 
    uart0_init(115200);

    printf("�ڻ������Ϻ�����\r\n");
    printf("lpc1788-ek\r\n");
    printf("%dMHz\r\n", SystemCoreClock/1000000ul);

    // create task 2 to task 7
    void create_tasks(void);
    create_tasks();

    printf("this is task1..\r\n");    
    
    while(1) {
        OSTimeDly(OS_TICKS_PER_SEC * 1);
    }
}

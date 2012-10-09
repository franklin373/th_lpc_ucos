// task7
// ÀÔ–¬ª¢
// 20110217

// LED…¡À∏

#include <stdio.h>
#include "lpc177x_8x_gpio.h"
#include "ucos_ii.h"
#include "task7.h"

void led_init(void)
{
    // 2.3 
    // 2.4 
    // 0.27 
    // 2.6
    
    GPIO_SetDir(4, (1<<22), 1);
    GPIO_SetDir(4, (1<<23), 1);
    GPIO_SetDir(4, (1<<26), 1);
    GPIO_SetDir(4, (1<<27), 1);
}


void led_value(uint8_t map)
{
    if((map & 1) != 0)
        GPIO_ClearValue(4, (1<<22));
    else
        GPIO_SetValue(4, (1<<22));
    
    if((map & 2) != 0)
        GPIO_ClearValue(4, (1<<23));
    else
        GPIO_SetValue(4, (1<<23));

    if((map & 4) != 0)
        GPIO_ClearValue(4, (1<<26));
    else
        GPIO_SetValue(4, (1<<26));

    if((map & 8) != 0)
        GPIO_ClearValue(4, (1<<27));
    else
        GPIO_SetValue(4, (1<<27));
}


void task7(void *p)
{
    printf("this is task7..\r\n");
    
    led_init();
    
    uint8_t i = 0;
    
    while(1) {
        
        
        static const uint8_t led_tab[] = {
            0x00,
            0x01,0x02,0x04,0x08,
            0x04,0x02,0x01,
            0x0f,0x00,0x0f,0x00,
            0x03,0x0c,
            0x02+0x04,0x03,0x02+0x04,0x0c,0x02+0x04,0x03,
            0x01,0x02,0x04,0x08,0x01,0x02,0x04,0x08,
        };
        
        led_value(led_tab[i++]);
        i %= sizeof(led_tab);
        
        OSTimeDly(OS_TICKS_PER_SEC / 2);
    
    }
}

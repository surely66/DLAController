#include "delay.h"
extern TIM_HandleTypeDef htim4;
void delay_init(void)
{
	HAL_TIM_Base_Start(&htim4);
}

void delay_us(uint32_t us)
{
	__IO uint16_t tOld, tNow;
	__IO uint32_t cnt = 0;
	tOld = __HAL_TIM_GET_COUNTER(&htim4);
	while(1)
	{
		tNow = __HAL_TIM_GET_COUNTER(&htim4);
		if(tNow != tOld)
		{
			if(tNow> tOld) cnt +=tNow - tOld;
			else cnt += 0xffff-tOld+tNow;
			tOld = tNow;
			if(cnt>=us) break;
		}
	
	}

}

void delay_ms(uint32_t ms)
{
	HAL_Delay(ms);

}

#include <STM32F4TouchController.hpp>

/* USER CODE BEGIN BSP user includes */
#include "ft5206.h"
extern int16_t pre_x;
extern int16_t pre_y;
/* USER CODE END BSP user includes */

extern "C"
{

uint32_t LCD_GetXSize();
uint32_t LCD_GetYSize();
}

using namespace touchgfx;

void STM32F4TouchController::init()
{
   /* USER CODE BEGIN F4TouchController_init */

    /* Add code for touch controller Initialization*/
    //BSP_TS_Init(LCD_GetXSize(), LCD_GetYSize());
	FT5206_Init();
  /* USER CODE END  F4TouchController_init  */
}

bool STM32F4TouchController::sampleTouch(int32_t& x, int32_t& y)
{
  /* USER CODE BEGIN  F4TouchController_sampleTouch  */
    
    /*TS_StateTypeDef state;
    BSP_TS_GetState(&state);
    if (state.TouchDetected)
    {
        x = state.x;
        y = state.y;
        return true;
    }*/
  	get_one_point();

		if(pre_x == -1 && pre_y == -1)
		{
				return false;
		}
		else
		{
				x = pre_x;
				y = pre_y;
				return true;
		}


 /* USER CODE END F4TouchController_sampleTouch */    
}

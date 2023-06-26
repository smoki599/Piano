/*
 * app_timers.h
 *
 *  Created on: Dec 3, 2022
 *      Author: patriciobulic
 */

#ifndef INC_APP_TIMERS_H_
#define INC_APP_TIMERS_H_

#define __USE_TIM3_BASE__

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_hal.h"

HAL_StatusTypeDef Init_TIM3(TIM_HandleTypeDef* TIMHandle);
//void MX_TIM2_Init(void);
//void HAL_TIM_MspPostInit(TIM_HandleTypeDef* htim);
#endif /* INC_TIMERS_H_ */

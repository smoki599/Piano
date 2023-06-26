#include "piano.h"

#include "app_timers.h"
#include "melody.h"
#include "main.h"
TIM_HandleTypeDef htim2;
//TIM_HandleTypeDef htim2;
static void Draw_Menu(void);
static void GetPosition();
static void reDraw();
static void PlayBlack(int8_t x);
static void PlayWhite(int8_t x);
static void clean(int8_t x,int col);

static void setPWM(TIM_HandleTypeDef timer, uint32_t channel, uint16_t period, uint16_t pulse);
static void MX_TIM2_Init(void);

/*
void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);
*/
int isPlaing = 0;
int colorPlay = -1;
/*	1->Black
 *	0->White
 */
int noteNum = -1;

// x,y position of tuch
uint16_t x = 0, y = 0;
uint16_t Px = 0, Py = 0;
uint32_t x_size, y_size;

uint16_t Mine_Num = 50;

uint16_t Tmp_Mine_Num = 0;

int16_t x_move = 0, y_move = 0;

long Time_playinf = 0;

static TS_State_t TS_State;

void pianoMain()
{
  BSP_LCD_GetXSize(0, &x_size);
  BSP_LCD_GetYSize(0, &y_size);

  MX_TIM2_Init();

  Draw_Menu();

  // define time for random
  Time_playinf = HAL_GetTick();
  while (1)
  {
      if ((HAL_GetTick() - Time_playinf) > 1000)
      {
        GetPosition();
      }
  }
}


static void Draw_Menu(void)
{
  /* Set background Layer */
  UTIL_LCD_SetLayer(0);

  /* Clear the LCD */
  UTIL_LCD_Clear(UTIL_LCD_COLOR_WHITE);

  // border around screen
  UTIL_LCD_DrawRect(0, 0, x_size - 2, 2, UTIL_LCD_COLOR_BLACK);
  UTIL_LCD_DrawRect(0, 0, 2, y_size, UTIL_LCD_COLOR_BLACK);
  UTIL_LCD_DrawRect(x_size - 2, 1, 2, y_size, UTIL_LCD_COLOR_BLACK);
  UTIL_LCD_DrawRect(1, y_size - 2, x_size, 2, UTIL_LCD_COLOR_BLACK);
 //DRAW KEYS
  x_move = 0;
  y_move = 0;
  //while (y_move < 11)
  //{
    while (x_move < 11)
    {
      // draws a squear
      UTIL_LCD_FillRect(20 + (x_move * 40), 43 ,40, 2+200, UTIL_LCD_COLOR_WHITE);
      UTIL_LCD_DrawRect(20 + (x_move * 40), 43 ,40, 2+200, UTIL_LCD_COLOR_LIGHTGRAY);
      x_move++;
    }
    x_move = 0;
    while (x_move < 10)
        {
    	if(x_move != 3 && x_move!= 6){
    		UTIL_LCD_FillRect(50 + (x_move * 40), 43 ,25, 2+100, UTIL_LCD_COLOR_BLACK);
    	}
          x_move++;
        }

}

static void reDraw()
{
	clean(-1,-1);
}
static void colorWhite(int index)
{

	UTIL_LCD_FillRect(20 + (index * 40), 43 ,40, 2+200, UTIL_LCD_COLOR_LIGHTGRAY);
	if((index) != 3 && (index)!= 6 && (index)<10){
		UTIL_LCD_FillRect(50 + ((index) * 40), 43 ,25, 2+100, UTIL_LCD_COLOR_BLACK);
	}
	if((index-1) != 3 && (index-1) != 6 && (index-1)>=0){
		UTIL_LCD_FillRect(50 + ((index-1)* 40), 43 ,25, 2+100, UTIL_LCD_COLOR_BLACK);
	}

}
static void GetPosition()
{

  /* Get Touch screen position */
  BSP_TS_GetState(0, &TS_State);

  /* Read the coordinate */

  x = TS_State.TouchX;
  y = TS_State.TouchY;


  if (!TS_State.TouchDetected)
  {
	if(isPlaing == 1){
		reDraw();
		isPlaing = 0;
		colorPlay=-1;
		noteNum=-1;
	}
	HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_4); // stop generation of pwm
    return;
  }

  Px = x; Py = y;
  if ((x > 20) && (x < 460) && (y > 43) && (y < 263))
  {
	isPlaing = 1;
	if(y<140){
		x=x-50;
		x=x/40;
		clean(x,0);
		PlayBlack(x);
		if(x!=3&&x!=6 && x>=0 && x<10){
			colorPlay = 0;
			noteNum = x;
		}
		return;
	}
	x=x-20;
	x=x/40;
	clean(x,0);
	PlayWhite(x);
	colorPlay = 1;
	noteNum = x;
	return;
  }

}
static void clean(int8_t x, int col){
	if(colorPlay == -1 &&  noteNum == -1){return;}
	if(colorPlay != col ||  noteNum != x){
		if(colorPlay==0){
			UTIL_LCD_FillRect(50 + (noteNum * 40), 43 ,25, 2+100, UTIL_LCD_COLOR_BLACK);
			colorPlay=-1;
			noteNum=-1;
			return;
		}
			UTIL_LCD_FillRect(20 + (noteNum * 40), 43 ,40, 2+200, UTIL_LCD_COLOR_WHITE);
			UTIL_LCD_DrawRect(20 + (noteNum * 40), 43 ,40, 2+200, UTIL_LCD_COLOR_LIGHTGRAY);
			if((noteNum) != 3 && (noteNum)!= 6 && (noteNum)<10){
				UTIL_LCD_FillRect(50 + ((noteNum) * 40), 43 ,25, 2+100, UTIL_LCD_COLOR_BLACK);
			}
			if((noteNum-1) != 3 && (noteNum-1) != 6 && (noteNum-1)>=0){
				UTIL_LCD_FillRect(50 + ((noteNum-1)* 40), 43 ,25, 2+100, UTIL_LCD_COLOR_BLACK);
			}
			colorPlay=-1;
			noteNum=-1;
	}
}


static void PlayBlack(int8_t x){
	if(x<10 && x != 3 && x != 6)
		UTIL_LCD_FillRect(50 + (x * 40), 43 ,25, 2+100, UTIL_LCD_COLOR_ST_GRAY_LIGHT);
			int ARR_period;
			int NoteFreq;
			int Delaymsecs;
			  switch(x){
			  	 case 0:
			  		NoteFreq = NOTE_FS4;
			  		break;
			  	case 1:
			  		NoteFreq = NOTE_GS4;
			  		break;
			  	case 2:
			  		NoteFreq = NOTE_AS4;
			  		break;
			  	case 4:
			  		NoteFreq = NOTE_CS5;
			  		break;
			  	case 5:
			  		NoteFreq = NOTE_DS5;
			  		break;
			  	case 7:
			  		NoteFreq = NOTE_FS5;
			  		break;
			  	case 8:
			  		NoteFreq = NOTE_GS5;
			  		break;
			  	case 9:
			  		NoteFreq = NOTE_AS5;
			  		break;
			  	default:
			  		return;
			  }
			  			  if (NoteFreq == 0) NoteFreq = 1;

			  			  ARR_period = (int)(1000000/NoteFreq);  //Already prescaled to 1 MHz
			      		  setPWM(htim2, TIM_CHANNEL_4, ARR_period, ARR_period/2);

			  			  Delaymsecs = 150;

			  		  	  HAL_Delay(Delaymsecs);


}
static void PlayWhite(int8_t x){
	colorWhite(x);

		int ARR_period;
		int NoteFreq;
		int Delaymsecs;

		switch(x){
			case 0:
				NoteFreq = NOTE_F4;
				break;
			case 1:
				NoteFreq = NOTE_G4;
				break;
			case 2:
				NoteFreq = NOTE_A4;
				break;
			case 3:
				NoteFreq = NOTE_B4;
				break;
			case 4:
				NoteFreq = NOTE_C5;
				break;
			case 5:
				NoteFreq = NOTE_D5;
				break;
			case 6:
				NoteFreq = NOTE_E5;
				break;
			case 7:
				NoteFreq = NOTE_F5;
				break;
			case 8:
				NoteFreq = NOTE_G5;
				break;
			case 9:
				NoteFreq = NOTE_A5;
				break;
			case 10:
				NoteFreq = NOTE_B5;
				break;
			default:
				return;
			}

	  if (NoteFreq == 0) NoteFreq = 1;

	  ARR_period = (int)(1000000/NoteFreq);  //Already prescaled to 1 MHz
	  setPWM(htim2, TIM_CHANNEL_4, ARR_period, ARR_period/2);

	  Delaymsecs = 150;
  	  HAL_Delay(Delaymsecs);
}

void setPWM(TIM_HandleTypeDef timer, uint32_t channel, uint16_t period, uint16_t pulse)
{
	 HAL_TIM_PWM_Stop(&timer, channel); // stop generation of pwm
	 TIM_OC_InitTypeDef sConfigOC;
	 timer.Init.Period = period; // set the period duration
	 HAL_TIM_PWM_Init(&timer); // reinititialise with new period value
	 sConfigOC.OCMode = TIM_OCMODE_PWM1;
	 sConfigOC.Pulse = pulse; // set the pulse duration
	 sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
	 sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
	 HAL_TIM_PWM_ConfigChannel(&timer, &sConfigOC, channel);
	 HAL_TIM_PWM_Start(&timer, channel); // start pwm generation
}

void MX_TIM2_Init(void)
{
	 /* USER CODE BEGIN TIM2_Init 0 */

	  /* USER CODE END TIM2_Init 0 */

	  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
	  TIM_MasterConfigTypeDef sMasterConfig = {0};
	  TIM_OC_InitTypeDef sConfigOC = {0};

	  /* USER CODE BEGIN TIM2_Init 1 */

	  /* USER CODE END TIM2_Init 1 */
	  htim2.Instance = TIM2;
	  htim2.Init.Prescaler = 63;
	  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
	  htim2.Init.Period = 4294967295;
	  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
	  {
	    Error_Handler();
	  }
	  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
	  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
	  {
	    Error_Handler();
	  }
	  if (HAL_TIM_PWM_Init(&htim2) != HAL_OK)
	  {
	    Error_Handler();
	  }
	  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
	  {
	    Error_Handler();
	  }
	  sConfigOC.OCMode = TIM_OCMODE_PWM1;
	  sConfigOC.Pulse = 0;
	  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
	  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
	  if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_4) != HAL_OK)
	  {
	    Error_Handler();
	  }
	  /* USER CODE BEGIN TIM2_Init 2 */

	  /* USER CODE END TIM2_Init 2 */
	  HAL_TIM_MspPostInit(&htim2);


}



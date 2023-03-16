#include "sweeperMain.h"
#include "main.h"

static void Draw_Menu(void);
static void GetPosition();
static void Draw_Cvad(int8_t x, int8_t y);
static void Set_Numbers();
static void Bomb_Hit();
static void Open_empty(int8_t x, int8_t y);
static void Set_Bomb_Number();
static void Draw_flag(int8_t x, int8_t y);
static void Remove_flag(int8_t x, int8_t y);
static void Mine_Selection_Position();
static void Reset_Game();
// mape array
int8_t tab[23][11];
/**
 * nimbers in tab
 *  -1 -> hiddne bombm
 * 0 -> zero bombs around
 * 1-8 -> number of bombs around
 * 10 -> open empty tile
 * 11-18 -> opend number tile
 * 19 -> marked bomb
 * 20 -> marked(as bomb) enpty tile
 * 21-28 -> marked number tile
 */

// MARK FALH.... mark bombs
int8_t flag = 0;

// x,y position of tuch
uint16_t x = 0, y = 0;
// previous position of x,y so it dest click the same infinitly
uint16_t Px = 0, Py = 0;
// size of acreen
uint32_t x_size, y_size;

// nimber of mines left
uint16_t Mine_Num = 50;

uint16_t Tmp_Mine_Num = 0;

// game state if =0 end game
int8_t Game_State = 1;

long Time_playinf = 0;
/**
 * 0 -> game end
 * 1 -> game is playing
 * 2 -> selecting bomb amount
 */

static TS_State_t TS_State;

void sweeperMain()
{
  Game_State = 1;
  flag = 0;
  BSP_LCD_GetXSize(0, &x_size);
  BSP_LCD_GetYSize(0, &y_size);
  /*##-6- Draw the menu ######################################################*/
  Draw_Menu();

  // define time for random

  Time_playinf = HAL_GetTick();
  for (int i = 0; i < 23; i++)
  {
    for (int j = 0; j < 11; j++)
    {
      tab[i][j] = 0;
    }
  }

  int num_mine = Mine_Num;
  while (num_mine != 0)
  {
    int j = rand() % 11;
    int i = rand() % 23;
    if (tab[i][j] == 0)
    {
      num_mine--;
      tab[i][j] = -1;
    }
  }

  Set_Numbers();

  while (1)
  {
    if (Game_State == 2)
      Mine_Selection_Position();
    else if (Game_State == 1)
    {

      if ((HAL_GetTick() - Time_playinf) > 1000)
      {
        int sekind = (HAL_GetTick() - Time_playinf) / 1000;
        UTIL_LCD_SetTextColor(UTIL_LCD_COLOR_RED);
        UTIL_LCD_SetBackColor(UTIL_LCD_COLOR_BLACK);
        UTIL_LCD_SetFont(&Font16);
        char st[3];
        sprintf(st, "%3d", sekind);
        UTIL_LCD_DisplayStringAt(420, 15, (uint8_t *)st, LEFT_MODE);
        GetPosition();
      }
    }
    else if (Game_State == 0)
    {
      BSP_TS_GetState(0, &TS_State);
      x = TS_State.TouchX;
      y = TS_State.TouchY;
      if ((x > 220) && (x < 255) && (y > 7) && (y < 33))
      {

        Reset_Game();
      }
    }
    else if (Game_State == -1)
    {
      break;
    }
  }
}

/**
 * @brief  Draws the menu.
 * @param  None
 * @retval None
 */
static void Draw_Menu(void)
{
  /* Set background Layer */
  UTIL_LCD_SetLayer(0);

  /* Clear the LCD */
  UTIL_LCD_Clear(UTIL_LCD_COLOR_ST_GRAY_LIGHT);

  // border around screen
  UTIL_LCD_DrawRect(0, 0, x_size - 2, 2, UTIL_LCD_COLOR_WHITE);
  UTIL_LCD_DrawRect(0, 0, 2, y_size, UTIL_LCD_COLOR_WHITE);
  UTIL_LCD_DrawRect(x_size - 2, 1, 2, y_size, UTIL_LCD_COLOR_ST_GRAY_DARK);
  UTIL_LCD_DrawRect(1, y_size - 2, x_size, 2, UTIL_LCD_COLOR_ST_GRAY_DARK);

  // top section
  UTIL_LCD_DrawRect(8, 6, x_size - 16, 2, UTIL_LCD_COLOR_ST_GRAY_DARK);
  UTIL_LCD_DrawRect(8, 6, 2, 30, UTIL_LCD_COLOR_ST_GRAY_DARK);
  UTIL_LCD_DrawRect(x_size - 10, 6, 2, 30, UTIL_LCD_COLOR_WHITE);
  UTIL_LCD_DrawRect(8, 35, x_size - 16, 2, UTIL_LCD_COLOR_WHITE);

  // bottom section
  UTIL_LCD_DrawRect(8, 41, x_size - 16, 2, UTIL_LCD_COLOR_ST_GRAY_DARK);
  UTIL_LCD_DrawRect(8, 41, 2, y_size - 50, UTIL_LCD_COLOR_ST_GRAY_DARK);
  UTIL_LCD_DrawRect(x_size - 10, 41, 2, y_size - 50, UTIL_LCD_COLOR_WHITE);
  UTIL_LCD_DrawRect(8, y_size - 9, x_size - 16, 2, UTIL_LCD_COLOR_WHITE);

  // flag marker squear
  UTIL_LCD_DrawRect(123, 10, 2, 23, UTIL_LCD_COLOR_ST_GRAY_DARK);
  UTIL_LCD_DrawRect(100, 31, 24, 2, UTIL_LCD_COLOR_ST_GRAY_DARK);
  UTIL_LCD_DrawRect(100, 10, 25, 2, UTIL_LCD_COLOR_WHITE);
  UTIL_LCD_DrawRect(100, 10, 2, 23, UTIL_LCD_COLOR_WHITE);

  // draw flag icon
  UTIL_LCD_DrawRect(112, 15, 2, 10, UTIL_LCD_COLOR_BLACK);
  UTIL_LCD_DrawRect(107, 25, 11, 2, UTIL_LCD_COLOR_BLACK);
  UTIL_LCD_DrawRect(105, 27, 15, 2, UTIL_LCD_COLOR_BLACK);
  UTIL_LCD_FillRect(107, 15, 5, 5, UTIL_LCD_COLOR_RED);

  // squear around emojy
  UTIL_LCD_DrawRect(251, 10, 2, 23, UTIL_LCD_COLOR_ST_GRAY_DARK);
  UTIL_LCD_DrawRect(228, 31, 24, 2, UTIL_LCD_COLOR_ST_GRAY_DARK);
  UTIL_LCD_DrawRect(228, 10, 25, 2, UTIL_LCD_COLOR_WHITE);
  UTIL_LCD_DrawRect(228, 10, 2, 23, UTIL_LCD_COLOR_WHITE);

  // draws hapy emojy
  UTIL_LCD_FillCircle(240, 21, 8, UTIL_LCD_COLOR_YELLOW);
  UTIL_LCD_DrawCircle(240, 21, 8, UTIL_LCD_COLOR_BLACK);
  UTIL_LCD_DrawRect(242, 18, 2, 2, UTIL_LCD_COLOR_BLACK);
  UTIL_LCD_DrawRect(237, 18, 2, 2, UTIL_LCD_COLOR_BLACK);
  UTIL_LCD_DrawRect(237, 25, 7, 1, UTIL_LCD_COLOR_BLACK);
  UTIL_LCD_DrawRect(236, 24, 1, 1, UTIL_LCD_COLOR_BLACK);
  UTIL_LCD_DrawRect(244, 24, 1, 1, UTIL_LCD_COLOR_BLACK);
  // konec smejkota

  // number of squears 23*11
  int16_t x_move = 0, y_move = 0;
  while (y_move < 11)
  {
    while (x_move < 23)
    {
      // draws a squear
      UTIL_LCD_DrawRect(28 + (x_move * 20), 43 + (y_move * 20), 2, 18, UTIL_LCD_COLOR_ST_GRAY_DARK);
      UTIL_LCD_DrawRect(10 + (x_move * 20), 61 + (y_move * 20), 20, 2, UTIL_LCD_COLOR_ST_GRAY_DARK);
      UTIL_LCD_DrawRect(10 + (x_move * 20), 43 + (y_move * 20), 20, 2, UTIL_LCD_COLOR_WHITE);
      UTIL_LCD_DrawRect(10 + (x_move * 20), 43 + (y_move * 20), 2, 20, UTIL_LCD_COLOR_WHITE);
      x_move++;
    }
    x_move = 0;
    y_move++;
  }

  // despay the number of bombs
  UTIL_LCD_SetTextColor(UTIL_LCD_COLOR_RED);
  UTIL_LCD_SetBackColor(UTIL_LCD_COLOR_BLACK);
  UTIL_LCD_SetFont(&Font16);
  UTIL_LCD_FillRect(12, 9, 50, 25, UTIL_LCD_COLOR_BLACK);
  char st[3];
  sprintf(st, "%3d", Mine_Num);
  UTIL_LCD_DisplayStringAt(20, 15, (uint8_t *)st, LEFT_MODE);

  UTIL_LCD_FillRect(410, 9, 50, 25, UTIL_LCD_COLOR_BLACK);
}

/**
 * @brief  Sets numbers acording to the mines
 * @param  None
 * @retval None
 */
static void Set_Numbers()
{
  for (int i = 0; i < 11; i++)
  {
    for (int j = 0; j < 23; j++)
    {
      if (tab[j][i] != -1)
      {
        if (i > 0)
        {
          if (tab[j][i - 1] == -1)
            tab[j][i]++;
          if (j > 0)
          {
            if (tab[j - 1][i - 1] == -1)
              tab[j][i]++;
          }
          if (j < 22)
          {
            if (tab[j + 1][i - 1] == -1)
              tab[j][i]++;
          }
        }
        if (tab[j - 1][i] == -1 && j > 0)
          tab[j][i]++;
        if (tab[j + 1][i] == -1 && j < 22)
          tab[j][i]++;
        if (i < 10)
        {
          if (tab[j][i + 1] == -1)
            tab[j][i]++;
          if (j > 0)
          {
            if (tab[j - 1][i + 1] == -1)
              tab[j][i]++;
          }
          if (j < 22)
          {
            if (tab[j + 1][i + 1] == -1)
              tab[j][i]++;
          }
        }
      }
    }
  }
}

/**
 * @brief  When you hit a bomb/game end
 * @param  None
 * @retval None
 */
static void Bomb_Hit()
{

  Game_State = 0;
  for (int i = 0; i < 23; i++)
  {
    for (int j = 0; j < 11; j++)
    {
      if (tab[i][j] == -1)
      {
        // draws a squear
        UTIL_LCD_FillCircle(20 + (i * 20), 53 + (j * 20), 5, UTIL_LCD_COLOR_BLACK);
        UTIL_LCD_DrawRect(19 + (i * 20), 46 + (j * 20), 2, 15, UTIL_LCD_COLOR_BLACK);
        UTIL_LCD_DrawRect(13 + (i * 20), 53 + (j * 20), 14, 2, UTIL_LCD_COLOR_BLACK);

        UTIL_LCD_DrawRect(15 + (i * 20), 48 + (j * 20), 2, 2, UTIL_LCD_COLOR_BLACK);
        UTIL_LCD_DrawRect(15 + (i * 20), 57 + (j * 20), 2, 2, UTIL_LCD_COLOR_BLACK);

        UTIL_LCD_DrawRect(24 + (i * 20), 48 + (j * 20), 2, 2, UTIL_LCD_COLOR_BLACK);
        UTIL_LCD_DrawRect(24 + (i * 20), 57 + (j * 20), 2, 2, UTIL_LCD_COLOR_BLACK);

        UTIL_LCD_FillRect(18 + (i * 20), 51 + (j * 20), 2, 2, UTIL_LCD_COLOR_WHITE);
      }
    }
  }
}

/**
 * @brief  Draw the unknown squear
 * @param  None
 * @retval None
 */
static void Draw_Cvad(int8_t x_move, int8_t y_move)
{

  UTIL_LCD_DrawRect(28 + (x_move * 20), 43 + (y_move * 20), 2, 18, UTIL_LCD_COLOR_ST_GRAY_LIGHT);
  UTIL_LCD_DrawRect(10 + (x_move * 20), 61 + (y_move * 20), 20, 2, UTIL_LCD_COLOR_ST_GRAY_LIGHT);
  UTIL_LCD_DrawRect(10 + (x_move * 20), 43 + (y_move * 20), 20, 2, UTIL_LCD_COLOR_ST_GRAY_LIGHT);
  UTIL_LCD_DrawRect(10 + (x_move * 20), 43 + (y_move * 20), 2, 20, UTIL_LCD_COLOR_ST_GRAY_LIGHT);

  if (tab[x_move][y_move] > 0 && tab[x_move][y_move] < 9)
  {
    if (tab[x_move][y_move] == 1)
      UTIL_LCD_SetTextColor(UTIL_LCD_COLOR_BLUE);
    else if (tab[x_move][y_move] == 2)
      UTIL_LCD_SetTextColor(UTIL_LCD_COLOR_GREEN);
    else if (tab[x_move][y_move] == 3)
      UTIL_LCD_SetTextColor(UTIL_LCD_COLOR_RED);
    else if (tab[x_move][y_move] == 4)
      UTIL_LCD_SetTextColor(UTIL_LCD_COLOR_ST_BLUE_DARK);
    else if (tab[x_move][y_move] == 5)
      UTIL_LCD_SetTextColor(UTIL_LCD_COLOR_ST_PURPLE);
    else if (tab[x_move][y_move] == 6)
      UTIL_LCD_SetTextColor(UTIL_LCD_COLOR_ST_BLUE_LIGHT);
    else if (tab[x_move][y_move] == 7)
      UTIL_LCD_SetTextColor(UTIL_LCD_COLOR_BLACK);
    else if (tab[x_move][y_move] == 8)
      UTIL_LCD_SetTextColor(UTIL_LCD_COLOR_ST_GRAY);

    UTIL_LCD_SetBackColor(UTIL_LCD_COLOR_ST_GRAY_LIGHT);
    char st;
    sprintf(st, "%1d", tab[x_move][y_move]);
    UTIL_LCD_DisplayStringAt(15 + (x_move * 20), 47 + (y_move * 20), (uint8_t *)st, LEFT_MODE);
    tab[x_move][y_move] += 10;
  }
  UTIL_LCD_DrawRect(10 + (x_move * 20), 43 + (y_move * 20), 20, 20, UTIL_LCD_COLOR_ST_GRAY_DARK);
}

/**
 * @brief  Configures and gets Touch screen position.
 * @param  None
 * @retval None
 */
static void GetPosition()
{

  /* Get Touch screen position */
  BSP_TS_GetState(0, &TS_State);

  /* Read the coordinate */

  x = TS_State.TouchX;
  y = TS_State.TouchY;

  if (Px == x && Py == y)
  {
    return;
  }
  Px = x;
  Py = y;

  // switch flag staus
  if ((x > 90) && (x < 130) && (y > 10) && (y < 35))
  {
    if (flag == 0)
    {

      UTIL_LCD_DrawRect(123, 10, 2, 23, UTIL_LCD_COLOR_RED);
      UTIL_LCD_DrawRect(100, 31, 24, 2, UTIL_LCD_COLOR_RED);
      UTIL_LCD_DrawRect(100, 10, 25, 2, UTIL_LCD_COLOR_RED);
      UTIL_LCD_DrawRect(100, 10, 2, 23, UTIL_LCD_COLOR_RED);
      flag = 1;
    }
    else
    {
      flag = 0;
      // flag marker squear
      UTIL_LCD_DrawRect(123, 10, 2, 23, UTIL_LCD_COLOR_ST_GRAY_DARK);
      UTIL_LCD_DrawRect(100, 31, 24, 2, UTIL_LCD_COLOR_ST_GRAY_DARK);
      UTIL_LCD_DrawRect(100, 10, 25, 2, UTIL_LCD_COLOR_WHITE);
      UTIL_LCD_DrawRect(100, 10, 2, 23, UTIL_LCD_COLOR_WHITE);
    }
  }

  // number set
  if ((x > 12) && (x < 62) && (y > 9) && (y < 34))
  {
    Set_Bomb_Number();
  }

  // clicks happy face
  if ((x > 220) && (x < 255) && (y > 7) && (y < 33))
  {
    //
    Reset_Game();
  }

  // press squears
  if ((x > 10) && (x < 470) && (y > 43) && (y < 263))
  {
    x = x - 10;
    y = y - 43;
    x = x / 20;
    y = y / 20;

    if (y >= 0 && y <= 11 && x <= 23 && x >= 0)
    {
      if (flag == 1)
      {

        if (tab[x][y] < 9)
        {
          Draw_flag(x, y);
          tab[x][y] += 20;
        }
        else if (tab[x][y] >= 19)
        {
          Remove_flag(x, y);
          tab[x][y] -= 20;
        }
      }
      else
      {
        if (tab[x][y] < 10)
          Draw_Cvad(x, y);
        if (tab[x][y] == 0)
        {
          Open_empty(x, y);
        }
        else if (tab[x][y] == -1)
        {
          UTIL_LCD_FillRect(10 + (x * 20), 43 + (y * 20), 20, 20, UTIL_LCD_COLOR_RED);
          Bomb_Hit();
        }
      }
    }
  }
}

/**
 * @brief  Opens empty squears
 * @param  None
 * @retval None
 */
static void Open_empty(int8_t x, int8_t y)
{
  Draw_Cvad(x, y);
  tab[x][y] += 10;
  if (y > 0)
  {
    if (tab[x][y - 1] == 0)
      Open_empty(x, y - 1);
    else
      Draw_Cvad(x, y - 1);
    if (x > 0)
    {
      if (tab[x - 1][y - 1] == 0)
        Open_empty(x - 1, y - 1);
      else
        Draw_Cvad(x - 1, y - 1);
    }
    if (x < 22)
    {
      if (tab[x + 1][y - 1] == 0)
        Open_empty(x + 1, y - 1);
      else
        Draw_Cvad(x + 1, y - 1);
    }
  }
  if (x > 0)
  {
    if (tab[x - 1][y] == 0)
      Open_empty(x - 1, y);
    else
      Draw_Cvad(x - 1, y);
  }
  if (x < 22)
  {
    if (tab[x + 1][y] == 0)
      Open_empty(x + 1, y);
    else
      Draw_Cvad(x + 1, y);
  }
  if (y < 10)
  {
    if (tab[x][y + 1] == 0)
      Open_empty(x, y + 1);
    else
      Draw_Cvad(x, y + 1);
    if (x > 0)
    {
      if (tab[x - 1][y + 1] == 0)
        Open_empty(x - 1, y + 1);
      else
        Draw_Cvad(x - 1, y + 1);
    }
    if (x < 22)
    {
      if (tab[x + 1][y + 1] == 0)
        Open_empty(x + 1, y + 1);
      else
        Draw_Cvad(x + 1, y + 1);
    }
  }
}

/**
 * @brief  load bomb insert window
 * @param  None
 * @retval None
 */
static void Set_Bomb_Number()
{
  Game_State = 2;
  Tmp_Mine_Num = 0;

  // mine number selection section
  UTIL_LCD_FillRect(10, 41, x_size - 16, y_size - 50, UTIL_LCD_COLOR_ST_GRAY_LIGHT);
  UTIL_LCD_DrawRect(8, 41, x_size - 16, 2, UTIL_LCD_COLOR_ST_GRAY_DARK);
  UTIL_LCD_DrawRect(8, 41, 2, y_size - 50, UTIL_LCD_COLOR_ST_GRAY_DARK);
  UTIL_LCD_DrawRect(x_size - 10, 41, 2, y_size - 50, UTIL_LCD_COLOR_WHITE);
  UTIL_LCD_DrawRect(8, y_size - 9, x_size - 16, 2, UTIL_LCD_COLOR_WHITE);

  int8_t i = 1;
  UTIL_LCD_SetBackColor(UTIL_LCD_COLOR_ST_GRAY_LIGHT);
  UTIL_LCD_SetTextColor(UTIL_LCD_COLOR_BLACK);
  UTIL_LCD_SetFont(&Font24);

  char st;
  sprintf(st, "%1d", 0);
  UTIL_LCD_DisplayStringAt(170 + (1 * 55), 60 + (3 * 55), (uint8_t *)st, LEFT_MODE);

  sprintf(st, "%1d", 0);
  UTIL_LCD_DisplayStringAt(160 + (2 * 55), 60 + (3 * 55), (uint8_t *)"OK", LEFT_MODE);

  sprintf(st, "%1d", 0);
  UTIL_LCD_DisplayStringAt(152 + (0 * 55), 60 + (3 * 55), (uint8_t *)"CLR", LEFT_MODE);
  for (int8_t y = 0; y < 4; y++)
    for (int8_t x = 0; x < 3; x++)
    {
      {
        UTIL_LCD_DrawRect(203 + (x * 55), 43 + (y * 55), 2, 55, UTIL_LCD_COLOR_ST_GRAY_DARK);
        UTIL_LCD_DrawRect(150 + (x * 55), 43 + (y * 55), 55, 2, UTIL_LCD_COLOR_WHITE);
        UTIL_LCD_DrawRect(150 + (x * 55), 43 + (y * 55), 2, 55, UTIL_LCD_COLOR_WHITE);
        UTIL_LCD_DrawRect(150 + (x * 55), 96 + (y * 55), 55, 2, UTIL_LCD_COLOR_ST_GRAY_DARK);
        if (y < 3)
        {
          sprintf(st, "%1d", i++);
          UTIL_LCD_DisplayStringAt(170 + (x * 55), 60 + (y * 55), (uint8_t *)st, LEFT_MODE);
        }
      }
    }

  UTIL_LCD_FillRect(30, 125, 100, 50, UTIL_LCD_COLOR_BLACK);

  UTIL_LCD_SetFont(&Font16);
}

/**
 * @brief  draw fkag on mark
 * @param  None
 * @retval None
 */
static void Draw_flag(int8_t x, int8_t y)
{
  UTIL_LCD_DrawRect(20 + (x * 20), 47 + (y * 20), 2, 9, UTIL_LCD_COLOR_BLACK);
  UTIL_LCD_DrawRect(16 + (x * 20), 56 + (y * 20), 8, 2, UTIL_LCD_COLOR_BLACK);
  UTIL_LCD_DrawRect(14 + (x * 20), 58 + (y * 20), 12, 2, UTIL_LCD_COLOR_BLACK);
  UTIL_LCD_FillRect(16 + (x * 20), 47 + (y * 20), 4, 5, UTIL_LCD_COLOR_RED);
}
/**
 * @brief  removes flag on mark
 * @param  None
 * @retval None
 */
static void Remove_flag(int8_t x, int8_t y)
{
  UTIL_LCD_FillRect(10 + (x * 20), 43 + (y * 20), 20, 20, UTIL_LCD_COLOR_ST_GRAY_LIGHT);

  UTIL_LCD_DrawRect(28 + (x * 20), 43 + (y * 20), 2, 18, UTIL_LCD_COLOR_ST_GRAY_DARK);
  UTIL_LCD_DrawRect(10 + (x * 20), 61 + (y * 20), 20, 2, UTIL_LCD_COLOR_ST_GRAY_DARK);
  UTIL_LCD_DrawRect(10 + (x * 20), 43 + (y * 20), 20, 2, UTIL_LCD_COLOR_WHITE);
  UTIL_LCD_DrawRect(10 + (x * 20), 43 + (y * 20), 2, 20, UTIL_LCD_COLOR_WHITE);
}

/**
 * @brief  Detect the number imput
 * @param  None
 * @retval None
 */
static void Mine_Selection_Position()
{
  /* Get Touch screen position */
  BSP_TS_GetState(0, &TS_State);

  /* Read the coordinate */

  x = TS_State.TouchX;
  y = TS_State.TouchY;

  if (Px == x && Py == y)
  {
    return;
  }
  Px = x;
  Py = y;

  // clicks happy face
  if ((x > 220) && (x < 255) && (y > 7) && (y < 33))
  {
    //
    Bomb_Hit();
  }

  // number set
  if ((x > 12) && (x < 62) && (y > 9) && (y < 34))
  {
    Bomb_Hit();
  }

  if (x > 150 && x < 205)
  {
    if (y > 43 && y < 98)
    {
      Tmp_Mine_Num *= 10;
      Tmp_Mine_Num += 1;
    }
    if (y > 98 && y < 153)
    {
      Tmp_Mine_Num *= 10;
      Tmp_Mine_Num += 4;
    }
    if (y > 153 && y < 208)
    {
      Tmp_Mine_Num *= 10;
      Tmp_Mine_Num += 7;
    }
    if (y > 208 && y < 263)
    {
      Tmp_Mine_Num = 0;
      UTIL_LCD_FillRect(30, 125, 100, 50, UTIL_LCD_COLOR_BLACK);
    }
  }
  if (x > 205 && x < 260)
  {
    if (y > 43 && y < 98)
    {
      Tmp_Mine_Num *= 10;
      Tmp_Mine_Num += 2;
    }
    if (y > 98 && y < 153)
    {
      Tmp_Mine_Num *= 10;
      Tmp_Mine_Num += 5;
    }
    if (y > 153 && y < 208)
    {
      Tmp_Mine_Num *= 10;
      Tmp_Mine_Num += 8;
    }
    if (y > 208 && y < 263)
    {
      Tmp_Mine_Num *= 10;
    }
  }
  if (x > 260 && x < 315)
  {
    if (y > 43 && y < 98)
    {
      Tmp_Mine_Num *= 10;
      Tmp_Mine_Num += 3;
    }
    if (y > 98 && y < 153)
    {
      Tmp_Mine_Num *= 10;
      Tmp_Mine_Num += 6;
    }
    if (y > 153 && y < 208)
    {
      Tmp_Mine_Num *= 10;
      Tmp_Mine_Num += 9;
    }
    if (y > 208 && y < 263)
    {
      if (Tmp_Mine_Num > 252)
        Tmp_Mine_Num = 252;
      Mine_Num = Tmp_Mine_Num;
      Reset_Game();
    }
  }
  UTIL_LCD_SetBackColor(UTIL_LCD_COLOR_BLACK);
  UTIL_LCD_SetTextColor(UTIL_LCD_COLOR_RED);
  UTIL_LCD_SetFont(&Font24);
  char st;
  sprintf(st, "%1d", Tmp_Mine_Num);
  UTIL_LCD_DisplayStringAt(40, 130, (uint8_t *)st, LEFT_MODE);
}

/**
 * @brief  Resets game
 * @param  None
 * @retval None
 */
static void Reset_Game()
{
  Game_State = -1;
}

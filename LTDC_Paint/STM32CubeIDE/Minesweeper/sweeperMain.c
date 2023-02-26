#include "Minesweeper/sweeperMain.h"
#include "main.h"

static void Draw_Menu(void);
static void GetPosition();
static void Draw_Cvad(int8_t x, int8_t y);
static void Set_Numbers();
static void Bomb_Hit();
static void Open_empty(int8_t x, int8_t y);

// mape array
int8_t tab[23][11];
/**
 * nimbers in tab
 * 0 -> zero bombs around
 * 1-8 -> number of bombs around
 * -1 -> hiddne bombm
 * -2 -> marked bomb
 * -3 -> opend empty tile
 *
 */

// MARK FALH.... mark bombs
int8_t flag = 0;

// previous

// x,y position of tuch
uint16_t x = 0, y = 0;
// previous position of x,y so it dest click the same infinitly
uint16_t Px = 0, Py = 0;
// size of acreen
uint32_t x_size, y_size;

// nimber of mines left
uint16_t Mine_Num = 50;

// game state if =0 end game
int8_t Game_State = 1;

static TS_State_t TS_State;

void sweeperMain()
{

  /*##-6- Draw the menu ######################################################*/
  Draw_Menu();

  // define time for random
  time_t t;
  srand((unsigned)time(&t));

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
    /*##-7- Configure the touch screen and Get the position ##################*/
    GetPosition();
    if (Game_State == 0)
    {
      Game_State=1;
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

  UTIL_LCD_DrawRect(0, 0, x_size - 2, 2, UTIL_LCD_COLOR_WHITE);
  UTIL_LCD_DrawRect(0, 0, 2, y_size, UTIL_LCD_COLOR_WHITE);
  UTIL_LCD_DrawRect(x_size - 2, 1, 2, y_size, UTIL_LCD_COLOR_ST_GRAY_DARK);
  UTIL_LCD_DrawRect(1, y_size - 2, x_size, 2, UTIL_LCD_COLOR_ST_GRAY_DARK);

  UTIL_LCD_DrawRect(8, 6, x_size - 16, 2, UTIL_LCD_COLOR_ST_GRAY_DARK);
  UTIL_LCD_DrawRect(8, 6, 2, 30, UTIL_LCD_COLOR_ST_GRAY_DARK);
  UTIL_LCD_DrawRect(x_size - 10, 6, 2, 30, UTIL_LCD_COLOR_WHITE);
  UTIL_LCD_DrawRect(8, 35, x_size - 16, 2, UTIL_LCD_COLOR_WHITE);

  UTIL_LCD_DrawRect(8, 41, x_size - 16, 2, UTIL_LCD_COLOR_ST_GRAY_DARK);
  UTIL_LCD_DrawRect(8, 41, 2, y_size - 50, UTIL_LCD_COLOR_ST_GRAY_DARK);
  UTIL_LCD_DrawRect(x_size - 10, 41, 2, y_size - 50, UTIL_LCD_COLOR_WHITE);
  UTIL_LCD_DrawRect(8, y_size - 9, x_size - 16, 2, UTIL_LCD_COLOR_WHITE);

  UTIL_LCD_DrawRect(118, 11, 2, 18, UTIL_LCD_COLOR_ST_GRAY_DARK);
  UTIL_LCD_DrawRect(100, 29, 20, 2, UTIL_LCD_COLOR_ST_GRAY_DARK);
  UTIL_LCD_DrawRect(100, 11, 20, 2, UTIL_LCD_COLOR_WHITE);
  UTIL_LCD_DrawRect(100, 11, 2, 20, UTIL_LCD_COLOR_WHITE);

  // stevilo kvadratkov 23*11

  int16_t x_move = 0, y_move = 0;
  while (y_move < 11)
  {
    while (x_move < 23)
    {
      UTIL_LCD_DrawRect(28 + (x_move * 20), 43 + (y_move * 20), 2, 18, UTIL_LCD_COLOR_ST_GRAY_DARK);
      UTIL_LCD_DrawRect(10 + (x_move * 20), 61 + (y_move * 20), 20, 2, UTIL_LCD_COLOR_ST_GRAY_DARK);
      UTIL_LCD_DrawRect(10 + (x_move * 20), 43 + (y_move * 20), 20, 2, UTIL_LCD_COLOR_WHITE);
      UTIL_LCD_DrawRect(10 + (x_move * 20), 43 + (y_move * 20), 2, 20, UTIL_LCD_COLOR_WHITE);
      x_move++;
    }
    x_move = 0;
    y_move++;
  }
  UTIL_LCD_SetTextColor(UTIL_LCD_COLOR_RED);
  UTIL_LCD_SetBackColor(UTIL_LCD_COLOR_ST_GRAY_LIGHT);
  UTIL_LCD_SetFont(&Font8);
  UTIL_LCD_DisplayStringAt(20, 20, (uint8_t *)"ZIVO", LEFT_MODE);
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
  UTIL_LCD_DisplayStringAt(200, 20, (uint8_t *)"MRTU", LEFT_MODE);
  for (int i = 0; i < 23; i++)
  {
    for (int j = 0; j < 11; j++)
    {
      if (tab[i][j] == -1)
      {
        UTIL_LCD_DrawRect(10 + (i * 20), 43 + (j * 20), 20, 20, UTIL_LCD_COLOR_RED);
      }
      else if (tab[i][j] == -2)
      {
        UTIL_LCD_DrawRect(10 + (i * 20), 43 + (j * 20), 20, 20, UTIL_LCD_COLOR_GREEN);
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

  UTIL_LCD_DrawRect(10 + (x_move * 20), 43 + (y_move * 20), 20, 20, UTIL_LCD_COLOR_ST_GRAY_DARK);

  if (tab[x_move][y_move] > 0)
  {
    UTIL_LCD_SetTextColor(UTIL_LCD_COLOR_BLACK);
    char st;
    sprintf(st, "%1d", tab[x_move][y_move]);
    UTIL_LCD_DisplayStringAt(17 + (x_move * 20), 50 + (y_move * 20), (uint8_t *)st, LEFT_MODE);
  }
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

  if ((x > 90) && (x < 130) && (y > 5) && (y < 35))
  {
    if (flag == 0)
    {
      UTIL_LCD_DrawRect(100, 11, 20, 20, UTIL_LCD_COLOR_RED);
      flag = 1;
    }
    else
    {
      flag = 0;
      UTIL_LCD_DrawRect(118, 11, 2, 18, UTIL_LCD_COLOR_ST_GRAY_DARK);
      UTIL_LCD_DrawRect(100, 29, 20, 2, UTIL_LCD_COLOR_ST_GRAY_DARK);
      UTIL_LCD_DrawRect(100, 11, 20, 2, UTIL_LCD_COLOR_WHITE);
      UTIL_LCD_DrawRect(100, 11, 2, 20, UTIL_LCD_COLOR_WHITE);
    }
  }

  if ((x > 10) && (x < 470) && (y > 43) && (y < 263))
  {
    x = x - 10;
    y = y - 43;
    x = x / 20;
    y = y / 20;

    if (y >= 0 && y <= 11 && x <= 23 && x >= 0)
    {
      Draw_Cvad(x, y);
      if (tab[x][y] == 0)
      {
        Open_empty(x, y);
      }

      if (tab[x][y] == -1)
      {
        if (flag == 1)
        {
          UTIL_LCD_DrawRect(10 + (x * 20), 43 + (y * 20), 20, 20, UTIL_LCD_COLOR_GREEN);
          tab[x][y] = -2;
        }
        else
        {
          UTIL_LCD_DrawRect(10 + (x * 20), 43 + (y * 20), 20, 20, UTIL_LCD_COLOR_RED);
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
  tab[x][y] = -3;
  if (tab[x][y] != -1)
  {
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
    if (tab[x - 1][y] == 0 && x > 0)
      Open_empty(x - 1, y);
    else
      Draw_Cvad(x - 1, y);
    if (tab[x + 1][y] == 0 && x < 22)
      Open_empty(x + 1, y);
    else
      Draw_Cvad(x + 1, y);
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
}

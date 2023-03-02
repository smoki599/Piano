# STM32H750B-DK Minesweepwe

## Project summary
This is a project for the subject "Organizacija računalnikov". 
The goal of my project was to make a game for STM32H750B-DK using the LCD and touch screen in C/C++. I created Minesweepwe, I tried to make it similar to the original, all of the assets are made with the included library with no use of any bitmaps or images.

## How to load the program
### 1. ExtMen_Boot
The first thing to do, is get ExtMem_Boot project form [GitHub Pages](https://github.com/STMicroelectronics/STM32CubeH7/tree/master/Projects/STM32H750B-DK/Templates). This is necessary to load the game in the board, it will let you load programs to external memory and run from it. 

1. Load the program into your project manager
2. Build and load it on the board as per usual


### 2. LTDC_Paint

I created the game from an example LTDC_Paint hence why the name. The code is changed dramatically in my game but it uses the same libraries. 

1. Load the program into your project manager
2. Build the project 

You might need to select the external load when loading the project. When the Debug Configurations window opens you go under the Debugger tab and find External Loder. Pres Scan and the options should appear, select the one that has the name MT25TL01G_STM32H750B-DISCO.

## About the project

### Initialization

In the main.c ``` int main()``` function all the necessary attributes are configured and functions initialized. The LCD and Touchscreen have been initialized there which are the main way of interacting with the game. After initialization in the infinite loop the ```sweeperMain(); ``` is called to begin the game.

All code for the game is located in the Minesweeper. The ```sweeperMain.h``` is the header file. In ```sweeperMain.c``` all the code is located. In ``` sweeperMain()``` the game is initialized, all the necessary parameters are set, and the bombs are placed randomly on the map(23*11). 
The numbers around the bombs are generated using ```Set_Bomb_Number();``` function it goes and looks at every non-bomb tile and checks for all the bombs around. 
Then in the ```while(1)``` loop where we have 4 game modes. This is just to know what actions can the player make. There are 2 main modes Game mode when ```Game_State == 1``` is the time the player is playing the game. ```Game_State == 2``` is when the player is selecting the bomb amount. ```Game_State == -1``` is just to breake the infinet loop in ```sweeperMain(); ``` so it restarts. ```Game_State == 4``` is the winner screen when you successfully open all the non-bomb tiles.


### Game mechanics  
When you are playing the game there is a bomb counter in the top right of the screen that shows you how many bombs there are left. Next to it is a flag icon that indicates whether you open a tile or mark it as a bomb you can toggle between a press on the icon. When the Read border is around the icon you will mark tiles and bombs otherwise you will open it. The happy yellow face in the middle of the screen is to reset. On the right-hand side of the screen, there is a time counter so you can track how long it takes you to complete the game. 
When you open the menu for bomb selection a number pad will appear and you will be able to input the number of bombs. If you make a mistake you can clear the number with CLR button or press OK to confirm and start the game again. There is a limit of 252 bombs because of the number of tiles and a bottom limit of 1. The number of tiles isn't adjustable because the screen is a fixed size and more tiles would make it harder to hit the right one because of the size of an individual tile.
If you unlock all the tiles successfully you win to be granted a Viscory screen, you can press on the happy face to restart and play again.

### Video
A short video of the game [Video](https://www.youtube.com/watch?v=5qmvxCDKR-Q).


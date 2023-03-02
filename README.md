# STM32H750B-DK Minesweepwe

## Project summary
This is a project for subject "Organizacija računalnikov". 
The goal of my project was to make a game for STM32H750B-DK using the LCD and touch screen in C/C++. I crated Minesweepwe, I tried to make it as simmular to the origila, all of the assets are made with the included library with no use of any bitmaps or images.

## How to install 
### 1. ExtMen_Boot
First thing to do, get ExtMem_Boot project form [GitHub Pages](https://github.com/STMicroelectronics/STM32CubeH7/tree/master/Projects/STM32H750B-DK/Templates). This is necessary to load the game in the board, it will let you load programs to Cache and run the program from it. 

1. Load the program in your project manager
2. Build and load it on the board as per usual


### 2. LTDC_Paint

I created the game from an example LTDC_Paint hence why the name. The code is changed dramaticly in my game but it uses the same libraries. 

1. Load the program in your project manager
2. Build the project 
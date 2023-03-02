# How to install 
## 1. ExtMen_Boot
As a normal STM32 project load the program on your STM32H750B-DK board.

## 2. LTDC_Paint
- When mporting the project I suggest to select the STM32CubeIDE folder in LTDC_Paint folder when selecting "Open file from file system".
- Build the project as normal. If error try cleaning it and build again
- When you run the project thw window will appear go tunder debug tab and select external load
- Press scan and select the one cintaining "STM32H750-DISCO"
- Press applay and cintinue
- After the program loads successfully u may have to press the reset button on the board, you might have to do that a couple of times in my cae it usualy works in one press, but sometimes i had to pres 2-3 times


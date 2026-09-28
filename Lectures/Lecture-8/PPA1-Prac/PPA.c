#include <stdio.h>
#include "MacUILib.h"

#define XDIM 20
typedef struct 
{
    int xPos;
    char symbol;
} objPosition;



int main(void)
{

    // Initiatlize

    int i, exitFlag=1;
    char input;
    MacUILib_init();
    objPosition player = {XDIM/2, '&'};
    

    //Main Loop
    while(exitFlag==1)
    {
        //Get INput
        if(MacUILib_hasChar())
        {
            input=MacUILib_getChar();
        }


    


        //Run Logic
        switch(input)
        {

        
            //Check shutdown key 'X' - if pressed, set exitflag to 0
            case 'x':
            case 'X':
                exitFlag=0;
                break;
            // Check 'a' or 'A' - if pressed move player to left
            case 'a':
            case 'A':
                player.xPos--;
                if(player.xPos<0)
                    player.xPos=0;
                break;
            // Check 'd' or 'D' - if pressed move player to right
            case 'd':
            case 'D':
            player.xPos++;
                if(player.xPos>=XDIM)
                    player.xPos=XDIM-1;
                break;

        }

        //Draw screen
        for(i=0; i<XDIM;i++)
        {
            if(i==player.xPos)
            {
                MacUILib_printf("%c", player.symbol);
            }
            else
            {
                MacUILib_printf(".");
            }
        }

        //delay a bit...

    //uninitialize
    MacUILib_uninit();
    }


    return 0;
}
// Compile By: 
// on Windows:     gcc -DWINDOWS MacUILib.c MacUITest.c -o test 
// on Mac/Linux:   gcc -DPOSIX MacUILib.c MacUITest.c -o test 

#include "MacUILib.h"

int main(void)
{
    char input = '?'; 
    
    MacUILib_init();
    
    while(input != ' ')
    {
        MacUILib_clearScreen();
        
        if(MacUILib_hasChar())
        {
            input = MacUILib_getChar();    
        }
        
        MacUILib_printf("Current Character: %c\n", input);

        MacUILib_Delay(100000);
    }    
    
    MacUILib_uninit();
    return 0;
}
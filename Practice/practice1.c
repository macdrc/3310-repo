#include <stdlib.h>
#include <stdio.h>

int main (int argc, char** argv){

    int a = 0;
    int b = 1000;   // 0...2......1float
    int c = -1;        //0.......5...10float
    int x = 133;

    int done = 0;
    
    int c_old;

    do {
        c_old = c;
        c = (a+b)/2; // equal 5

        if (c*c == x)
            done = 1;
        else if(c*c < x)
            a = c;
        else
            b = c;

    } while (!done && c != c_old);

    return c;

    printf("%d", c);
    return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>

int main()
{
    int i, j, noframes, x, wait;
    printf("Enter the number of frames: ");
    scanf("%d", &noframes);
    i = 1;
    j = 1;
    printf("Number of frames is %d ", noframes);
    while (noframes > 0)
    {
        printf("\nSending frame : %d", i);
        x = rand() % 10; // random number between 0 to 9
        if (x % 10 == 0)
        {
            for (wait = 1;wait < 2;wait++)
            {
                printf("\nWaiting for %d seconds\n", wait);
                sleep(wait); // sleep() function is used to pause the program for a given number of seconds
            }
            printf("\nSending frame : %d\n", i);
            x = rand() % 10;
        }
        printf("\nAck for frame %d\n", j);
        noframes--;
        i++;
        j++;
    }
    printf("\nEnd of stop and wait protocol\n");
}
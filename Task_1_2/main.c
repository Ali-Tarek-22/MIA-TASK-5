#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int number;
    printf("Enter number of countdown: ");
    scanf("%i",&number);//Get number from user
    for(int i = number; i > 0; i--)
        {
            printf("%i\n",i);//Print countdown
            sleep(1);//wait 1 second
        }
    printf("Blast off to the moon!");//Missile luanched
    return 0;
}

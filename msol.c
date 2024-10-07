#include <stdio.h>

int questionM();

int main()
{
    //correct=1, incorrect=0
    int burek = questionM();
    if (burek==1)
    {
        printf("\nBravo, you picked the only valid choice of burek");
    }
    else
        printf("\nThis is the wrong choice");
    
    return 0;
}

int questionM()
{
    printf("Which burek shown bellow is the best one");
    printf("\n1. Cheese"
           "\n2. Meat"
           "\n3. Spinach");
    printf("\nBest burek: ");
    int inp=0;
    int ret=0;
    scanf("%d" ,&inp);
    switch (inp)
    {
    case 1:
        ret=0;
        break;
    case 2:
        ret=1;
        break;
    case 3:
        ret=0;
        break;
    
    default:
        printf("\nJebo ti majku choose an existing one ");
        break;
    }
    return ret;
}
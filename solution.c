#include<stdio.h>

int main () {
// correct = 1, incorrect = 0
    int input = 0; //user input varible
    int c = 0; //used for if the answer was correct
    printf ("\nWelcome to the best questions in the WORLD!!!");
    c = question_e ();
    (c == 1) ? printf ("\nCorrect!!") : printf ("\nIncorrect *womp womp*");
    c = question_d ();
    (c == 1) ? printf ("\nCorrect!!") : printf ("\nIncorrect *womp womp*");
    c = question_w ();
    (c == 1) ? printf ("\nCorrect!!") : printf ("\nIncorrect *womp womp*");
    c = questionM ();
    (c == 1) ? printf ("\nCorrect!!") : printf ("\nIncorrect *womp womp*");
}

int question_e () {
    printf ("\nWhat's your favourite colour?");
    printf ("\n1. Yellow"
            "\n2. Green"
            "\n3. Blue");
    int answer = 0;
    int correct = 0;
    scanf ("%d", &answer);
    switch (answer) {
        case 1:
        correct = 1;
            break;
        case 2:
        correct = 0;
            break;
        case 3:
        correct = 1;
            break;
        default:
            printf ("Die die die");
            break;
    }
    return correct;
};
int question_d () {
    printf ("\nWhat's the lenght of a rope?");
    printf ("\n1. Just long enough"
            "\n2. Too long"
            "\n3. Too short");
    int answer = 0;
    int correct = 0;
    scanf ("%d", &answer);
    switch (answer) {
        case 1:
        correct = 0;
            break;
        case 2:
        correct = 0;
            break;
        case 3:
        correct = 1;
            break;
        default:
            printf ("Die die die");
            break;
}
        return correct;
};
    
    
    int question_w () {
    printf ("\n What is the most common name in the world");
    printf ("\n1. bish bosh"
            "\n2. Muhammed"
            "\n3. Bob");
      int answer = 0;
    int correct = 0;
    scanf ("%d", &answer);
    switch (answer) {
        case 1:
        correct = 0;
            break;
        case 2:
        correct = 1;
            break;
        case 3:
        correct = 0;
            break;
        default:
            printf ("Die die die");
            break;
    }
        return correct;
    };
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
};
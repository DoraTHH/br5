#include<stdio.h>

int main () {
// correct = 1, incorrect = 0

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
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char* choices[] = { "Rock", "Paper", "Scissors" };
typedef enum { LOSS, TIE, WIN } Result;

int main(void) {
    int player;
    int computer;
    Result result;

    srand(time(NULL));
    
    // Get player choice
    printf("0 - Rock\n 1 - Paper\n 2 - Scissors\n");
    scanf("%d", &player);
    if (player < 0 || player > 2) {
        printf("Invalid choice!\n");
        return 1;
    }

    // Generate computer choice
    computer = rand() % 3;
    
    /* Determine winner */
    if (player == computer) {
        result = TIE;
    } else if ((player == 0 && computer == 2) || (player == 1 && computer == 0) || (player == 2 && computer == 1)) {
        result = WIN;
    } else {
        result = LOSS;
    }
    
    // Print result
    printf("You chose: %s\n", choices[player]);
    printf("Computer chose: %s\n", choices[computer]);
    switch (result) {
        case WIN:
            printf("You win!\n");
            break;

        case LOSS:
            printf("You lose!\n");
            break;

        case TIE:
            printf("It's a tie!\n");
            break;
    }
    
    return 0;
}

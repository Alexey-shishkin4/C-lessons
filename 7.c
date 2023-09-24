#include <stdio.h>
#include <assert.h>


void printMap(unsigned long player_x, unsigned long player_y, unsigned long n){
    for (unsigned long i = 0; i < n; i++){
        for (unsigned long j = 0; j < n; j++){
            if (player_x == j && player_y == i){
                printf("0_0");
                continue;
            }

            if (j == n - 1 && i == n - 1) {
                printf(" F ");
                continue;
            }

            printf(" # ");
        }
        printf("\n");
    }
}


int main(){
    unsigned long n;
    scanf("%lu", &n);
    assert(n >= 2);

    unsigned long x = 0, y = 0;
    int count = 0;
    printMap(x, y, n);
    while (1){
        int move;
        int successful_input = 0;
        scanf("%d", &move);
        if (move == 4){
            successful_input = 1;
            if (x > 0)
                x -= 1;
        }
        else if (move == 8){
            successful_input = 1;
            if (y >0)
                y -= 1;
        }
        else if (move == 5){
            successful_input = 1;
            if (y < n - 1)
                y += 1;
        }
        else if (move == 6){
            successful_input = 1;
            if (x < n - 1)
                x += 1;
        }

        if (successful_input) {
            count += 1;
            printMap(x, y, n);
        } else{
            printf("Error!");
            break;
        }

        if (x == n - 1 && y == n - 1){
            printf("END! Your score: %d", count);
            break;
        }
    }

    return 0;
}
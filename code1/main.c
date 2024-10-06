#include <stdio.h>

void findCombinations(int score) {
    int td_8pt, td_7pt, td_6pt, fg, safety;

    printf("Possible combinations of scoring plays if a team’s score is %d:\n", score);

    for (td_8pt = 0; td_8pt <= score / 8; td_8pt++) {
        for (td_7pt = 0; td_7pt <= score / 7; td_7pt++) {
            for (td_6pt = 0; td_6pt <= score / 6; td_6pt++) {
                for (fg = 0; fg <= score / 3; fg++) {
                    for (safety = 0; safety <= score / 2; safety++) {
                        if (td_8pt * 8 + td_7pt * 7 + td_6pt * 6 + fg * 3 + safety * 2 == score) {
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",
                                   td_8pt, td_7pt, td_6pt, fg, safety);
                        }
                    }
                }
            }
        }
    }
}

int main() {
    int score;

    while (1) {
        printf("Enter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");
        scanf("%d", &score);

        if (score <= 1) {
            break;  // Stop the program when a score of 1 or less is entered
        }

        findCombinations(score);
    }

    printf("Program terminated.\n");
    return 0;
}

#include <stdio.h>

int main(void) {
    int alice[3], bob[3];
    int alice_score = 0, bob_score = 0;

    for (int i = 0; i < 3; i++) {
        scanf("%d", &alice[i]);
    }

    for (int i = 0; i < 3; i++) {
        scanf("%d", &bob[i]);
    }

    for (int i = 0; i < 3; i++) {
        if (alice[i] > bob[i]) {
            alice_score++;
        } else if (alice[i] < bob[i]) {
            bob_score++;
        }
    }

    printf("%d %d\n", alice_score, bob_score);
    return 0;
}

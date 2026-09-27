#include <stdio.h>
#include <string.h>

int main(void) {
    char time[11];
    scanf("%s", time);

    int hour = (time[0] - '0') * 10 + (time[1] - '0');
    int minute = (time[3] - '0') * 10 + (time[4] - '0');
    int second = (time[6] - '0') * 10 + (time[7] - '0');

    if (time[8] == 'P' && hour != 12) {
        hour += 12;
    }

    if (time[8] == 'A' && hour == 12) {
        hour = 0;
    }

    printf("%02d:%02d:%02d\n", hour, minute, second);
    return 0;
}

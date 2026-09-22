# Time Conversion

Direct HackerRank access link:
https://www.hackerrank.com/challenges/time-conversion/problem

## Solution in C

This version parses the time string, adjusts the hour based on AM/PM, and prints it in 24-hour format.

```c
#include <stdio.h>
#include <string.h>

int main(void) {
    char time_str[20];
    scanf("%s", time_str);

    int hours, minutes, seconds;
    char suffix[3];
    sscanf(time_str, "%2d:%2d:%2d%s", &hours, &minutes, &seconds, suffix);

    if (strcmp(suffix, "AM") == 0) {
        if (hours == 12) {
            hours = 0;
        }
    } else {
        if (hours != 12) {
            hours += 12;
        }
    }

    printf("%02d:%02d:%02d\n", hours, minutes, seconds);
    return 0;
}
```

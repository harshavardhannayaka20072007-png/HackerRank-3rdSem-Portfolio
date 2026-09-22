#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* timeConversion(char* s) {
    // Extract the hour digits from the string
    int hh = (10 * (s[0] - '0')) + (s[1] - '0');
    
    // Check if it's PM or AM
    if (s[8] == 'P' && hh < 12) {
        hh += 12; // Convert afternoon hours (1-11 PM to 13-23)
    } else if (s[8] == 'A' && hh == 12) {
        hh = 0;   // Convert 12:xx:xxAM to 00:xx:xx
    }
    
    // Write the modified hour back to the start of the string
    s[0] = (char)((hh / 10) + '0');
    s[1] = (char)((hh % 10) + '0');
    
    // Terminate the string before 'AM'/'PM' to drop the suffix
    s[8] = '\0';
    
    return s;
}

int main() {
    // Read the input time string from HackerRank
    char s[15];
    if (scanf("%s", s) != 1) return 0;
    
    // Convert and print the result
    char* result = timeConversion(s);
    printf("%s\n", result);

    return 0;
}
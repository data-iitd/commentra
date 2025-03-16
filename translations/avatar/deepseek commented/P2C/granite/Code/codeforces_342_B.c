

#include <stdio.h>

int main() {
    int n, m, s, f, d, c, t, l, r, i, j, k;
    char res[100001];
    
    scanf("%d %d %d %d", &n, &m, &s, &f);  // Read values of n, m, s, and f
    
    if (s < f) {
        d = 1;  // Set direction to right (R)
        c = 'R';
    } else {
        d = -1;  // Set direction to left (L)
        c = 'L';
    }
    
    res[0] = '\0';  // Initialize an empty string to store the result
    i = 1;  // Initialize step counter
    j = s;  // Initialize current position
    k = 1;  // Initialize the current time step
    
    while (j!= f) {
        if (i > t && k < m) {  // Check if it's time to update the time step and there are more steps
            scanf("%d %d %d", &t, &l, &r);  // Read new values for t, l, and r
            k++;  // Increment the time step counter
        }
        
        if (i == t && (l <= j && j <= r || l <= j + d && j + d <= r)) {  // Check if it's the specified time step and the position is within the allowed range
            strcat(res, "X");  // Append 'X' to the result string
        } else {
            strcat(res, &c);  // Append the direction character to the result string
            j += d;  // Update the current position
        }
        i++;  // Increment the step counter
    }
    
    printf("%s", res);  // Print the result string
    
    return 0;
}

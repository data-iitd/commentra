#include <stdio.h>

void main_function() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    int current_level = 0;
    int counter = 0;
    int counter_turns = -1;

    while (counter < n) {
        counter_turns++;
        for (int i = 0; i < n; i++) {
            if (a[i] != -1 && a[i] <= counter) {
                counter++;
                a[i] = -1;
            }
        }
        
        // Reverse the array
        for (int i = 0; i < n / 2; i++) {
            int temp = a[i];
            a[i] = a[n - 1 - i];
            a[n - 1 - i] = temp;
        }
    }
    
    printf("%d\n", counter_turns);
}

int main() {
    main_function();
    return 0;
}

// <END-OF-CODE>

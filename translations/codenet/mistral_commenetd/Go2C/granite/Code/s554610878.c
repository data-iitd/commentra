
#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
    // Initialize week array with 7 days of the week
    char *week[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    // Read input string from scanner
    char s[100];
    fgets(s, sizeof(s), stdin);

    // Find index of the given day in week array
    int index = -1;
    for (int i = 0; i < 7; i++) {
        if (strcmp(s, week[i]) == 0) {
            index = i;
            break;
        }
    }

    // If the given day is not present in the week array, panic with error message
    if (index == -1) {
        panic("Invalid day of the week");
    }

    // Calculate the number of days between the given day and Sunday
    // and print the result
    int daysUntilSunday = 7 - index;
    printf("The number of days until Sunday is: %d\n", daysUntilSunday);

    return 0;
}

// Function to calculate the absolute value of a number
int abs(int num) {
    return abs(num);
}

// Function to calculate the power of a number
int pow(int base, int exp) {
    return pow(base, exp);
}

// Function to find the minimum of given numbers
int min(int num,...) {
    va_list args;
    va_start(args, num);
    int min = num;
    int next;
    while ((next = va_arg(args, int))!= 0) {
        if (next < min) {
            min = next;
        }
    }
    va_end(args);
    return min;
}

// Function to find the maximum of given numbers
int max(int num,...) {
    va_list args;
    va_start(args, num);
    int max = num;
    int next;
    while ((next = va_arg(args, int))!= 0) {
        if (next > max) {
            max = next;
        }
    }
    va_end(args);
    return max;
}

// Function to check if a string is present in a slice of strings
int strSearch(char *s, char *str) {
    int len1 = strlen(s);
    int len2 = strlen(str);
    if (len1!= len2) {
        return 0;
    }
    for (int i = 0; i < len1; i++) {
        if (s[i]!= str[i]) {
            return 0;
        }
    }
    return 1;
}

// Function to print an integer array
void printIntArray(int *array, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", array[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

// Function to calculate the modulo of a number
int calcMod(int num) {
    return num % 100000007;
}

// Function to read a single line of input as string
void getString(char *s) {
    fgets(s, 100, stdin);
    s[strlen(s) - 1] = '\0';
}

// Function to read a single line of input as integer
int getInt() {
    char s[100];
    fgets(s, sizeof(s), stdin);
    int num;
    sscanf(s, "%d", &num);
    return num;
}

// Main function
int main() {
    // Initialize week array with 7 days of the week
    char *week[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    // Read input string from scanner
    char s[100];
    getString(s);

    // Find index of the given day in week array
    int index = -1;
    for (int i = 0; i < 7; i++) {
        if (strcmp(s, week[i]) == 0) {
            index = i;
            break;
        }
    }

    // If the given day is not present in the week array, panic with error message
    if (index == -1) {
        panic("Invalid day of the week");
    }

    // Calculate the number of days between the given day and Sunday
    // and print the result
    int daysUntilSunday = 7 - index;
    printf("The number of days until Sunday is: %d\n", daysUntilSunday);

    return 0;
}

// Function to calculate the absolute value of a number
int abs(int num) {
    return abs(num);
}

// Function to calculate the power of a number
int pow(int base, int exp) {
    return pow(base, exp);
}

// Function to find the minimum of given numbers
int min(int num,...) {
    va_list args;
    va_start(args, num);
    int min = num;
    int next;
    while ((next = va_arg(args, int))!= 0) {
        if (next < min) {
            min = next;
        }
    }
    va_end(args);
    return min;
}

// Function to find the maximum of given numbers
int max(int num,...) {
    va_list args;
    va_start(args, num);
    int max = num;
    int next;
    while ((next = va_arg(args, int))!= 0) {
        if (next > max) {
            max = next;
        }
    }
    va_end(args);
    return max;
}

// Function to check if a string is present in a slice of strings
int strSearch(char *s, char *str) {
    int len1 = strlen(s);
    int len2 = strlen(str);
    if (len1!= len2) {
        return 0;
    }
    for (int i = 0; i < len1; i++) {
        if (s[i]!= str[i]) {
            return 0;
        }
    }
    return 1;
}

// Function to print an integer array
void printIntArray(int *array, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", array[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

// Function to calculate the modulo of a number
int calcMod(int num) {
    return num % 1000000007;
}

// Function to read a single line of input as string
void getString(char *s) {
    fgets(s, 100, stdin);
    s[strlen(s) - 1] = '\0';
}

// Function to read a single line of input as integer
int getInt() {
    char s[100];
    getString(s);
    int num;
    sscanf(s, "%d", &num);
    return num;
}

// Main function
int main() {
    // Initialize week array with 7 days of the week
    char *week[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    // Read input string from scanner
    char s[100];
    getString(s);

    // Find index of the given day in week array
    int index = -1;
    for (int i = 0; i < 7; i++) {
        if (week[i] == s) {
            index = i;
            break;
        }
    }

    // If the given day is not present in the week array, panic("Invalid day of the week")
    }

    // Calculate the number of days between the given day and Sunday
    int daysUntilSunday = 7 - index;
    printf("The number of days until Sunday is: %d\n", daysUntilSunday);

    return 0;
}

// Function to calculate the absolute value of a number
int abs(int num) {
    return math.Abs(float64(num))
}

// Function to calculate the power of a number
int pow(int base, int exp) {
    return int(math.Pow(float64(base), float64(exp))
}

// Function to find the minimum of given numbers
int min(int num,...) {
    va_list args;
    va_start(args, num)
    int min = num
    int next;
    for {
        next = va_arg(args, int)
        if next < min {
            min = next
        }
    }
    va_end(args)
    return min
}

// Function to find the maximum of given numbers
int max(int num,...) {
    va_list args;
    va_start(args, num)
    int max = num
    int next;
    for {
        next = va_arg(args, int)
        if next > max {
            max = next
        }
    }
    va_end(args)
    return max
}

// Function to check if a string is present in a slice of strings
bool strSearch(string s, string str) {
    int len1 = len(s)
    int len2 = len(str)
    if len1!= len2 {
        panic("Invalid day of the week")
    }

    // Calculate the modulo of a number
int calcMod(int num) {
    return num % 10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
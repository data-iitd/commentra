#include <stdio.h>

int main() {
    # Declare variables
    key = 0
    i = 0
    j = 0
    len = 0
    a = []
    
    # Read the length of the array
    scanf("%d", &len)
    
    # Read the elements of the array
    for i in range(len):
        scanf("%d", &a[i])

    # Perform insertion sort
    for j in range(1, len):
        # Print the current state of the array
        for i in range(len):
            printf(i != 0 ? " %d" : "%d", a[i])
        puts("") # Move to the next line after printing the array
        
        # Store the current element to be positioned
        key = a[j]
        
        # Shift elements of the sorted segment to the right
        for i in range(j - 1, -1, -1):
            if a[i] > key:
                a[i + 1] = a[i]
            else:
                break
        
        # Place the key in its correct position
        a[i + 1] = key

    # Print the sorted array
    for i in range(len):
        printf(i != 0 ? " %d" : "%d", a[i])
    puts("") # Move to the next line after printing the sorted array
    
    return 0 # End of the program
}

#include <stdbool.h>
#include <stdio.h>

int main() {
    int n, a[100000], cnt = 1;
    bool isup;
    bool issame = false;
    
    # Step 1: Reading Input
    scanf("%d", &n); # Read the number of elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]); # Read the elements into the array
    }
    
    # Step 2: Initialization and Condition Check
    if (a[0] < a[1])
        isup = True; # Set isup to true if the first two elements indicate an increasing trend
    else if (a[0] > a[1])
        isup = False; # Set isup to false if the first two elements indicate a decreasing trend
    else
        issame = True; # Set issame to true if the first two elements are the same
    
    # Step 3: Loop Through Elements
    for (int i = 1; i < n - 1; i++) {
        if (issame) {
            if (a[i] != a[i + 1]) {
                issame = False; # If the sequence is not consistent, reset issame and set the new trend
                if (a[i] < a[i + 1])
                    isup = True;
                else
                    isup = False;
            }
        } else {
            if (isup and a[i] <= a[i + 1]):
                ; # Continue if the current trend is increasing and the next element is greater or equal
            elif (not isup and a[i] >= a[i + 1]):
                ; # Continue if the current trend is decreasing and the next element is less or equal
            else:
                if (i + 2 < n):
                    if (a[i + 1] < a[i + 2]):
                        isup = True; # Update the trend if the next element indicates a change
                    elif (a[i + 1] > a[i + 2]):
                        isup = False;
                    else:
                        issame = True;
                    cnt += 1; # Increment the count for a new segment
                else:
                    cnt += 1; # Increment the count for the last segment
                    break;
        }
    }
    
    # Step 4: Output the Result
    print(cnt); # Print the count of segments
    return 0;
}


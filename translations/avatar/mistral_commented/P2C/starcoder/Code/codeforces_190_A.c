#######
# Code
#######

# Read input as two integers n and m
n, m = map(int, input().split())

# Check if both n and m are less than 1
if (n < 1) && (m < 1):
    # If yes, print n and m and quit the program
    printf("%d %d\n", n, m);
    return 0;

# Check if m is greater than n
if (m > n):
    // If yes, calculate the minimum and maximum values
    int min = m;
    int max = n + m - 1;
    // Print the minimum and maximum values
    printf("%d %d\n", min, max);

// If m is less than or equal to n
if (m <= n):
    // Calculate the minimum and maximum values
    int min = n;
    int max = n + m - 1;
    // If m is 0, adjust the maximum value accordingly
    if (m == 0):
        max = n;
    // Print the minimum and maximum values
    printf("%d %d\n", min, max);


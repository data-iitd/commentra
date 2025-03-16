
# Importing the Scanner class for user input
import java.util.*;

# Creating a Scanner object to read input from the console
scan = Scanner(System.in);

# Reading the number of elements in the array
n = scan.nextInt();

# Initializing an array to hold the input values
arr = [0] * n;

# Loop to read 'n' integers from the user and store them in the array
for i in range(n):
    arr[i] = scan.nextInt();

# Initialize the answer with the absolute value of the first element
answer = abs(arr[0]);

# Loop to calculate the sum of absolute differences between consecutive elements
for i in range(1, n):
    answer += abs(arr[i] - arr[i - 1]);

# Output the final calculated answer
print(answer);

# 
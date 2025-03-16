
# BufferedReader to read input from the console
import java.io.BufferedReader;

# IOException for handling input/output exceptions
import java.io.IOException;

# InputStreamReader to read input from the console
import java.io.InputStreamReader;

# Create a BufferedReader object to read input from the console
br = java.io.BufferedReader(java.io.InputStreamReader(System.in));

# Declare an integer variable 'n' to store the input number
n = 0;

# Read the input number from the console and store it in the 'n' variable
print("Enter a number: ");
n = int(br.readLine());

# Call the'solve' method to calculate and print the result
solve(n);

# Close the BufferedReader object to release the system resources
br.close();

#'solve' method to calculate and print the result
def solve(n):
    # Calculate the result and print it to the console
    print((n / 3) * 2 + (n % 3 == 0? 0 : 1));


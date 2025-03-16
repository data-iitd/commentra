# Import the 'Scanner' class for user input
import java.util.Scanner;

# Create a Scanner object to read input from the console
in = java.util.Scanner(System.in);

# Read three integers from the input: T, S, and q
T = in.nextInt(); # The upper limit
S = in.nextInt(); # The starting value
q = in.nextInt(); # The multiplier

previous = S; # Initialize 'previous' with the starting value S
answer = 0; # Initialize the answer counter

# Loop until 'previous' is less than 'T'
while (previous < T):
    answer++; # Increment the answer counter
    previous *= q; # Multiply 'previous' by 'q' for the next iteration

# Output the final count of how many times 'previous' was multiplied before reaching 'T'
System.out.println(answer);


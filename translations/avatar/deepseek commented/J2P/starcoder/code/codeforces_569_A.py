
# Import the Scanner class for reading user input
import java.util.Scanner;

# Create a Scanner object to read input
in = java.util.Scanner(System.in);

# Read the values of T, S, and q from the user input
T = in.nextInt();
S = in.nextInt();
q = in.nextInt();

# Initialize the variable `previous` with the value of S
previous = S;

# Initialize the variable `answer` with the value 0
answer = 0;

# Enter a while loop that continues until `previous` is less than T
while (previous < T):
    # Inside the loop, multiply `previous` by q and increment the `answer` by 1
    previous *= q;
    answer++;

# After the loop, print the value of `answer`
print(answer);

# 
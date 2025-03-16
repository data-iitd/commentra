# Import the Scanner class for user input
import java.util.Scanner;

# Create a Scanner object to read input from the console
in = java.util.Scanner(System.in);

# Read an integer K from the user, which represents the maximum length of the string to display
K = in.nextInt();

# Read a string S from the user
S = in.next();

# Check if the length of the string S is less than or equal to K
if (S.length() <= K):
    # If true, print the string S as it is
    print(S);
else:
    # If false, print the first K characters of S followed by "..."
    print(S.substring(0, K) + "...");

# Close the scanner to prevent resource leaks
in.close();


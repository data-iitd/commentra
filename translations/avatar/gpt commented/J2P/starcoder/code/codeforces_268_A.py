# Importing the Scanner class for user input
import java.util.*;

def main():
    # Creating a Scanner object to read input from the console
    sc = Scanner(System.in);

    # Reading the number of elements (n) from the user
    n = int(sc.nextLine());

    # Initializing a variable to store the result of matching elements
    result = 0;

    # Creating two arrays to hold the input values
    h = [0] * n; # Array to store the first set of integers
    g = [0] * n; # Array to store the second set of integers

    # Reading n integers into the first array (h)
    for i in range(n):
        h[i] = int(sc.nextInt()); # Storing input in array h

    # Reading n integers into the second array (g)
    for i in range(n):
        g[i] = int(sc.nextInt()); # Storing input in array g

    # Comparing each element of array h with each element of array g
    for i in range(n):
        for j in range(n):
            # If a match is found, increment the result counter
            if (h[i] == g[j]):
                result += 1; # Incrementing the count of matches

    # Outputting the total number of matches found
    print(result);

if __name__ == "__main__":
    main();


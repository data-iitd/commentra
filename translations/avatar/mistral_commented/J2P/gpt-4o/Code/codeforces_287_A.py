# Import the sys module for reading input
import sys

def main():
    # Create a list to store the input strings
    str_list = [None] * 4  # Define a list of length 4 to store the input strings
    i = -1  # Initialize an integer variable i to -1

    while i != 3:  # Continue as long as i is not equal to 3
        i += 1  # Increment i by 1
        str_list[i] = input()  # Read the next input string and store it in the str_list

    u = -1  # Initialize an integer variable u to -1

    while u != 2:  # Continue as long as u is not equal to 2
        u += 1  # Increment u by 1

        yes = 0  # Initialize an integer variable yes to 0
        i = -1  # Initialize an integer variable i to -1

        while i != 2:  # Continue as long as i is not equal to 2
            i += 1  # Increment i by 1

            # Compare the corresponding characters in the current and next strings
            if ((str_list[u][i] == str_list[u][i + 1] and 
                 (str_list[u + 1][i] == str_list[u][i] or str_list[u + 1][i + 1] == str_list[u][i])) or 
                (str_list[u + 1][i] == str_list[u + 1][i + 1] and 
                 (str_list[u][i] == str_list[u + 1][i] or str_list[u][i + 1] == str_list[u + 1][i]))):
                yes = 1  # Set yes to 1 if the condition is true
                print("YES")  # Print "YES"
                break  # Break out of the inner while loop

        if yes == 1:  # If yes is set to 1, break out of the outer while loop
            break

        if yes == 0:  # If yes is still 0, print "NO"
            print("NO")

if __name__ == "__main__":
    main()

# <END-OF-CODE>

# Importing the necessary classes for using input and list from the Python standard library.

def main():  # Defining the main function, which is the entry point of the program.
    n = int(input())  # Reading the first integer input n from the user.

    s = ""  # Initializing an empty string variable s to store the binary representation of the number n.

    while n > 0:  # Starting a while loop that continues as long as n is greater than zero.
        x = n % 2  # Calculating the last bit of the binary representation of n by finding the remainder of n divided by 2.
        n //= 2  # Updating the value of n by dividing it by 2 to get the next bit of the binary representation.
        s += str(x)  # Appending the calculated bit to the string s.

    ans = 0  # Initializing an integer variable ans to 0 to store the number of 1's in the binary representation of n.

    for i in range(len(s)):  # Starting a for loop that iterates through each character in the string s.
        if s[i] == '1':  # Checking if the current character is '1'.
            ans += 1  # If the character is '1', incrementing the value of ans by 1.

    print(ans)  # Printing the value of ans to the standard output stream.

if __name__ == "__main__":  # Checking if the script is being run directly.
    main()  # Calling the main function to execute the program.

# <END-OF-CODE>

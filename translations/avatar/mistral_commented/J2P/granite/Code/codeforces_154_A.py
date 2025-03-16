
import sys

def main():
    # Declaring the main function, which is the entry point of the Python application

    infile = sys.stdin
    # Creating a file object 'infile' to read input from the standard input stream

    arr = infile.readline().strip()
    # Reading the first line of input as a string and storing it in the 'arr' variable

    N = len(arr)
    # Declaring and initializing the length of the string 'arr' in the variable 'N'

    set = set()
    # Creating an empty set object to store unique strings

    K = int(infile.readline())
    # Reading the second line of input as an integer and storing it in the variable 'K'

    res = 0
    # Declaring and initializing an integer variable'res' to store the result

    for k in range(K):
        # Starting a for loop that iterates 'K' times

        input = infile.readline().strip()
        # Reading a string as input and storing it in the 'input' variable

        a = 0
        b = 0
        # Declaring and initializing two integer variables 'a' and 'b' to count the occurrences of two different characters in the string 'arr'

        for i in range(N):
            # Starting a nested for loop that iterates through each index of the string 'arr'

            if arr[i] == input[0]:
                a += 1  # Incrementing the 'a' variable if the character at the current index matches the first character of the input string
            elif arr[i] == input[1]:
                b += 1  # Incrementing the 'b' variable if the character at the current index matches the second character of the input string
            else:
                res += min(a, b)  # Adding the minimum of 'a' and 'b' to the'res' variable if the current character is different from both characters in the input string
                a = b = 0  # Resetting the 'a' and 'b' variables to zero

    res += min(a, b)  # Adding the minimum of 'a' and 'b' to the'res' variable after the end of the outer for loop

    print(res)  # Printing the final result to the standard output stream

if __name__ == "__main__":
    main()


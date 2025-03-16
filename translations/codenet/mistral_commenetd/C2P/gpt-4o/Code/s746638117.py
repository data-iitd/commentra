# Importing the standard input/output library is not necessary in Python

def main():  # The main function is the starting point of the program
    a, b = map(int, input().split())  # Reading two integers from the user and storing them in variables a and b

    ar = a * b  # Multiplying the values of variables a and b and storing the result in variable ar

    le = 2 * (a + b)  # Multiplying the sum of variables a and b by 2 and storing the result in variable le

    print(ar, le)  # Printing the values of variables ar and le to the console

if __name__ == "__main__":  # Ensuring that the main function runs when the script is executed
    main()

# <END-OF-CODE>

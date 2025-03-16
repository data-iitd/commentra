def main():
    # Reading a single line of input from the console and storing it as a String array
    str = input().split(" ")

    # Parsing the first two elements of the String array as integers 'h' and 'a' respectively
    h = int(str[0])
    a = int(str[1])

    # Initializing a variable 'num' to keep track of the number of steps
    num = 0

    # Using a while loop to simulate the given condition
    while h > 0:
        # Subtracting 'a' from 'h' in each iteration
        h = h - a

        # Incrementing the 'num' variable after each successful subtraction
        num += 1

    # Printing the final result 'num' to the console
    print(num)


# Calling the main method to execute the program
if __name__ == "__main__":
    main()

# Include the standard input/output library

def main():  # The main function is the entry point of the program
    count = [0] * 4  # Declare an array count of size 4 to store the count of each number

    # Read three pairs of numbers from the user and update the count array accordingly
    for _ in range(3):
        a, b = map(int, input().split())  # Read two numbers a and b from the user
        count[a - 1] += 1  # Increment the count of number a in the count array
        count[b - 1] += 1  # Increment the count of number b in the count array

    # Calculate the product of all counts in the count array
    s = 1
    for i in range(4):
        s *= count[i]

    # Check if the product of all counts is equal to 4
    if s == 4:
        print("YES")  # If yes, print "YES" to the console
    else:
        print("NO")  # Else, print "NO" to the console

# Call the main function to execute the program
if __name__ == "__main__":
    main()

# <END-OF-CODE>

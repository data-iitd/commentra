# Include the standard input/output library

def main():  # The entry point of the program
    n = int(input())  # Read an integer value from the standard input and store it in 'n'

    a = list(map(int, input().split()))  # Read 'n' integer values from the standard input and store them in the list 'a'

    t = 0  # Initialize the variable 't' to zero

    for i in range(n):  # Iterate through each element of the list 'a'
        s = 0  # Initialize the variable 's' to zero for summation

        for j in range(n):  # Iterate through all other elements of the list 'a'
            if j <= i:  # If the current index 'j' is less than or equal to the current index 'i', then skip the iteration
                continue

            m = a[i] * a[j]  # Multiply the current element 'a[i]' with the next element 'a[j]' and store the result in 'm'

            s += m  # Add the product 'm' to the sum 's'

        t += s  # Add the sum 's' to the total sum 't'

    print(t)  # Print the total sum 't' to the standard output

if __name__ == "__main__":
    main()  # Call the main function

# <END-OF-CODE>

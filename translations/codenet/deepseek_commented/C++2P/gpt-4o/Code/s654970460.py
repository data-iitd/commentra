# Define the main function which is the entry point of the program.
def main():
    n = int(input())  # Input the number of elements for the array.
    a = list(map(int, input().split()))  # Take 'n' integer inputs and store them in the list 'a'.
    
    print(a[-1], end='')  # Output the last element of the list 'a'.
    for i in range(1, n):  # Loop to output the remaining elements of the list 'a' in reverse order.
        print(" ", a[n-i-1], end='')  # Print each element with a leading space.
    print()  # End the line after outputting all the elements.

# Call the main function to execute the program.
if __name__ == "__main__":
    main()

# <END-OF-CODE>

import sys

def main():
    n = int(input())  # Read the number of integers
    a = []  # Create a list to store integers

    if n == 1:  # Check if there is only one integer
        print(int(input()))  # Read and print the single integer
        sys.exit(0)  # Exit the program

    for _ in range(n):  # Read n integers and add them to the list
        a.append(int(input()))

    a.sort()  # Sort the list

    if a[-1] == 0:  # Check if the largest element is 0
        print(0)  # Print 0 and exit the program
        sys.exit(0)

    ans = 0  # Initialize the result variable

    while True:  # Enter an infinite loop to process the list
        if len(a) == 1:  # Check if there is only one element left
            ans = a[0]  # Assign the single element to ans
            break  # Exit the loop
        a = func(a)  # Call the func method to update the list

    print(ans)  # Print the final result

def func(A):
    a = A[:]  # Create a copy of the input list
    min_val = 0  # Initialize the minimum variable

    i = 0
    while i < len(a):  # Iterate through the list
        if a[i] == 0:  # Remove elements that are zero
            a.remove(a[i])
        else:  # Process non-zero elements
            if min_val != 0:  # Check if min_val is not zero
                a[i] = a[i] % min_val  # Perform modulo operation
                if a[i] == 1:  # Check if the result is 1
                    print(1)  # Print 1 and exit the program
                    sys.exit(0)
            else:  # Find the minimum non-zero element
                min_val = a[i]
                i += 1  # Move to the next index
                continue
        i += 1  # Move to the next index

    a.sort()  # Sort the list
    return a  # Return the updated list

if __name__ == "__main__":
    main()

# <END-OF-CODE>

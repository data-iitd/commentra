import sys

def main():
    # Read the first integer from the input
    n = int(input())

    # Check if the input is 1, if so, print the only integer and exit the program
    if n == 1:
        print(int(input()))  # Print the only integer
        sys.exit(0)  # Exit the program

    # Initialize a list to store the integers
    a = []

    # Read the rest of the integers and add them to the list
    for _ in range(n):
        a.append(int(input()))

    # Sort the list in ascending order
    a.sort()

    # Check if the last integer in the list is 0, if so, print 0 and exit the program
    if a[-1] == 0:
        print(0)  # Print 0
        sys.exit(0)  # Exit the program

    # Initialize the answer variable
    ans = 0

    # Use a while loop to keep applying the function to the list until it contains only one element
    while True:
        if len(a) == 1:
            ans = a[0]  # Assign the only remaining integer to the answer variable
            break  # Exit the loop
        a = func(a)  # Apply the function to the list and assign the result back to it

    # Print the answer
    print(ans)

def func(A):
    a = A[:]  # Create a copy of the list to modify it without affecting the original one
    min_val = 0

    # Iterate through the list and apply the logic to each integer
    i = 0
    while i < len(a):
        if a[i] == 0:  # If the current integer is 0, remove it and decrease the index
            a.pop(i)
        else:
            if min_val != 0:  # If there is already a minimum value, apply the modulo operation
                a[i] = a[i] % min_val
                if a[i] == 1:  # If the result is 1, print 1 and exit the program
                    print(1)
                    sys.exit(0)
            else:  # If there is no minimum value yet, assign the current integer as the minimum value
                min_val = a[i]
            i += 1  # Only increment if we didn't remove an element
    # Sort the list in ascending order and return it
    a.sort()
    return a

if __name__ == "__main__":
    main()

# <END-OF-CODE>

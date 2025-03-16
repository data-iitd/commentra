def swap(a, b):
    # Function to swap two integers
    return b, a

def main():
    # Infinite loop to read two integers from the user
    while True:
        a, b = map(int, input().split())
        # Read two integers from the user and store them in 'a' and 'b' respectively

        if a == 0 and b == 0:
            break
        # If both 'a' and 'b' are zero, break out of the loop

        if b < a:
            a, b = swap(a, b)
        # If 'b' is less than 'a', swap their values

        print(a, b)
        # Print the swapped values of 'a' and 'b'

if __name__ == "__main__":
    main()
# <END-OF-CODE>

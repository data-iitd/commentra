def scan_array_int():
    return list(map(int, input().split()))  # Read a line of input and convert it to a list of integers

def main():
    arr = scan_array_int()  # Call the function to get the input array of integers
    a, b = arr[0], arr[1]  # Extract the two integers from the input array
    tap = 0                 # Initialize the tap counter
    consent = 1             # Initialize the consent level
    while consent < b:      # Loop until consent reaches or exceeds b
        consent += a - 1    # Increment consent by a - 1
        tap += 1            # Increment the tap counter
    print(tap)             # Print the number of taps needed

if __name__ == "__main__":
    main()  # Execute the main function

# <END-OF-CODE>

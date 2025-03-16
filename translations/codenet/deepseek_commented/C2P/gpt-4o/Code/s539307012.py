# Include the standard input-output library

def main():
    n, x, min_value = map(int, input().split())  # Read three integers from standard input
    x -= min_value  # Subtract the minimum value from x
    for i in range(1, n):  # Start a loop from 1 to n-1
        m = int(input())  # Read the next integer
        x -= m  # Subtract the current integer from x
        if min_value > m:  # Check if the current integer is less than the current min
            min_value = m  # Update min to the current integer if true
    print(n + x // min_value)  # Print the result

if __name__ == "__main__":
    main()  # Call the main function

# <END-OF-CODE>

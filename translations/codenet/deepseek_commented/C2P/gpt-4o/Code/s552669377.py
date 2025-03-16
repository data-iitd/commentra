# Include the standard input-output header file

def main():
    n = int(input())  # Read the number of elements
    min_val = 1000000  # Initialize min
    max_val = -1000000  # Initialize max
    total_sum = 0  # Initialize sum

    for _ in range(n):  # Loop through the number of elements
        tmp = int(input())  # Read an integer value into tmp
        if min_val > tmp: 
            min_val = tmp  # Update min if tmp is smaller
        if max_val < tmp: 
            max_val = tmp  # Update max if tmp is larger
        total_sum += tmp  # Add tmp to sum

    print(min_val, max_val, total_sum)  # Print the results

if __name__ == "__main__":
    main()  # Call the main function

# <END-OF-CODE>

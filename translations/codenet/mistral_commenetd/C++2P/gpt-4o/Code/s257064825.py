# Initialize I/O streams
def main():
    import sys
    input = sys.stdin.read

    # Read input string from standard input
    str_input = input().strip()

    # Initialize sum variable to 0
    total_sum = 0

    # Iterate through each character in the string and add its integer value to total_sum
    for x in str_input:
        total_sum += int(x)  # Convert character to integer

    # Check if total_sum is divisible by 9
    if total_sum % 9 == 0:
        print("Yes")  # Output "Yes" if total_sum is divisible by 9
    else:
        print("No")  # Output "No" otherwise

if __name__ == "__main__":
    main()

# <END-OF-CODE>

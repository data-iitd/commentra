# We import necessary modules
import sys

# Function to read input
def input_scanner():
    return sys.stdin.read().split()

# Main function
def main():
    # Read input
    data = input_scanner()
    N = int(data[0])  # Read N
    P = int(data[1])  # Read P
    S = data[2]       # Read S

    # Call check_sub_numbers function and print the result
    answer = check_sub_numbers(N, P, S)
    print(answer)

# Function to check if any subnumber of given string S is divisible by prime number P
def check_sub_numbers(N, P, S):
    if P in (2, 5):
        return check_two_or_five(N, P, S)  # Call check_two_or_five function
    else:
        return check_not_two_nor_five(N, P, S)  # Call check_not_two_nor_five function

# Function to check if any subnumber of given string S is divisible by prime number P equal to 2 or 5
def check_two_or_five(N, P, S):
    answer = 0  # Initialize answer variable as 0
    # Iterate through the string S from the last character to the first character
    for i in range(N - 1, -1, -1):
        n = int(S[i])  # Convert the substring to an integer
        if n % P == 0:  # If n is divisible by P
            answer += i + 1  # Add its index to the answer variable
    return answer

# Function to check if any subnumber of given string S is divisible by prime number P which is not equal to 2 or 5
def check_not_two_nor_five(N, P, S):
    multiplier = 1  # Initialize multiplier variable as 1
    answer = 0      # Initialize answer variable as 0
    remainder_lookup = [0] * P  # Create a list for storing the count of remainders
    prev_remainder = -1  # Initialize prev_remainder variable as -1

    # Iterate through the string S from the last character to the first character
    for i in range(N - 1, -1, -1):
        digit = int(S[i])  # Get the digit from the string S at the current index i
        if prev_remainder == -1:
            remainder = digit % P  # Get the remainder of the first digit by dividing it by P
        else:
            remainder = ((multiplier * digit) % P + prev_remainder) % P  # Calculate the new remainder

        if remainder == 0:  # If the remainder is equal to 0
            answer += 1  # Add 1 to the answer variable

        count = remainder_lookup[remainder]  # Get the count of the current remainder
        answer += count  # Add the count to the answer variable
        remainder_lookup[remainder] += 1  # Update the count of the current remainder
        prev_remainder = remainder  # Update the previous remainder
        multiplier = (multiplier * 10) % P  # Update the multiplier

    return answer

# Entry point of the program
if __name__ == "__main__":
    main()

# <END-OF-CODE>

import sys

# N: [1, 2e5]
# len(S) = N
# P: [2, 10000], prime

def main():
    # Read the integer values N and P, and the string S from input
    N, P, S = map(str, sys.stdin.read().split())
    N = int(N)
    P = int(P)
    
    # Check the sub-numbers based on the conditions and print the result
    answer = check_sub_numbers(N, P, S)
    print(answer)

# check_sub_numbers determines the method to check sub-numbers based on the value of P
def check_sub_numbers(N, P, S):
    if P in (2, 5):
        # If P is 2 or 5, use the specific check for these primes
        return check_two_or_five(N, P, S)
    else:
        # For other primes, use the general check
        return check_not_two_nor_five(N, P, S)

# check_two_or_five counts the sub-numbers divisible by 2 or 5
def check_two_or_five(N, P, S):
    answer = 0
    
    # Iterate through the string S from the end to the beginning
    for i in range(N - 1, -1, -1):
        n = int(S[i])  # Convert the character to an integer
        
        # Check if the digit is divisible by P and update the answer
        if n % P == 0:
            answer += i + 1  # Count the number of valid sub-numbers
    return answer

# check_not_two_nor_five counts the sub-numbers for primes other than 2 and 5
def check_not_two_nor_five(N, P, S):
    multiplier = 1  # Initialize the multiplier for 10^i % P
    answer = 0      # Initialize the answer counter
    remainder_lookup = [0] * P  # Array to keep track of remainders
    prev_remainder = -1  # Variable to store the previous remainder
    
    # Iterate through the string S from the end to the beginning
    for i in range(N - 1, -1, -1):
        digit = int(S[i])  # Convert the character to an integer
        
        # Calculate the current remainder based on the previous remainder
        if prev_remainder == -1:  # First digit case
            remainder = digit % P
        else:
            remainder = (multiplier * digit % P + prev_remainder) % P
        
        # If the remainder is zero, increment the answer
        if remainder == 0:
            answer += 1
        
        # Update the count of sub-numbers with the current remainder
        count = remainder_lookup[remainder]
        answer += count  # Add the count of previous occurrences of this remainder
        count += 1  # Increment the count for this remainder
        remainder_lookup[remainder] = count  # Store the updated count
        prev_remainder = remainder  # Update the previous remainder
        multiplier = (multiplier * 10) % P  # Update the multiplier for the next digit
    
    return answer

if __name__ == "__main__":
    main()

# <END-OF-CODE>

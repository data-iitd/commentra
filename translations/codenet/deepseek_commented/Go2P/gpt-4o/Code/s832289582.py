import sys

# N: [1, 2e5]
# len(S) = N
# P: [2, 10000], prime
def main():
    sc = InputScanner()  # Initialize the input scanner.
    N, P, S = sc.next_int(), sc.next_int(), sc.next_str()  # Read the values of N, P, and S from the input.
    answer = check_sub_numbers(N, P, S)  # Call the check_sub_numbers function with the read values and print the result.
    print(answer)

# check_sub_numbers determines whether P is 2 or 5 and calls the appropriate helper function.
def check_sub_numbers(N, P, S):
    if P in (2, 5):
        return check_two_or_five(N, P, S)  # If P is 2 or 5, call check_two_or_five.
    else:
        return check_not_two_nor_five(N, P, S)  # Otherwise, call check_not_two_nor_five.

# check_two_or_five iterates over the string S from the end to the beginning, checking if the last digit of each substring is divisible by P.
def check_two_or_five(N, P, S):
    answer = 0
    for i in range(N - 1, -1, -1):
        n = int(S[i])  # Convert the current character to an integer.
        if n % P == 0:  # Check if the integer is divisible by P.
            answer += i + 1  # If it is, add the position to the answer.
    return answer

# check_not_two_nor_five uses a rolling hash approach to efficiently determine the number of substrings of S that are divisible by P.
def check_not_two_nor_five(N, P, S):
    multiplier = 1  # 10^i % P
    answer = 0
    remainder_lookup = [0] * P  # Create a list to store the counts of remainders.
    prev_remainder = -1
    for i in range(N - 1, -1, -1):
        digit = int(S[i])  # Convert the current character to an integer.
        if prev_remainder == -1:  # If it's the first digit, calculate the remainder directly.
            remainder = digit % P
        else:  # Otherwise, use the rolling hash approach.
            remainder = (multiplier * digit % P + prev_remainder) % P
        if remainder == 0:  # If the remainder is 0, increment the answer.
            answer += 1
        count = remainder_lookup[remainder]  # Get the current count of this remainder.
        answer += count  # Add the count to the answer.
        count += 1  # Increment the count.
        remainder_lookup[remainder] = count  # Update the count in the list.
        prev_remainder = remainder  # Update the previous remainder.
        multiplier = (multiplier * 10) % P  # Update the multiplier for the next iteration.
    return answer

class InputScanner:
    def __init__(self):
        self.input = sys.stdin.read().split()
        self.index = 0

    def next_int(self):
        value = int(self.next_str())
        return value

    def next_str(self):
        value = self.input[self.index]
        self.index += 1
        return value

if __name__ == "__main__":
    main()

# <END-OF-CODE>

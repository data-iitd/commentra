
import sys

# N: [1, 2e5]
# len(S) = N
# P: [2, 10000], prime
def main():
    N, P, S = map(int, sys.stdin.readline().split()) # Read the values of N, P, and S from the input.
    answer = checkSubNumbers(N, P, S) # Call the checkSubNumbers function with the read values and print the result.
    print(answer)

# checkSubNumbers determines whether P is 2 or 5 and calls the appropriate helper function.
def checkSubNumbers(N, P, S):
    if P == 2 or P == 5:
        return checkTwoOrFive(N, P, S) # If P is 2 or 5, call checkTwoOrFive.
    else:
        return checkNotTwoNorFive(N, P, S) # Otherwise, call checkNotTwoNorFive.

# checkTwoOrFive iterates over the string S from the end to the beginning, checking if the last digit of each substring is divisible by P.
def checkTwoOrFive(N, P, S):
    answer = 0
    for i in range(N-1, -1, -1):
        if int(S[i]) % P == 0: # Check if the integer is divisible by P.
            answer += i + 1 # If it is, add the position to the answer.
    return answer

# checkNotTwoNorFive uses a rolling hash approach to efficiently determine the number of substrings of S that are divisible by P.
def checkNotTwoNorFive(N, P, S):
    multiplier = 1 # 10^i % P
    answer = 0
    remainderLookup = [0] * P # Create a list to store the counts of remainders.
    prevRemaider = -1
    for i in range(N-1, -1, -1):
        digit = int(S[i]) # Convert the current character to an integer.
        if prevRemaider == -1: # If it's the first digit, calculate the remainder directly.
            remainder = digit % P
        else: # Otherwise, use the rolling hash approach.
            remainder = (((multiplier * digit) % P) + prevRemaider) % P
        if remainder == 0: # If the remainder is 0, increment the answer.
            answer += 1
        count = remainderLookup[remainder] # Get the current count of this remainder.
        answer += count # Add the count to the answer.
        count += 1 # Increment the count.
        remainderLookup[remainder] = count # Update the count in the list.
        prevRemaider = remainder # Update the previous remainder.
        multiplier = (multiplier * 10) % P # Update the multiplier for the next iteration.
    return answer

if __name__ == "__main__":
    main()


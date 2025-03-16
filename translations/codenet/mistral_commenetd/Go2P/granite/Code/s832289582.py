

import sys
import math

# N: [1, 2e5] # We define N as an integer variable with the range [1, 2e5]
# len(S) = N   # The length of string S is equal to N
# P: [2, 10000], prime # We define P as an integer variable with the range [2, 10000] and prime
N, P, S = map(int, input().split()) # We read N, P, and S from the standard input using input function and convert them to integers

def checkSubNumbers(N, P, S):
    # Switch statement to check if P is equal to 2 or 5
    if P == 2 or P == 5:
        return checkTwoOrFive(N, P, S) # If P is equal to 2 or 5, we call checkTwoOrFive function
    else:
        return checkNotTwoNorFive(N, P, S) # If P is not equal to 2 or 5, we call checkNotTwoNorFive function

def checkTwoOrFive(N, P, S):
    answer = 0 # We initialize answer variable as 0
    n = 0 # We define an integer variable n
    # We iterate through the string S from the last character to the first character
    for i in range(N - 1, -1, -1):
        # We convert the substring from i to i+1 to an integer n
        n = int(S[i:i+1])
        # If n is divisible by P, we add its index to the answer variable
        if n % P == 0:
            answer += i + 1
    return answer

def checkNotTwoNorFive(N, P, S):
    multiplier = 1 # We initialize multiplier variable as 1
    answer = 0 # We initialize answer variable as 0
    # We create a slice of length P for storing the count of remainders
    remainderLookup = [0] * P
    prevRemaider = -1 # We initialize prevRemaider variable as -1
    # We iterate through the string S from the last character to the first character
    for i in range(N - 1, -1, -1):
        # We get the digit from the string S at the current index i
        digit = int(S[i])
        # If prevRemaider is equal to -1, we get the remainder of the first digit by dividing it by P
        if prevRemaider == -1:
            remainder = digit % P
        else:
            # Otherwise, we get the remainder of the current digit multiplied by multiplier and added to the previous remainder, then we get the remainder of the result by dividing it by P
            remainder = (((multiplier * digit) % P) + prevRemaider) % P
        # If the remainder is equal to 0, we add 1 to the answer variable
        if remainder == 0:
            answer += 1
        # We get the count of the current remainder from the slice remainderLookup
        count = remainderLookup[remainder]
        # We add the count to the answer variable
        answer += count
        # We update the slice remainderLookup with the new count of the current remainder
        count += 1
        remainderLookup[remainder] = count
        # We update the multiplier variable as multiplier * 10 % P
        prevRemaider = remainder
        multiplier = (multiplier * 10) % P
    return answer

answer = checkSubNumbers(N, P, S) # We call checkSubNumbers function with N, P, and S as arguments and store the result in answer variable
print(answer) # We print the answer using print function


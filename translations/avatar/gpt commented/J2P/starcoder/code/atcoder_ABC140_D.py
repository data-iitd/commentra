
# <START-OF-CODE>

import sys

def main():
    # Read the input from the console
    N, K = map(int, sys.stdin.readline().split())
    S = sys.stdin.readline().strip()

    # Initialize a flag to track changes and a count for 'R' occurrences
    flag = False
    count = 0

    # First pass: Change 'L' to 'R' up to K times
    for i in range(N):
        # If the flag is set and the current character is 'R', increment count and reset flag
        if flag and S[i] == 'R':
            flag = False
            count += 1
        # Break the loop if K changes have been made
        if count == K:
            break
        # If the current character is 'L', set the flag and change 'L' to 'R'
        if S[i] == 'L':
            flag = True
            S = S[:i] + 'R' + S[i+1:]

    # Reset flag and count for the second pass
    flag = False
    count = 0

    # Second pass: Change 'R' to 'L' up to K times
    for i in range(N):
        # If the flag is set and the current character is 'L', increment count and reset flag
        if flag and S[i] == 'L':
            flag = False
            count += 1
        # Break the loop if K changes have been made
        if count == K:
            break
        # If the current character is 'R', set the flag and change 'R' to 'L'
        if S[i] == 'R':
            flag = True
            S = S[:i] + 'L' + S[i+1:]

    # Initialize variables to count consecutive characters in S1
    count = 1
    sum1 = 0
    bef = S[0]

    # Count the number of consecutive characters in S1
    for i in range(1, N):
        if S[i] == bef:
            count += 1
            # If it's the last character, add the count to sum1
            if i == N - 1:
                sum1 += count - 1
        else:
            bef = S[i]
            sum1 += count - 1
            count = 1

    # Reset count and initialize variables to count consecutive characters in S3
    count = 1
    sum3 = 0
    bef = S[0]

    # Count the number of consecutive characters in S3
    for i in range(1, N):
        if S[i] == bef:
            count += 1
            # If it's the last character, add the count to sum3
            if i == N - 1:
                sum3 += count - 1
        else:
            bef = S[i]
            sum3 += count - 1
            count = 1

    # Output the maximum of the two sums calculated from S1 and S3
    print(max(sum1, sum3))

if __name__ == '__main__':
    main()

# 
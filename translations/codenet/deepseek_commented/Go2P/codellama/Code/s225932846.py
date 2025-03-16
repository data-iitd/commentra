
import sys

# Read a string S from the standard input
S = sys.stdin.readline().strip()

# Iterate over the string in steps of 2, starting from index 2 up to the length of the string
for i in range(2, len(S), 2):
    # Check if the substring from the start to the middle of the remaining part of the string
    # is equal to the substring from the middle of the remaining part of the string to the end
    if S[0:(len(S)-i)/2] == S[(len(S)-i)/2:len(S)-i]:
        # If a match is found, print the length of the string minus the current step size and break out of the loop
        print((len(S) - i))
        break

# 
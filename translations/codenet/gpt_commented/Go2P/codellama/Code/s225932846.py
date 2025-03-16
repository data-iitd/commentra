
# Declare a variable S to hold the input string
S = input()

# Iterate over even lengths of the string from 2 to the length of S
for i in range(2, len(S)+1, 2):
    # Check if the first half of the string (up to the current length minus i)
    # is equal to the second half of the string (from the middle to the current length minus i)
    if S[0:(len(S)-i)//2] == S[(len(S)-i)//2:len(S)-i]:
        # If they are equal, print the length of the string minus i
        # This gives the length of the string that is not part of the repeated pattern
        print((len(S) - i))
        # Exit the loop after finding the first match
        break


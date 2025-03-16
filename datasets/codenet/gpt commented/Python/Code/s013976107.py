# Read two integers A and B from input, separated by a space
A, B = map(int, input().split())

# Read a string S from input
S = list(input())

# Check if the character at index A in S is '-' and if '-' appears only once in S
if S[A] == '-' and S.count('-') == 1:
    # If both conditions are true, print "Yes"
    print("Yes")
else:
    # If either condition is false, print "No"
    print("No")

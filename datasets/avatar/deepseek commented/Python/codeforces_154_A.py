s = input()  # Taking input string s
n = int(input())  # Taking integer input n
ans = 0  # Initializing the answer variable to 0

# Loop runs n times
for _ in range(n):
    x = input()  # Taking input for string x of length 2
    a, b = 0, 0  # Initializing counters a and b to 0

    # Iterating over each character in the string s
    for j in s:
        if j == x[0]:  # Checking if the character matches the first character of x
            a += 1  # Incrementing the count for the first character
        elif j == x[1]:  # Checking if the character matches the second character of x
            b += 1  # Incrementing the count for the second character
        else:  # If the character does not match any of the two
            ans += min(a, b)  # Adding the minimum of a and b to ans
            a, b = 0, 0  # Resetting the counters a and b to 0

    ans += min(a, b)  # Adding the minimum of a and b to ans after the inner loop

print(ans)  # Printing the final answer


# Read the value of n from standard input
n = int(input())

# Loop through numbers from 1 to n
for i in range(1, n+1):
    # Check if the number is divisible by 3 or ends with 3
    if i % 3 == 0 or str(i)[-1] == '3':
        print(i, end=" ")
    else:
        # Check each digit of the number to see if it contains 3
        s = str(i)
        for j in range(len(s)-1, -1, -1):
            if s[j] == '3':
                print(i, end=" ")
                break

# Output a newline character at the end of the program
print()


# Read an integer input from the user
N = int(input())

# Define a recursive function 'aaa' that takes a string 'n'
def aaa(n):
    # Check if the integer value of 'n' exceeds the limit N
    if int(n) > N:
        return 0  # If it does, return 0 (base case)

    # Check if the digits of 'n' are exactly '7', '5', and '3'
    ans = 1 if set(str(int(n))) == {'7', '5', '3'} else 0

    # Iterate over each character in the string '753'
    for i in '753':
        # Recursively call 'aaa' with the current number 'n' concatenated with 'i'
        ans += aaa(n + i)

    # Return the accumulated answer
    return ans

# Print the result of calling 'aaa' with the initial value '0'
print(aaa('0'))

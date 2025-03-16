
N = int(input())  # Take an integer input N

# Define a function named `aaa` that takes an argument `n`
def aaa(n):
    # Check if the integer value of `n` is greater than N. If it is, return 0
    if int(n) > N:
        return 0
    
    # Check if the digits of `n` are '7', '5', and '3'. If they are, set `ans` to 1; otherwise, set `ans` to 0
    ans = 1 if set(str(int(n))) == {'7', '5', '3'} else 0
    
    # Iterate over the string '753' and recursively call the function `aaa` with `n` incremented by each digit
    for i in '753':
        ans += aaa(n + i)
    
    # Return the value of `ans`
    return ans

# Call the function `aaa` with the initial argument '0' and print the result
print(aaa('0'))


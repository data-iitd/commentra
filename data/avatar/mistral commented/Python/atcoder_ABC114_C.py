
N = int(input()) # User inputs an integer value `N`

def aaa(n): # Function definition for function `aaa` that takes an integer argument `n`
    if int(n) > N: # Check if the input integer `n` is greater than `N`
        return 0 # If it is, return 0

    ans = 1 if set(str(int(n))) == {'7', '5', '3'} else 0 # Assign a value of 1 to `ans` if the set of string representation of the integer `n` is equal to the set `{'7', '5', '3'}`; otherwise, assign it a value of 0

    for i in '753': # Iterate through each character in the string `'753'`
        ans += aaa(n + i) # Call the function recursively with the argument `n + i` and add the result to `ans`

    return ans # Return the value of `ans`

print(aaa('0')) # Call the function with argument `'0'` and print the result
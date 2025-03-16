
s = input()  # Taking an input from the user and storing it in the variable `s`.

if len(s) == 2:  # Checking if the length of the input string `s` is equal to 2.
    print(s)  # If the length is 2, it prints the string `s`.
else:  # If the length is not 2,
    print(s[::-1])  # It prints the string `s` in reverse order.


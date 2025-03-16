

n = int(input("Enter a number: ")) # Reading an integer value from the standard input and storing it in the variable `n`

if n % 1000 == 0: # Checking if the remainder of `n` when divided by 1000 is equal to 0
    print(0) # If the condition is true, we print the value 0 to the standard output
else:
    print((n // 1000 + 1) * 1000 - n) # If the condition is false, we calculate the number that is one thousand greater than the quotient of `n` when divided by 1000 and print that value to the standard output


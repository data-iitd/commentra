

n = int(input())  # Reading the integer value of n from the standard input
str = input()  # Reading the string value of the input from the standard input

l = list(str)  # Creating a list l of characters from the input string using list() method

t = 0  # Declaring and initializing an integer variable t

for i in range(n):  # Iterating through each character in the input string
    if l[i]!= '4' and l[i]!= '7':  # Checking if the current character is not equal to '4' or '7'
        t = 1  # Setting the value of t to 1 if the condition is true

if t == 1:  # Checking if the value of t is equal to 1
    print("NO")  # Printing "NO" if the condition is true
else:  # Else part of the if statement
    x = 0  # Declaring and initializing an integer variable x to store the sum of the digits in the first half of the string
    y = 0  # Declaring and initializing an integer variable y to store the sum of the digits in the second half of the string

    for i in range(n // 2):  # Iterating through the first half of the string to calculate the sum of its digits
        x += int(l[i])  # Adding the value of the current digit to the variable x

    for i in range(n // 2, n):  # Iterating through the second half of the string to calculate the sum of its digits
        y += int(l[i])  # Adding the value of the current digit to the variable y

    if x == y:  # Checking if the sum of digits in the first half is equal to the sum of digits in the second half
        print("YES")  # Printing "YES" if the condition is true
    else:  # Else part of the if statement
        print("NO")  # Printing "NO" if the condition is false


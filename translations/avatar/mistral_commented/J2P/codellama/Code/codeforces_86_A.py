
import math

def power(a):
    # Function definition for calculating the power of a number
    res = 0
    while a > 0:
        res += 1
        a = a // 10
    return res

def mult(a):
    # Function definition for calculating the product of a number with the maximum number that can be formed using its digits
    pow = power(a)
    max = 0
    for j in range(pow):
        # Loop to calculate the maximum number that can be formed using the digits of the number 'a'
        max = (max * 10) + 9
    return a * (max - a)

l = int(input())
r = int(input())

res = 0

maxxes = [0] * 10

temp = 0

for i in range(10):
    # Loop to calculate and store the maximum numbers that can be formed using each digit
    temp = (temp * 10) + 9
    maxxes[i] = (temp // 2) * (temp - (temp // 2))

res = max(mult(l), res)
res = max(mult(r), res)

temp = 0

for i in range(10):
    # Loop to check if the range between the first and second number includes the maximum number that can be formed using the 'i'th digit
    temp = (temp * 10) + 9
    if l <= temp // 2 and temp // 2 <= r:
        # Check if the range includes the maximum number that can be formed using the 'i'th digit
        res = max(maxxes[i], res)

print(res)


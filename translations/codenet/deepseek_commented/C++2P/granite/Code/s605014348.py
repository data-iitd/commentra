
import math

# Function to find the smallest divisor of a number
def div(n):
    if n % 2 == 0:
        return 2
    s = math.sqrt(n)
    for i in range(3, int(s) + 1, 2):
        if n % i == 0:
            return i
    return n

num = int(input("Enter an integer: "))
print(num, ":", end=" ")

while num!= 1:
    print(div(num), end=" ")
    num = num / div(num)

print()


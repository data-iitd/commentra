import math

def div(n):
    if n % 2 == 0:
        return 2
    s = int(math.sqrt(n))
    for i in range(3, s + 1, 2):
        if n % i == 0:
            return i
    return n

num = int(input())
print(f"{num}:", end="")

while num != 1:
    divisor = div(num)
    print(f" {divisor}", end="")
    num = num // divisor

print()  # for newline
# <END-OF-CODE>

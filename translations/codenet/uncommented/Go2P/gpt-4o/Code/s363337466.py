import math

def walk_on_multiplication_table(num):
    div = 0
    for i in range(int(math.sqrt(num)), 1, -1):
        if num % i == 0:
            div = i
            break
    if div == 0:
        return num - 1
    return div + num // div - 2

if __name__ == "__main__":
    a = int(input())
    print(walk_on_multiplication_table(a))

# <END-OF-CODE>

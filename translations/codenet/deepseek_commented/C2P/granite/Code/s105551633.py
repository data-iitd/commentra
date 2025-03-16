
import math

# Define a function to count the number of digits in a number
def digit(n):
    res = 0
    while n > 0:
        res += 1
        n //= 10
    return res

# Main logic of the program
def run():
    n = int(input())
    min_digits = digit(n)
    for i in range(1, int(math.sqrt(n)) + 1):
        if n % i!= 0:
            continue
        a = i
        b = n // i
        min_digits = min(min_digits, max(digit(a), digit(b)))
    print(min_digits)

# Main function
if __name__ == "__main__":
    run()


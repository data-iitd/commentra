import math

def main():
    n, k = map(float, input().split())

    # Calculate the number of digits in the base k representation of n.
    # The logic involves finding the smallest integer x such that k^x is less than or equal to n
    # and n is less than k^(x+1). Output x + 1 as the number of digits in the base k representation of n.

    x = 0.0
    while True:
        under = math.pow(k, x)
        upper = math.pow(k, x + 1)

        if under <= n < upper:
            print(int(x + 1))
            return
        x += 1

if __name__ == "__main__":
    main()

# <END-OF-CODE>

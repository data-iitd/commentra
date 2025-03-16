import sys

def main():
    # Read two integers N and K from standard input
    N, K = map(int, input().split())

    # Convert N to base K and print the length of the resulting string
    s = tenToN(N, K)
    print(len(s))

# Convert a decimal number to a base N string
def tenToN(number, n):
    s = ""
    tmp = number
    while True:
        s = i2s(tmp%n) + s
        if tmp < n:
            break
        tmp //= n
    return s

# Convert an integer to a string
def i2s(i):
    return str(i)

if __name__ == "__main__":
    main()


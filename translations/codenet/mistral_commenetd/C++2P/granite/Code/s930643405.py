
# Read input
n, k = map(int, input().split())

# Initialize a boolean array to keep track of digits that have been seen
d = [False] * 10

# Check each digit in the input number 'k' times
for _ in range(k):
    a = int(input())
    d[a] = True

# Keep generating numbers until a valid one is found
while True:
    x = n
    hantei = True

    # Check each digit in the number 'x'
    while x:
        # If the current digit has already been seen, then the number is not valid
        if d[x % 10]:
            hantei = False
            break
        x //= 10

    # If the current number is valid, print it and exit the loop
    if hantei:
        print(n)
        break

    # If the current number is not valid, increment 'n' and continue checking
    n += 1


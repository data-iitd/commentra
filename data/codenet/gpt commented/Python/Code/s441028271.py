# Read four integers from input and unpack them into variables a, b, c, and k
(a, b, c, k) = list(map(int, input().split()))

# Check if k is an even number
if k % 2 == 0:
    # If k is even, print the result of a minus b
    print(a - b)
else:
    # If k is odd, print the result of b minus a
    print(b - a)

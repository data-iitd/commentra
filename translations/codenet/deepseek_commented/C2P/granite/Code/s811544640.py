
a, b, c = map(int, input().split())  # Step 1: Read input values

if b > a * c:  # Step 2: Implement the if-else condition
    print(c)  # If true, print c
else:
    print(b // a)  # Otherwise, print b divided by a


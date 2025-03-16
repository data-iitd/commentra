
# Taking input for variables a, v, b, w and t
a, v = map(int, input().split())
b, w = map(int, input().split())
t = int(input())

# Checking if a is equal to b
if a == b:
    # If yes, print YES
    print('YES')
else:
    # If not, check if v is less than or equal to w
    if v <= w:
        # If yes, print NO
        print('NO')
    else:
        # If not, check if t is less than the absolute difference between a and b
        # divided by the difference between v and w
        if t < abs(a - b) / (v - w):
            # If yes, print NO
            print('NO')
        else:
            # If not, print YES
            print('YES')
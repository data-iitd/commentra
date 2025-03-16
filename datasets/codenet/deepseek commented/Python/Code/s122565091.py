a, v = map(int, input().split())  # Taking inputs a, v, b, w, and t
b, w = map(int, input().split())
t = int(input())

# Checking if a is equal to b
if a == b:
    print('YES')  # If a and b are equal, print 'YES'
elif v <= w:
    print('NO')  # If v is less than or equal to w, print 'NO'
else:
    # If v is greater than w, calculate the required time to reach from a to b
    if t < abs(a - b) / (v - w):
        print('NO')  # If the required time is greater than t, print 'NO'
    else:
        print('YES')  # If the required time is less than or equal to t, print 'YES'

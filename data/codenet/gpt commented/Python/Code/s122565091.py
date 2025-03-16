# Read the initial positions and velocities of two objects
a, v = map(int, input().split())  # a: position of object A, v: velocity of object A
b, w = map(int, input().split())  # b: position of object B, w: velocity of object B

# Read the time duration for which the objects are moving
t = int(input())  # t: time duration

# Check if both objects are at the same position
if a == b:
    print('YES')  # If they are at the same position, they will meet
elif v <= w:
    print('NO')  # If object A is slower than or equal to object B, they will never meet
else:
    # Calculate the time it would take for object A to catch up to object B
    # and check if it is within the given time duration
    if t < abs(a - b) / (v - w):
        print('NO')  # If the time required to catch up is greater than t, they won't meet
    else:
        print('YES')  # If the time required is within t, they will meet

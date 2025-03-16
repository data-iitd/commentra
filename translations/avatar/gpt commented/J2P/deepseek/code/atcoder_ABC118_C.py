import sys

def func(A):
    a = A.copy()
    min_val = 0
    i = 0
    while i < len(a):
        if a[i] == 0:
            a.pop(i)
        else:
            if min_val != 0:
                a[i] = a[i] % min_val
                if a[i] == 1:
                    print(1)
                    sys.exit(0)
            else:
                min_val = a[i]
            i += 1
    a.sort()
    return a

# Read the number of integers to be processed
n = int(input())

# Read n integers from input and store them in a list
a = list(map(int, input().split()))

# If there is only one integer, print it and exit
if n == 1:
    print(a[0])
    sys.exit(0)

# Sort the list in ascending order
a.sort()

# If the largest number is 0, print 0 and exit
if a[-1] == 0:
    print(0)
    sys.exit(0)

# Process the list until it is reduced to one element
while True:
    if len(a) == 1:
        ans = a[0]
        break
    a = func(a)

# Print the final answer
print(ans)

import sys

n, k = map(int, input().split())
a = input()

# Check if k is greater than n/2
if k > n / 2:
    # Move right until k equals n
    while k < n:
        print("RIGHT")
        k += 1
else:
    # Move left until k equals 1
    while k > 1:
        print("LEFT")
        k -= 1

# If k equals 1, print each character of the string a starting from the first character and moving rightwards
if k == 1:
    for i in range(len(a)):
        print("PRINT", a[i])
        if i + 1 < len(a):
            print("RIGHT")
else:
    # If k does not equal 1, print each character of the string a starting from the last character and moving leftwards
    for i in range(len(a) - 1, -1, -1):
        print("PRINT", a[i])
        if i - 1 >= 0:
            print("LEFT")


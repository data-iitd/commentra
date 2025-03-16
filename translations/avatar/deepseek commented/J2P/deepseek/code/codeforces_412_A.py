import sys

# Read input from the user
n = int(input().strip())
k = int(input().strip())
a = input().strip()

# Check if k is greater than n/2
if k > n // 2:
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
    for i in range(n):
        print(f"PRINT {a[i]}")
        if i < n - 1:
            print("RIGHT")

# If k does not equal 1, print each character of the string a starting from the last character and moving leftwards
else:
    for i in range(n - 1, -1, -1):
        print(f"PRINT {a[i]}")
        if i > 0:
            print("LEFT")

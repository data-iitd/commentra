
# <START-OF-CODE>

# Read the first long integer input from the user
pandu = int(input())

# Read the second long integer input from the user
vundu = int(input())

# Read the third long integer input from the user
urdu = int(input())

# The for loop iterates from 1 to urdu (inclusive)
# In each iteration, it calculates the product of i and pandu and adds it to the variable c
c = 0
for i in range(1, urdu + 1):
    c += i * pandu

# The if-else statement checks if the value of c is less than vundu
# If it is, the program prints "0". Otherwise, it prints the difference between c and vundu
if c < vundu:
    print("0")
else:
    print(c - vundu)

# 
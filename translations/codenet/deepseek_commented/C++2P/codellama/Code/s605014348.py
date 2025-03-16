#include <iostream>
#include <cmath>
using namespace std;

# Function to find the smallest divisor of a number
def div(n):
    if n % 2 == 0:
        return 2
    s = math.sqrt(n)
    for i in range(3, int(s) + 1, 2):
        if n % i == 0:
            return i

    return n


# Read an integer from the user
num = int(input("Enter a number: "))
print(num, end=":")

# Print the smallest divisor and update the number
while num != 1:
    print(" ", div(num), end="")
    num = num // div(num)

print()


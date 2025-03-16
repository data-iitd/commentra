import math

# Function to calculate the binomial coefficient C(n, m)
def C(n, m):
    res = 1
    # Calculate the binomial coefficient for n choose m
    for i in range(m - n + 1, m + 1):
        res *= i
    for i in range(1, n + 1):
        res //= i
    return res

# Main function to calculate the answer based on the given conditions
def main():
    # Read the values of n and p from standard input
    n, p = map(int, input().split())
    
    # Read the values of n elements and count the number of odd and even elements
    elements = list(map(int, input().split()))
    k0, k1 = 0, 0
    for x in elements:
        if x % 2 == 1:
            k1 += 1
        else:
            k0 += 1
    
    ans = 1
    
    # Calculate the answer based on the given conditions
    for i in range(k0):
        ans *= 2
    
    if p == 0:
        # If p is 0, calculate the answer using the given formula
        add = 0
        for i in range(0, k1 + 1, 2):
            add += C(i, k1)
        ans *= add
        print(ans)
    else:
        # If p is not 0, calculate the answer using a similar formula
        add = 0
        for i in range(1, k1 + 1, 2):
            add += C(i, k1)
        ans *= add
        print(ans)

# Call the main function
main()

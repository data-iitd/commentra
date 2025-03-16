
import sys

def power(a):
    res = 0
    # Count the number of digits by dividing the number by 10 until it becomes 0
    while a > 0:
        res += 1
        a //= 10
    return res

def mult(a):
    pow = power(a) # Get the number of digits in 'a'
    maxx = 0
    # Create the largest number with the same number of digits as 'a' (all 9s)
    for j in range(pow):
        maxx = maxx * 10 + 9
    # Return the product of 'a' and the difference between the largest number and 'a'
    return a * (maxx - a)

def main():
    l, r = map(int, input().split()) # Read the lower bound and upper bound of the range
    res = 0 # Variable to store the maximum result
    maxxes = [0] * 10 # Array to store maximum products for numbers with different digit lengths
    temp = 0

    # Precompute maximum products for numbers with up to 10 digits
    for i in range(10):
        temp = temp * 10 + 9 # Create the largest number with i+1 digits (all 9s)
        maxxes[i] = temp // 2 * (temp - temp // 2) # Calculate the maximum product for this digit length

    # Calculate the maximum product for the lower bound 'l'
    res = max(mult(l), res)
    # Calculate the maximum product for the upper bound 'r'
    res = max(mult(r), res)
    temp = 0

    # Check for numbers formed by all 9s and see if they lie within the range [l, r]
    for i in range(10):
        temp = temp * 10 + 9 # Create the largest number with i+1 digits (all 9s)
        # If the half of this number is within the range, consider its maximum product
        if l <= temp // 2 <= r:
            res = max(maxxes[i], res)

    # Output the maximum product found
    print(res)

if __name__ == "__main__":
    main()


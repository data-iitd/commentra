import math

def main():
    # Read an integer input from the user
    x = int(input())
    
    # If x is even and not equal to 2, increment x to make it odd
    if x != 2 and x % 2 == 0:
        x += 1
    
    # Infinite loop to find the next prime number
    while True:
        # Calculate the square root of x for optimization
        sqrt_num = math.sqrt(x)
        
        # Check for factors of x from 3 to the square root of x, incrementing by 2 (to check only odd numbers)
        i = 3
        while i <= sqrt_num:
            # If i divides x, then x is not prime
            if x % i == 0:
                break  # Exit the loop if a divisor is found
            i += 2
        
        # If no divisors were found, i will be greater than sqrt_num, indicating x is prime
        if i > sqrt_num:
            break  # Exit the while loop as we found a prime number
        
        # Increment x by 2 to check the next odd number
        x += 2
    
    # Output the next prime number
    print(x)

if __name__ == "__main__":
    main()

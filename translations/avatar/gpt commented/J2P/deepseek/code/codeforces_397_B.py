import sys

# Define constants for the problem
MOD = int(1e9 + 7)

def main():
    # Read the number of test cases
    t = int(input().strip())
    
    # Process each test case
    for _ in range(t):
        # Read input values for each test case
        n, a, b = map(int, input().strip().split())
        
        # Check if n is less than a, if so, output "No"
        if n < a:
            print("No")
            continue
        
        # If a equals b, check if n is a multiple of a
        if a == b:
            if n % a == 0:
                print("Yes")
            else:
                print("No")
            continue
        
        # Calculate the maximum number of a's that can fit into b
        x = b // (b - a)
        
        # If n is greater than x * a, output "Yes"
        if n > x * a:
            print("Yes")
            continue
        
        # Binary search to find the largest mid such that mid * a < n
        low, high = 1, x + 1
        ans = 1
        while low <= high:
            mid = (low + high) // 2
            
            # Adjust the search range based on the condition
            if mid * a < n:
                low = mid + 1
            else:
                ans = mid
                high = mid - 1
        
        # Check the final conditions to determine output
        if n > (ans - 1) * b and n < ans * a:
            print("No")
        else:
            print("Yes")

if __name__ == "__main__":
    main()

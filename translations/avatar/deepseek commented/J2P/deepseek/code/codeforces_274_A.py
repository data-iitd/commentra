import sys

def main():
    # Read input values
    n = int(input().strip())
    k = int(input().strip())
    arr = list(map(int, input().strip().split()))
    
    # Sort the array
    arr.sort()
    
    # Initialize count variable
    count = 0
    # Initialize a set to keep track of elements
    s = set()
    
    # Iterate through the array
    for num in arr:
        # Check if the element is not divisible by k
        if num % k != 0 and num not in s:
            count += 1
            s.add(num)
        # Check if the quotient is not in the set
        elif num % k == 0 and num // k not in s:
            count += 1
            s.add(num)
    
    # Print the result
    print(count)

if __name__ == "__main__":
    main()

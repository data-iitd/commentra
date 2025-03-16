def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])  # Read the number of elements
    d = int(data[1])  # Read the difference threshold
    nums = list(map(int, data[2:n+2]))  # Read the numbers and store them in the list
    
    result = 0  # Initialize the result variable to 0
    
    for i in range(1, n):
        a = nums[i - 1] - nums[i]  # Calculate the difference between consecutive elements
        if a >= 0:
            result += a // d + 1  # Update the result based on the difference
            nums[i] += (a // d + 1) * d  # Adjust the current element to meet the condition
    
    print(result)  # Print the final result

if __name__ == "__main__":
    main()

# <END-OF-CODE>

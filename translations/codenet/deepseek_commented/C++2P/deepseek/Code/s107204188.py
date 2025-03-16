def main():
    # Initialize the minimum value to a large number
    minA = 10**9 + 1
    # Initialize the number of ways to achieve the maximum profit
    num = 0
    
    # Read the number of elements and an unused variable 't'
    n, t = map(int, input().split())
    # Create a list to store the elements
    A = list(map(int, input().split()))
    
    # Iterate through the list to find the maximum profit
    for i in range(n):
        # Update the minimum value found so far
        if minA > A[i]:
            minA = A[i]
        else:
            # Check if the current profit is equal to the maximum profit found so far
            if num == A[i] - minA:
                num += 1
            # Update the maximum profit and reset the count if a new maximum is found
            elif num < A[i] - minA:
                num = 1
    
    # Output the number of ways to achieve the maximum profit
    print(num)

main()

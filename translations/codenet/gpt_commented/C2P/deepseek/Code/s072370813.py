def main():
    # Read the number of elements from user input
    N = int(input())
    
    # Read the elements into array A and calculate the total sum and weighted sum
    A = list(map(int, input().split()))
    total_sum = sum(A)
    weighted_sum = sum(i + 1 for i in range(N))
    
    # Check if the total sum is divisible by the weighted sum
    if total_sum % weighted_sum != 0:
        print("NO")
        return
    
    # Calculate the average value (shou)
    average = total_sum // weighted_sum
    
    # Calculate the adjusted differences and store them in array sa
    sa = [(A[(i + 1) % N] - A[i] - average) for i in range(N)]
    
    # Check the conditions for the adjusted differences
    for s in sa[:-1]:
        # If the adjusted difference is non-positive and divisible by N
        if s <= 0 and s % N == 0:
            continue
        else:
            print("NO")
            return
    
    # Output the final result based on the answer
    print("YES")

# Call the main function
main()

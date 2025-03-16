def possible(N, A):
    # Calculate the sum of all elements in the array A
    total_sum = sum(A)
    
    # Calculate the expected sum NS based on the formula for the sum of the first N natural numbers
    NS = N * (N + 1) // 2
    
    # Check if the total sum is divisible by NS; if not, return False
    if total_sum % NS != 0:
        return False
    
    # Calculate the value of K which is the target average
    K = total_sum // NS
    
    # Verify the condition for each element in the array
    for i in range(N):
        # Determine the previous index in a circular manner
        j = (i - 1) % N
        
        # Calculate the difference d needed to satisfy the condition
        d = K - (A[i] - A[j])
        
        # If d is negative or not divisible by N, return False
        if d < 0 or d % N != 0:
            return False
    
    # If all conditions are satisfied, return True
    return True

# Main function to read input and print the result
def main():
    # Read the number of elements N
    N = int(input())
    
    # Read the array A with N integers from user input
    A = list(map(int, input().split()))
    
    # Check if it is possible to achieve the desired condition with the array A
    if possible(N, A):
        # If possible, print "YES"
        print("YES")
    else:
        # If not possible, print "NO"
        print("NO")

# Call the main function
if __name__ == "__main__":
    main()

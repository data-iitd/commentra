def main():
    N = int(input())  # Read the value of N from the standard input
    
    sum = 0  # Initialize sum to store the sum of elements
    wa = 0  # Initialize wa to store the weighted sum
    A = []  # Declare a list A to store the elements
    
    # Use a for loop to read the elements of the array A and calculate the sum and wa
    for i in range(N):
        element = int(input())  # Read the elements of the array A
        A.append(element)  # Add the current element to A
        sum += A[i]  # Add the current element to sum
        wa += i + 1  # Add the current index + 1 to wa
    
    # Initialize ans and shou
    ans = 0
    shou = 0
    
    # Check if the sum is divisible by wa
    if sum % wa != 0:
        ans = 0  # If not, set ans to 0
    else:
        shou = sum // wa  # Calculate the quotient shou
        sa = []  # Declare a list sa to store the differences between consecutive elements
        
        # Calculate the differences between consecutive elements and store them in the list sa
        for i in range(N):
            sa.append(A[(i + 1) % N] - A[i] - shou)
        
        # Check if all differences are less than or equal to 0 and divisible by N
        for i in range(N - 1):
            if sa[i] <= 0 and sa[i] % N == 0:
                ans = 1  # If so, set ans to 1
            else:
                ans = 0  # Otherwise, set ans to 0 and break the loop
                break
    
    # Print "YES" if ans is 1, otherwise print "NO"
    if ans:
        print("YES")
    else:
        print("NO")

if __name__ == "__main__":
    main()  # Call the main function

# <END-OF-CODE>

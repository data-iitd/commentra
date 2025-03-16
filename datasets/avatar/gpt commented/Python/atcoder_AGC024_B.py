def main():
    # Read the number of elements from user input
    N = int(input())
    
    # Read N integers from user input and store them in a list P
    P = [int(input()) for _ in range(N)]
    
    # Call the editorial function to process the input
    editorial(N, P)

def editorial(N, P):
    # If there is only one element, the answer is 0 (no removals needed)
    if N == 1:
        print(0)
        return
    
    # Create an array to store the positions of elements in P
    a = [0] * (N + 1)
    
    # Fill the array 'a' with the indices of the elements in P
    for i, p in enumerate(P):
        a[p] = i
    
    # Initialize temporary length and maximum length variables
    tmp = 1
    max_len = 1
    
    # Iterate through the array to find the longest increasing subsequence
    for i in range(1, N):
        if a[i] < a[i + 1]:
            tmp += 1  # Increase the temporary length if the sequence is increasing
            max_len = max(max_len, tmp)  # Update the maximum length found
        else:
            tmp = 1  # Reset temporary length if the sequence is not increasing
    
    # Calculate the answer as the total elements minus the length of the longest subsequence
    ans = N - max_len
    print(ans)

def WA(N, P):
    # Initialize temporary length and answer variables
    tmp = 0
    ans = 0
    
    # Iterate through the list P to find the longest consecutive subsequence
    for i, p in enumerate(P):
        # Check if the current element is consecutive to the previous one
        if i == 0 or P[i - 1] + 1 == p:
            tmp += 1  # Increase temporary length for consecutive elements
        else:
            ans = max(ans, tmp)  # Update the answer with the maximum found
            tmp = 1  # Reset temporary length for a new sequence
    
    # Print the result as the total elements minus the longest consecutive subsequence
    print(N - ans)

# Entry point of the program
if __name__ == '__main__':
    main()

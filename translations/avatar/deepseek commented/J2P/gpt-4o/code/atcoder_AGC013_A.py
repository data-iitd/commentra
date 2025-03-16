def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    N = int(data[0])  # Step 1: Read the input value N
    A = list(map(int, data[1:N+1]))  # Step 2: Read the elements of the array A
    
    count = 0  # Step 3: Initialize a counter 'count' to zero
    i = 0
    
    while i < N:
        if i == N - 1:
            count += 1  # Step 5: Check if the current index i is the last index
            break
        elif A[i] == A[i + 1]:
            i += 1  # Move to the next index if the current element is equal to the next element
        elif A[i] < A[i + 1]:
            while i < N - 1 and A[i] <= A[i + 1]:
                i += 1
            count += 1  # Step 7: Increment the counter 'count' after each segment
        else:
            while i < N - 1 and A[i] >= A[i + 1]:
                i += 1
            count += 1  # Step 8: Increment the counter 'count' after each segment
    
    print(count)  # Step 9: Print the value of the counter 'count'

if __name__ == "__main__":
    main()

# <END-OF-CODE>

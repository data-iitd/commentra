from collections import deque

def main():
    # Read the number of elements in the array
    N = int(input())
    
    # Initialize a list to hold the input values
    a = list(map(int, input().split()))
    
    # Lists to hold the counts of elements to the left and right of each element
    leftl = [0] * N
    rightl = [0] * N
    
    # Deque to help with calculating the left and right counts
    que = deque()
    
    # Calculate the right counts for each element
    index = 0
    while index < N:
        # While the deque is not empty and the current element is smaller than the element at the index at the front of the deque
        while que and a[que[0]] > a[index]:
            # Pop the index from the deque and calculate the right count
            ind = que.popleft()
            rightl[ind] = index - ind - 1
        # Push the current index onto the deque
        que.appendleft(index)
        index += 1
    
    # For any remaining indices in the deque, calculate the right counts
    while que:
        ind = que.popleft()
        rightl[ind] = N - ind - 1
    
    # Reset index to calculate left counts
    index = N - 1
    
    # Calculate the left counts for each element
    while index >= 0:
        # While the deque is not empty and the current element is smaller than the element at the index at the front of the deque
        while que and a[que[0]] > a[index]:
            # Pop the index from the deque and calculate the left count
            ind = que.popleft()
            leftl[ind] = ind - index - 1
        # Push the current index onto the deque
        que.appendleft(index)
        index -= 1
    
    # For any remaining indices in the deque, calculate the left counts
    while que:
        ind = que.popleft()
        leftl[ind] = ind - index - 1
    
    # Calculate the final answer based on the left and right counts
    ans = 0
    for i in range(N):
        # For each element, multiply its value by the number of valid subarrays it can form
        ans += a[i] * (leftl[i] + 1) * (rightl[i] + 1)
    
    # Output the final result
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>

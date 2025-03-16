import sys

def main():
    # Read the number of elements in the array
    N = int(input())
    
    # Initialize an array to hold the input values
    a = [0] * N
    
    # Populate the array with input values
    for i in range(N):
        a[i] = int(input())
    
    # Arrays to hold the counts of elements to the left and right of each element
    leftl = [0] * N
    rightl = [0] * N
    
    # Deque to help with calculating the left and right counts
    que = []
    
    # Calculate the right counts for each element
    index = 0
    while index < N:
        # While the deque is not empty and the current element is smaller than the element at the index at the front of the deque
        while que and a[que[-1]] > a[index]:
            # Pop the index from the deque and calculate the right count
            ind = que.pop()
            rightl[ind] = index - ind - 1
        # Push the current index onto the deque
        que.append(index)
        index += 1
    
    # For any remaining indices in the deque, calculate the right counts
    while que:
        ind = que.pop()
        rightl[ind] = N - ind - 1
    
    # Reset index to calculate left counts
    index = N - 1
    
    # Calculate the left counts for each element
    while index >= 0:
        # While the deque is not empty and the current element is smaller than the element at the index at the front of the deque
        while que and a[que[-1]] > a[index]:
            # Pop the index from the deque and calculate the left count
            ind = que.pop()
            leftl[ind] = ind - index - 1
        # Push the current index onto the deque
        que.append(index)
        index -= 1
    
    # For any remaining indices in the deque, calculate the left counts
    while que:
        ind = que.pop()
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


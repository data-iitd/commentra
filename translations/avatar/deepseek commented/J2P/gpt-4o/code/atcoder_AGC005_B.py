from collections import deque  # Importing deque from collections for using deque
import sys  # Importing sys for reading input

def main():
    input = sys.stdin.read  # Reading all input at once
    data = input().split()  # Splitting the input into a list of strings
    N = int(data[0])  # Reading the number of elements N
    a = list(map(int, data[1:N+1]))  # Reading N elements and storing them in the list a
    
    # Initializing lists to store the distances to the nearest smaller elements
    leftl = [0] * N
    rightl = [0] * N
    
    # Using a deque to find the nearest smaller element to the right
    que = deque()
    index = 0
    while index < N:
        while que and a[que[-1]] > a[index]:
            ind = que.pop()
            rightl[ind] = index - ind - 1  # Calculating the distance
        que.append(index)  # Adding the current index to the deque
        index += 1
    while que:
        ind = que.pop()
        rightl[ind] = N - ind - 1  # Calculating the distance for remaining elements
    
    # Using a deque to find the nearest smaller element to the left
    index = N - 1
    while index >= 0:
        while que and a[que[-1]] > a[index]:
            ind = que.pop()
            leftl[ind] = ind - index - 1  # Calculating the distance
        que.append(index)  # Adding the current index to the deque
        index -= 1
    while que:
        ind = que.pop()
        leftl[ind] = ind - index - 1  # Calculating the distance for remaining elements
    
    # Calculating the result by summing up the products
    ans = 0
    for i in range(N):
        ans += a[i] * (leftl[i] + 1) * (rightl[i] + 1)
    
    # Printing the result
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>

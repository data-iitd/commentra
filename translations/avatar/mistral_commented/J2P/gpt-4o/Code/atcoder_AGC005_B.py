from collections import deque  # Importing deque for implementing a double-ended queue
import sys  # Importing sys for reading input

def main():
    input = sys.stdin.read  # Reading all input at once
    data = input().split()  # Splitting the input into a list of strings
    N = int(data[0])  # Reading the number of elements in the array
    a = list(map(int, data[1:N+1]))  # Creating a list of integers from the input

    leftl = [0] * N  # Creating a list to store the length of the left segment for each element
    rightl = [0] * N  # Creating a list to store the length of the right segment for each element
    que = deque()  # Creating a deque object to implement a double-ended queue
    index = 0  # Initializing the index variable to traverse the array

    # Finding the length of the left and right segments for each element using two stacks
    while index < N:
        while que and a[que[-1]] > a[index]:  # Popping the elements from the queue whose right segment length is to be calculated
            ind = que.pop()  # Storing the index of the popped element
            rightl[ind] = index - ind - 1  # Calculating the length of the right segment for the popped element
        que.append(index)  # Pushing the current index into the queue
        index += 1  # Incrementing the index

    # Calculating the length of the right segment for the last element
    while que:
        ind = que.pop()
        rightl[ind] = N - ind - 1

    index = N - 1  # Initializing the index variable to traverse the array in reverse order

    # Finding the length of the left segments for each element using two stacks in reverse order
    while index >= 0:
        while que and a[que[-1]] > a[index]:  # Popping the elements from the queue whose left segment length is to be calculated
            ind = que.pop()
            leftl[ind] = ind - index - 1  # Calculating the length of the left segment for the popped element
        que.append(index)  # Pushing the current index into the queue
        index -= 1  # Decrementing the index

    # Calculating the length of the left segment for the first element
    while que:
        ind = que.pop()
        leftl[ind] = ind - index - 1

    ans = 0  # Initializing the variable to store the final answer

    # Calculating the answer by multiplying the element, left segment length, and right segment length for each element
    for i in range(N):
        ans += a[i] * (leftl[i] + 1) * (rightl[i] + 1)

    # Printing the final answer
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>

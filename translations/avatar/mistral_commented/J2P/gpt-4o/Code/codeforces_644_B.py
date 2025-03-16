from collections import deque  # Importing deque from collections for efficient queue operations

def main():  # Defining the main function
    n = int(input())  # Reading the first integer value from the standard input and assigning it to the variable n
    b = int(input())  # Reading the second integer value from the standard input and assigning it to the variable b
    ans = [0] * n  # Creating a list named ans with a length equal to the value of the variable n
    q = deque()  # Creating an empty deque named q

    for i in range(n):  # Starting a for loop that iterates from 0 to n-1
        t, d = map(int, input().split())  # Reading the current test case's first and second integer values

        # The following while loop is used to remove the smallest element from the queue if it is less than or equal to the current test case's first integer value t
        while q and q[0] <= t:
            q.popleft()  # Removing the smallest element from the queue

        # The following if statement checks whether the size of the queue is less than or equal to the value of the variable b
        if len(q) <= b:
            # If the condition is true, then the answer for the current test case is the sum of the last element in the queue and the difference d
            ans[i] = (t if not q else q[-1]) + d
            # Adding the answer to the queue
            q.append(ans[i])
        else:
            # If the condition is false, then the answer for the current test case is -1
            ans[i] = -1

    # The following for loop is used to print the answers for all the test cases
    print(" ".join(map(str, ans)))  # Printing the answer for all test cases in one line

if __name__ == "__main__":  # Checking if the script is being run directly
    main()  # Calling the main function

# <END-OF-CODE>

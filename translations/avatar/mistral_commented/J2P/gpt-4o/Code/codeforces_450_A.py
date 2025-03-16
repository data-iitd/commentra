from collections import deque  # Importing deque from collections for queue implementation

def main():  # Defining the main function
    n = int(input())  # Reading the first integer n from the standard input
    m = int(input())  # Reading the second integer m from the standard input

    q1 = deque()  # Creating an empty queue q1 using deque
    q2 = deque()  # Creating an empty queue q2 using deque

    for i in range(1, n + 1):  # Iterating through the input values from 1 to n
        q1.append(int(input()))  # Adding the next integer value to the queue q1
        q2.append(i)  # Adding the current index value to the queue q2

    ans = 0  # Initializing the answer variable to 0
    while q1:  # Starting the while loop to process the queues until q1 is empty
        if q1[0] <= m:  # Checking if the next value in q1 is less than or equal to m
            ans = q2.popleft()  # Removing the corresponding index value from q2 and assigning it to the answer variable
            q1.popleft()  # Removing the next value from q1
        else:  # If the next value in q1 is greater than m
            x = q1.popleft()  # Removing the next value from q1
            val = x - m  # Calculating the new value by subtracting m from the next value
            q1.append(val)  # Adding the new value back to the queue q1
            val2 = q2.popleft()  # Removing the corresponding index value from q2
            q2.append(val2)  # Adding the index value back to the queue q2

    print(ans)  # Printing the final answer

if __name__ == "__main__":  # Ensuring the main function runs when the script is executed
    main()

# <END-OF-CODE>

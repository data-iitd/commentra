import heapq  # Importing the heapq module for priority queue implementation
import sys  # Importing sys for reading input

class Job:  # Defining a class named Job
    def __init__(self, a, b):  # Constructor of the Job class
        self.a = a  # Initializing the variable a
        self.b = b  # Initializing the variable b

    def __lt__(self, other):  # Defining the less than method for comparison
        if self.a == other.a:  # Comparing the a values of the current and other Job objects
            return self.b > other.b  # If the a values are equal, comparing the b values (max-heap behavior)
        return self.a < other.a  # If the a values are not equal, comparing the a values

def main():  # Defining the main function
    input = sys.stdin.read  # Reading all input at once
    data = input().splitlines()  # Splitting the input into lines

    line = data[0].split('\u2581')  # Splitting the first line using the delimiter "\u2581"
    N = int(line[0])  # Parsing the first element as an integer
    M = int(line[1])  # Parsing the second element as an integer

    q = []  # Creating a list to use as a priority queue

    for i in range(1, N + 1):  # Iterating through the number of jobs
        line = data[i].split('\u2581')  # Splitting the next line using the delimiter "\u2581"
        heapq.heappush(q, Job(int(line[0]), int(line[1])))  # Adding a new Job object to the priority queue

    cnt = 0  # Initializing the counter variable to 0
    jobQ = []  # Creating a list to use as a max-heap for job benefits

    for i in range(1, M + 1):  # Iterating through the number of machines
        while q:  # While the priority queue is not empty
            job = q[0]  # Getting the Job object at the head of the priority queue
            if job.a <= i:  # If the machine number is greater than or equal to the job a
                heapq.heappop(q)  # Removing the Job object from the priority queue
                heapq.heappush(jobQ, -job.b)  # Adding the negative benefit of the job to the jobQ (max-heap behavior)
            else:  # If the machine number is less than the job a
                break  # Exiting the while loop

        if jobQ:  # If the jobQ is not empty
            cnt += -heapq.heappop(jobQ)  # Adding the benefit of the job to the counter variable and removing it from the jobQ

    print(cnt)  # Printing the value of the counter variable

if __name__ == "__main__":  # Checking if the script is being run directly
    main()  # Calling the main function

# <END-OF-CODE>

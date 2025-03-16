q = int(input())  # Read the number of queries
ans = [0, 0]  # Initialize the answer list with two zeros
import heapq  # Import the heapq module for heap operations
p1 = []  # Initialize the first priority queue
p2 = []  # Initialize the second priority queue
heapq.heapify(p1)  # Heapify the first priority queue
heapq.heapify(p2)  # Heapify the second priority queue
sum_b = 0  # Initialize the sum of differences
sum_p1 = 0  # Initialize the sum of the first priority queue
sum_p2 = 0  # Initialize the sum of the second priority queue

# Loop through each query
for _ in range(q):
    ql = list(map(int, input().split()))  # Read the query and convert to a list of integers
    if ql[0] == 2:  # Check if the query type is 2
        if len(p1) == len(p2):  # If the lengths of the two heaps are equal
            print(-p2[0], sum_p1 - len(p1) * -p2[0] + len(p2) * -p2[0] - sum_p2 + sum_b)  # Print the median and the sum of differences
        else:  # If the lengths of the two heaps are not equal
            print(p1[0], sum_p1 - len(p1) * p1[0] + len(p2) * p1[0] - sum_p2 + sum_b)  # Print the median and the sum of differences
    else:  # If the query type is not 2
        sum_b += ql[2]  # Add the given value to the sum of differences
        if len(p1) == 0:  # If the first priority queue is empty
            heapq.heappush(p1, ql[1])  # Push the value to the first priority queue
            sum_p1 += ql[1]  # Update the sum of the first priority queue
        elif p1[0] <= ql[1]:  # If the smallest element in the first priority queue is less than or equal to the given value
            heapq.heappush(p1, ql[1])  # Push the value to the first priority queue
            sum_p1 += ql[1]  # Update the sum of the first priority queue
        else:  # If the given value is less than the smallest element in the first priority queue
            heapq.heappush(p2, -ql[1])  # Push the negative value to the second priority queue
            sum_p2 += ql[1]  # Update the sum of the second priority queue
        if len(p1) < len(p2):  # If the first priority queue has fewer elements than the second priority queue
            k = heapq.heappop(p2)  # Pop the smallest element from the second priority queue
            heapq.heappush(p1, -k)  # Push the negative value to the first priority queue
            sum_p2 += k  # Update the sum of the second priority queue
            sum_p1 -= k  # Update the sum of the first priority queue
        if len(p1) - 1 > len(p2):  # If the first priority queue has one more element than the second priority queue
            k = heapq.heappop(p1)  # Pop the smallest element from the first priority queue
            heapq.heappush(p2, -k)  # Push the negative value to the second priority queue
            sum_p1 -= k  # Update the sum of the first priority queue
            sum_p2 += k  # Update the sum of the second priority queue

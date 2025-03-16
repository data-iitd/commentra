# Define the input size and initialize an empty list for answers
q = int(input())
ans = [0, 0]

# Import heapq module for priority queue implementation
import heapq

# Initialize empty priority queues for piles p1 and p2
p1 = []
p2 = []

# Initialize variables for sums of balls and priority queues
sum_b = 0
sum_p1 = 0
sum_p2 = 0

# Iterate through each query
for _ in range(q):
    ql = list(map(int, input().split()))

    # Check if the current query is to find the answer
    if ql[0] == 2:
        # Check if both piles have equal number of balls
        if len(p1) == len(p2):
            # Calculate the answer and print it
            print(-p2[0], sum_p1 - len(p1) * -p2[0] + len(p2) * -p2[0] - sum_p2 + sum_b)
        else:
            # Calculate the answer and print it
            print(p1[0], sum_p1 - len(p1) * p1[0] + len(p2) * p1[0] - sum_p2 + sum_b)

    # Else, the current query is to add balls to a pile
    else:
        # Add the number of balls to the total sum
        sum_b += ql[2]

        # If pile p1 is empty, add the ball to it
        if len(p1) == 0:
            heapq.heappush(p1, ql[1])
            sum_p1 += ql[1]

        # Else, check if the ball can be added to pile p1
        elif p1[0] <= ql[1]:
            heapq.heappush(p1, ql[1])
            sum_p1 += ql[1]

        # Else, add the ball to pile p2 and adjust the sums accordingly
        else:
            heapq.heappush(p2, -ql[1])
            sum_p2 += ql[1]
            sum_p1 -= ql[1]
            sum_p2 -= ql[1]

        # Adjust the priority queues if necessary
        if len(p1) < len(p2):
            k = heapq.heappop(p2)
            heapq.heappush(p1, -k)
            sum_p2 += k
            sum_p1 -= k

        if len(p1) - 1 > len(p2):
            k = heapq.heappop(p1)
            heapq.heappush(p2, -k)
            sum_p1 -= k
            sum_p2 += k

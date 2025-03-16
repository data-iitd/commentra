# Import heapq module for min heap implementation
import heapq

# Initialize constants and empty lists for left and right heaps
const = 0
left = []
right = []

# Get the number of queries from the user
q = int(input())

# Initialize counter and sums for left and right heaps
cnt = 0
left_sum = 0
right_sum = 0

# Process each query
for _ in range(q):
    # Get the query type and its arguments
    t = list(map(int, input().split()))

    # If the query type is 1, update the heaps
    if t[0] == 1:
        a, b = t[1:]

        # Update constant value
        const += b

        # If the counter is even, update the right heap
        if cnt % 2 == 0:
            if not right:
                # Push the new element to the left heap and update its sum
                heapq.heappush(left, -a)
                left_sum += a

                # Increment the counter
                cnt += 1

                # Check if the left and right heaps are balanced
                #print("Left sum: ", left_sum, "Right sum: ", right_sum, "Counter: ", cnt)
                continue

            # Pop the smallest element from the right heap
            c = heapq.heappop(right)

            # Update the sums of both heaps based on the relationship between a and c
            if a <= c:
                # Push both elements to their respective heaps and update their sums
                heapq.heappush(left, -a)
                heapq.heappush(right, c)
                left_sum += a
                right_sum += c
            else:
                # Push both elements to their respective heaps and update their sums
                heapq.heappush(left, c)
                heapq.heappush(right, a)
                left_sum -= c
                right_sum += c

            # Increment the counter
            cnt += 1

            # Check if the left and right heaps are balanced
            #print("Left sum: ", left_sum, "Right sum: ", right_sum, "Counter: ", cnt)

    # If the query type is 2, print the result
    else:
        # Get the minimum element from the left heap
        tmp = -left[0]

        # Calculate and print the result
        print(tmp, const - left_sum + right_sum + tmp * (cnt % 2))

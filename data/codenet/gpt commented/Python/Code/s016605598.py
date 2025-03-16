import heapq  # Import the heapq module for implementing heaps
const = 0  # Initialize a constant variable to track the cumulative updates
left = []  # Max-heap to store the smaller half of the numbers (inverted for max-heap behavior)
right = []  # Min-heap to store the larger half of the numbers

# Read the number of queries
q = int(input())
cnt = 0  # Counter to track the total number of elements processed
left_sum = 0  # Sum of elements in the left heap
right_sum = 0  # Sum of elements in the right heap

# Process each query
for _ in range(q):
    t = list(map(int, input().split()))  # Read the query input
    if t[0] == 1:
        # Handle the update operation
        a, b = t[1:]  # Extract the values to be processed
        const += b  # Update the constant with the value b

        # Check if the total count of elements is even
        if cnt % 2 == 0:
            # If the right heap is empty, push the element into the left heap
            if not right:
                heapq.heappush(left, -a)  # Push negative to maintain max-heap
                left_sum += a  # Update the sum of the left heap
                cnt += 1  # Increment the count of elements
                continue  # Skip to the next iteration

            # Pop the smallest element from the right heap
            c = heapq.heappop(right)
            right_sum -= c  # Update the sum of the right heap

            # Compare the new element with the smallest element in the right heap
            if a <= c:
                # If a is less than or equal to c, push a to the left heap
                heapq.heappush(left, -a)
                heapq.heappush(right, c)  # Push c back to the right heap
                left_sum += a  # Update the sum of the left heap
                right_sum += c  # Update the sum of the right heap
            else:
                # If a is greater than c, push c to the left heap and a to the right heap
                heapq.heappush(left, -c)
                heapq.heappush(right, a)
                left_sum += c  # Update the sum of the left heap
                right_sum += a  # Update the sum of the right heap
        else:
            # If the total count of elements is odd
            c = heapq.heappop(left)  # Pop the largest element from the left heap
            left_sum += c  # Update the sum of the left heap

            # Compare the new element with the largest element in the left heap
            if a <= -c:
                # If a is less than or equal to -c, push a to the left heap
                heapq.heappush(left, -a)
                heapq.heappush(right, -c)  # Push c back to the right heap
                left_sum += a  # Update the sum of the left heap
                right_sum -= c  # Update the sum of the right heap
            else:
                # If a is greater than -c, push c back to the left heap and a to the right heap
                heapq.heappush(left, c)
                heapq.heappush(right, a)
                left_sum -= c  # Update the sum of the left heap
                right_sum += a  # Update the sum of the right heap

        cnt += 1  # Increment the count of elements processed
    else:
        # Handle the query to print the result
        tmp = -left[0]  # Get the largest element from the left heap (inverted back)
        # Calculate and print the result based on the current state of the heaps
        print(tmp, const - left_sum + right_sum + tmp * (cnt % 2))

import heapq

# Constants and initializations
const = 0
left = []  # Max-heap for the left half
right = []  # Min-heap for the right half

# Read the number of queries
q = int(input())
cnt = 0
left_sum = 0
right_sum = 0

# Process each query
for _ in range(q):
    t = list(map(int, input().split()))
    if t[0] == 1:
        # Update operation
        a, b = t[1:]
        const += b  # Update the constant
        if cnt % 2 == 0:
            # Even count, add to left heap
            if not right:
                heapq.heappush(left, -a)
                left_sum += a
                cnt += 1
                continue

            c = heapq.heappop(right)
            right_sum -= c
            if a <= c:
                heapq.heappush(left, -a)
                heapq.heappush(right, c)
                left_sum += a
                right_sum += c
            else:
                heapq.heappush(left, -c)
                heapq.heappush(right, a)
                left_sum += c
                right_sum += a
        else:
            # Odd count, add to right heap
            c = heapq.heappop(left)
            left_sum += c
            if a <= -c:
                heapq.heappush(left, -a)
                heapq.heappush(right, -c)
                left_sum += a
                right_sum -= c
            else:
                heapq.heappush(left, c)
                heapq.heappush(right, a)
                left_sum -= c
                right_sum += a
        cnt += 1
    else:
        # Query type 2, print the median
        tmp = -left[0]
        print(tmp, const - left_sum + right_sum + tmp * (cnt % 2))

import sys
import heapq

def main():
    # Read the number of test cases
    t = int(sys.stdin.readline().strip())
    
    # Min-heap for minimum values and max-heap for maximum values
    pqmax = []  # This will be a max-heap (inverted min-heap)
    pqmin = []  # This will be a min-heap
    
    # Variables to store sums and minimum value
    sum_min = 0
    sum_max = 0
    sumb = 0
    min_value = 0
    
    # Process each test case
    for _ in range(t):
        s = sys.stdin.readline().strip().split()
        
        # If the first character is '2', calculate and print the result
        if s[0] == '2':
            ans = min_value * len(pqmin) - sum_min
            ans1 = sum_max - min_value * len(pqmax)
            
            # Print the minimum value and the calculated result
            print(min_value, ans + ans1 + sumb)
        else:
            # Parse the input values
            in_value = int(s[1])
            sumb += int(s[2])  # Update the sum of additional values
            
            # Add the input value to the appropriate priority queue
            if in_value > min_value:
                heapq.heappush(pqmax, -in_value)  # Push negative for max-heap
                sum_max += in_value
            else:
                heapq.heappush(pqmin, in_value)
                sum_min += in_value
            
            # Balance the two heaps if necessary
            if len(pqmin) > len(pqmax):
                sum_max += pqmin[0]
                sum_min -= pqmin[0]
                heapq.heappush(pqmax, -heapq.heappop(pqmin))
            if len(pqmin) < len(pqmax):
                sum_max -= -pqmax[0]
                sum_min += -pqmax[0]
                heapq.heappush(pqmin, -heapq.heappop(pqmax))
            
            # Update the minimum value based on the current state of the heaps
            min_value = pqmin[0]
    
if __name__ == "__main__":
    main()

# <END-OF-CODE>

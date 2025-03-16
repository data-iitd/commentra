
import sys
from heapq import heappush, heappop

def main():
    # Initialize variables to keep track of sums and the minimum value
    sum_min = 0
    sum_max = 0
    sum_b = 0
    min_val = 0
    heap_min = []
    heap_max = []
    
    # Process each test case
    for _ in range(int(input())):
        # Read the input for the current test case
        cmd = input().split()
        
        # If the command is '2', calculate and print the result
        if cmd[0] == '2':
            ans = min_val
            ans *= len(heap_min)
            ans -= sum_min
            ans1 = min_val
            ans1 *= len(heap_max)
            ans1 = sum_max - ans1
            print(min_val, ans + ans1 + sum_b)
        # If the command is '1', add the new value to the appropriate heap
        else:
            in_val = int(cmd[1])
            sum_b += int(cmd[2])
            
            if in_val > min_val:
                heappush(heap_max, -in_val)
                sum_max -= in_val
            else:
                heappush(heap_min, in_val)
                sum_min += in_val
            
            # Balance the heaps
            if len(heap_min) > len(heap_max) + 1:
                val = -heappop(heap_min)
                heappush(heap_max, val)
                sum_max += val
                sum_min -= val
            elif len(heap_max) > len(heap_min):
                val = heappop(heap_max)
                heappush(heap_min, -val)
                sum_max -= val
                sum_min += val
            
            # Update the minimum value
            min_val = -heap_min[0]
    
    # Flush the output
    sys.stdout.flush()

if __name__ == "__main__":
    main()


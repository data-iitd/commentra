import sys
import heapq

def main():
    # Read the number of test cases
    t = int(sys.stdin.readline().strip())
    
    # Initialize priority queues for max and min values
    pqmax = []  # Max heap (using min heap with negative values)
    pqmin = []  # Min heap
    
    # Initialize variables to keep track of sums and the minimum value
    sumMin = 0
    sumMax = 0
    sumb = 0
    min_val = 0
    
    # Process each test case
    for _ in range(t):
        s = sys.stdin.readline().strip().split()
        
        # If the command is '2', calculate and print the result
        if s[0] == '2':
            ans = min_val * len(pqmin) - sumMin
            ans1 = sumMax - min_val * len(pqmax)
            print(min_val, ans + ans1 + sumb)
        # If the command is '1', add the new value to the appropriate priority queue
        else:
            in_val = int(s[1])
            sumb += int(s[2])
            
            if in_val > min_val:
                heapq.heappush(pqmax, -in_val)  # Push negative for max heap
                sumMax += in_val
            else:
                heapq.heappush(pqmin, in_val)
                sumMin += in_val
            
            # Balance the priority queues
            if len(pqmin) > len(pqmax):
                sumMax += pqmin[0]
                sumMin -= pqmin[0]
                heapq.heappush(pqmax, -heapq.heappop(pqmin))
            
            if len(pqmin) < len(pqmax):
                sumMax -= -pqmax[0]
                sumMin += -pqmax[0]
                heapq.heappush(pqmin, -heapq.heappop(pqmax))
            
            # Update the minimum value
            min_val = pqmin[0]
    
if __name__ == "__main__":
    main()

# <END-OF-CODE>

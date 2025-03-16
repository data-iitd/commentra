
import sys
import heapq

def main():
    # Read the number of test cases
    t = int(input())

    # Initialize variables for processing input
    s = []
    pqmax = [] # Min-heap for maximum values
    pqmin = [] # Max-heap for minimum values
    sumMin = 0
    sumMax = 0
    sumb = 0
    min = 0

    # Process each test case
    for _ in range(t):
        # Read the input line and split it into parts
        s = input().split()

        # If the first character is '2', calculate and print the result
        if s[0][0] == '2':
            ans = min * len(pqmin) - sumMin
            ans1 = min * len(pqmax) - sumMax
            print(min, ans + ans1 + sumb)
        else:
            # Parse the input values
            in = int(s[1])
            sumb += int(s[2]) # Update the sum of additional values

            # Add the input value to the appropriate priority queue
            if in > min:
                heapq.heappush(pqmax, in)
                sumMax += in
            else:
                heapq.heappush(pqmin, in)
                sumMin += in

            # Balance the two heaps if necessary
            if len(pqmin) > len(pqmax) + 1:
                sumMax += heapq.heappushpop(pqmin, min)
            if len(pqmax) > len(pqmin):
                sumMin += heapq.heappushpop(pqmax, -min)

            # Update the minimum value based on the current state of the heaps
            min = -pqmin[0] if pqmin else pqmax[0]

if __name__ == "__main__":
    main()


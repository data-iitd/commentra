import sys
import heapq

def main():
    input = sys.stdin.read
    data = input().splitlines()
    
    t = int(data[0])  # Read the number of test cases
    pqmax = []  # Max Heap to store the maximum elements
    pqmin = []  # Min Heap to store the minimum elements
    sumMin = 0
    sumMax = 0
    sumb = 0
    min_elem = float('inf')  # Variable to store the minimum element

    for i in range(1, t + 1):
        s = data[i].split()  # Read each line of input and split it into an array of strings

        if s[0] == '2':  # If the first character of the line is '2'
            ans = min_elem  # Answer is the product of the minimum element and the size of the min heap
            ans *= len(pqmin)
            ans -= sumMin  # Subtract the sum of minimum elements before the current minimum
            ans1 = min_elem  # Answer1 is the product of the minimum element and the size of the max heap
            ans1 = sumMax - ans1  # Subtract the sum of maximum elements before the current minimum
            print(min_elem, ans + ans1 + sumb)  # Print the answer
        else:  # Else the first character of the line is not '2'
            in_val = int(s[1])  # Read the integer value from the input
            sumb += int(s[2])  # Add the long value to the sum of the current element

            if in_val > min_elem:  # If the input is greater than the current minimum
                heapq.heappush(pqmax, -in_val)  # Add the input to the max heap (negate for max heap)
                sumMax += in_val  # Add the input to the sum of maximum elements
            else:  # Else the input is smaller than the current minimum
                heapq.heappush(pqmin, in_val)  # Add the input to the min heap
                sumMin += in_val  # Add the input to the sum of minimum elements

            # Balance the heaps
            if len(pqmin) > len(pqmax):  # If the size of min heap is greater than the size of max heap
                sumMax += pqmin[0]  # Add the minimum element to the sum of maximum elements
                sumMin -= pqmin[0]  # Subtract the minimum element from the sum of minimum elements
                heapq.heappush(pqmax, -heapq.heappop(pqmin))  # Move the min element to max heap
            elif len(pqmin) < len(pqmax):  # Else if the size of min heap is smaller than the size of max heap
                sumMax -= -pqmax[0]  # Subtract the maximum element from the sum of maximum elements
                sumMin += -pqmax[0]  # Add the maximum element to the sum of minimum elements
                heapq.heappush(pqmin, -heapq.heappop(pqmax))  # Move the max element to min heap

            min_elem = pqmin[0]  # Update the minimum element

if __name__ == "__main__":
    main()

# <END-OF-CODE>

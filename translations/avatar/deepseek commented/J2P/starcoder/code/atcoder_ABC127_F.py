import sys
import heapq

# Declare static members for output stream and print writer
outputStream = sys.stdout
out = sys.stdout

# Declare static members for input stream and print reader
inputStream = sys.stdin
in = sys.stdin

# Declare static members for input stream and print reader
def main():
    # Read the number of test cases
    t = int(in.readline())
    
    # Initialize priority queues for max and min values
    pqmax = []
    pqmin = []
    
    # Initialize variables to keep track of sums and the minimum value
    sumMin = 0
    sumMax = 0
    sumb = 0
    min = 0
    
    # Process each test case
    while t > 0:
        # Read the input for the current test case
        s = in.readline().split(" ")
        
        # If the command is '2', calculate and print the result
        if s[0].charAt(0) == '2':
            ans = min
            ans *= len(pqmin)
            ans -= sumMin
            ans1 = min
            ans1 *= len(pqmax)
            ans1 = sumMax - ans1
            out.write(str(min) + " " + str(ans + ans1 + sumb) + "\n")
        # If the command is '1', add the new value to the appropriate priority queue
        else:
            in1 = int(s[1])
            sumb += int(s[2])
            
            if in1 > min:
                heapq.heappush(pqmax, in1)
                sumMax += in1
            else:
                heapq.heappush(pqmin, in1)
                sumMin += in1
            
            # Balance the priority queues
            if len(pqmin) > len(pqmax):
                sumMax += pqmin[0]
                sumMin -= pqmin[0]
                heapq.heappush(pqmax, pqmin[0])
                pqmin.pop(0)
            
            if len(pqmin) < len(pqmax):
                sumMax -= pqmax[0]
                sumMin += pqmax[0]
                heapq.heappush(pqmin, pqmax[0])
                pqmax.pop(0)
            
            # Update the minimum value
            min = pqmin[0]
        
        t -= 1
    
    # Close the print writer to flush the output
    out.close()

if __name__ == "__main__":
    main()


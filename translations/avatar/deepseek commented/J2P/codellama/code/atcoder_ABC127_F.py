import sys
import heapq

# Declare static variables for output stream and print writer
outputStream = sys.stdout
out = PrintWriter(outputStream)

def main():
    # Initialize BufferedReader to read input from System.in
    br = BufferedReader(InputStreamReader(System.in))
    
    # Read the number of test cases
    t = int(br.readLine())
    
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
        s = br.readLine().split(" ")
        
        # If the command is '2', calculate and print the result
        if s[0] == '2':
            ans = min
            ans *= len(pqmin)
            ans -= sumMin
            ans1 = min
            ans1 *= len(pqmax)
            ans1 = sumMax - ans1
            out.println(min + " " + (ans + ans1 + sumb))
        # If the command is '1', add the new value to the appropriate priority queue
        else:
            in = int(s[1])
            sumb += int(s[2])
            
            if in > min:
                heapq.heappush(pqmax, in)
                sumMax += in
            else:
                heapq.heappush(pqmin, in)
                sumMin += in
            
            # Balance the priority queues
            if len(pqmin) > len(pqmax):
                sumMax += pqmin[0]
                sumMin -= pqmin[0]
                heapq.heappush(pqmax, heapq.heappop(pqmin))
            if len(pqmin) < len(pqmax):
                sumMax -= pqmax[0]
                sumMin += pqmax[0]
                heapq.heappush(pqmin, heapq.heappop(pqmax))
            
            # Update the minimum value
            min = pqmin[0]
        
        t -= 1
    
    # Close the print writer to flush the output
    out.close()



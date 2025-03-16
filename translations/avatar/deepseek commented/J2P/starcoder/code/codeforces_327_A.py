import sys; # Importing the sys module for input

def main():
    if (sys.stdin.readline().strip()): # Checking if there is input available
        n = int(sys.stdin.readline().strip()); # Reading the size of the array
        arr = [int(sys.stdin.readline().strip()) for i in range(n)]; # Declaring and initializing the array
        
        max = -1; # Initializing max to the minimum possible integer value
        
        for i in range(n): # Iterating over all possible starting points of subarrays
            for j in range(i, n): # Iterating over all possible ending points of subarrays
                brr = arr.copy(); # Declaring and initializing a copy of the array
                
                for k in range(i, j + 1): # Flipping the elements in the current subarray
                    if (brr[k] == 0):
                        brr[k] = 1;
                    else:
                        brr[k] = 0;
                
                count = checkNo(brr); # Counting the number of 1s in the modified subarray
                
                if (count > max):
                    max = count; # Updating max if the current count is greater
        print(max); # Printing the maximum count of 1s found
    else:
        print(0); # Handling the special case of a single element array

def checkNo(brr): # Helper method to count the number of 1s in an array
    val = 0;
    for i in brr:
        if (i == 1):
            val += 1;
    return val;

if __name__ == "__main__":
    main();


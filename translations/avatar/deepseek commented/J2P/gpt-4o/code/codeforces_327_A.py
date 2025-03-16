def check_no(brr):  # Helper function to count the number of 1s in an array
    val = 0
    for i in brr:
        if i == 1:
            val += 1
    return val

def main():
    n = int(input())  # Reading the size of the array
    arr = list(map(int, input().split()))  # Reading the elements of the array
    
    max_count = float('-inf')  # Initializing max to the minimum possible integer value
    
    for i in range(n):  # Iterating over all possible starting points of subarrays
        for j in range(i, n):  # Iterating over all possible ending points of subarrays
            brr = arr[:]  # Creating a copy of the array
            
            for k in range(i, j + 1):  # Flipping the elements in the current subarray
                brr[k] = 1 - brr[k]  # Flipping 0 to 1 and 1 to 0
            
            count = check_no(brr)  # Counting the number of 1s in the modified array
            
            if count > max_count:
                max_count = count  # Updating max if the current count is greater
    
    if n == 1:  # Handling the special case of a single element array
        if arr[0] == 1:
            print(0)
        else:
            print(1)
    else:
        print(max_count)  # Printing the maximum count of 1s found

if __name__ == "__main__":
    main()

# <END-OF-CODE>

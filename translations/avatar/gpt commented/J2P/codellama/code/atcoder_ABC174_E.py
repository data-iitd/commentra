import sys 

def solve(n, k, logsLength): 
    # Initialize binary search bounds 
    min = 1 
    max = 1000000000 
    
    # Perform binary search to find the minimum possible length 
    while min < max: 
        mid = (min + max) // 2 
        
        # Check if it's possible to cut the logs with the current mid length 
        if nei(mid, logsLength, k): 
            max = mid 
        else: 
            min = mid + 1 
    
    # Output the minimum length found 
    print(min) 

def nei(mid, logsLength, k): 
    for log in logsLength: 
        k -= (log + mid - 1) // mid 
    
    # Return true if we can make the cuts within the limit of k 
    return k >= 0 

def main(): 
    # Read the number of logs and the value of k 
    n, k = map(int, sys.stdin.readline().split()) 
    
    # Read the lengths of the logs into an array 
    logsLength = list(map(int, sys.stdin.readline().split())) 
    
    # Solve the problem 
    solve(n, k, logsLength) 

if __name__ == "__main__": 
    main() 

# 
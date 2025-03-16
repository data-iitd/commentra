import heapq

def main():
    print(solve())

def solve():
    # Create a Scanner object to read input from the standard input stream
    N = int(input())
    
    # Initialize a list to store the integers
    arr = list(map(int, input().split()))
    
    # Initialize a sum variable to 0
    sum_count = 0
    
    # Create a priority queue (min-heap) to store the integers in ascending order
    q = []
    
    # Iterate through the array and add each element to the priority queue
    for i in range(N):
        heapq.heappush(q, arr[i])
        
        # Check if the current element is less than or equal to the smallest element in the priority queue
        if arr[i] <= q[0]:
            sum_count += 1
            
    # Return the sum
    return sum_count

if __name__ == "__main__":
    main()

# <END-OF-CODE>

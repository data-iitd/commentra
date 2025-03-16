class Work:
    def __init__(self, time, limit):
        self.time = time
        self.limit = limit

def main():
    # Read the number of works
    n = int(input())
    
    # Create a list of work objects with a length of n
    ws = []
    
    # Read the time and limit for each work and store them in the list
    for _ in range(n):
        a, n = map(int, input().split())
        ws.append(Work(a, n))
    
    # Sort the list of works based on the limit field
    ws.sort(key=lambda w: w.limit)
    
    # Initialize a sum variable to keep track of the cumulative time
    sum_time = 0
    
    # Iterate over the sorted list of works, adding the time of each work to the sum
    for w in ws:
        sum_time += w.time
        
        # Check if the cumulative time exceeds the limit of the current work
        if sum_time > w.limit:
            print("No")
            return
    
    # If the loop completes without the sum exceeding any limit, print "Yes"
    print("Yes")

# Call the main function
main()

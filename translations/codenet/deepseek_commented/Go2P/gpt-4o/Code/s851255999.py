class Work:
    def __init__(self, time, limit):
        self.time = time
        self.limit = limit

def main():
    # Read the number of works
    n = int(input())
    
    # Create a list of work objects
    works = []
    
    # Read the time and limit for each work and store them in the list
    for _ in range(n):
        a, limit = map(int, input().split())
        works.append(Work(a, limit))
    
    # Sort the list of works based on the limit field
    works.sort(key=lambda w: w.limit)
    
    # Initialize a sum variable to keep track of the cumulative time
    total_time = 0
    
    # Iterate over the sorted list of works, adding the time of each work to the total_time
    for w in works:
        total_time += w.time
        
        # Check if the cumulative time exceeds the limit of the current work
        if total_time > w.limit:
            print("No")
            return
    
    # If the loop completes without the total_time exceeding any limit, print "Yes"
    print("Yes")

if __name__ == "__main__":
    main()

# <END-OF-CODE>

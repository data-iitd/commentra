
import queue 

def main(): 
    # Create a queue object to store the values and their corresponding indices
    q1 = queue.Queue() 
    q2 = queue.Queue() 

    # Read the number of elements (n) and the threshold value (m)
    n = int(input()) 
    m = int(input()) 

    # Populate the queues with input values and their corresponding indices
    for i in range(1, n + 1): 
        q1.put(int(input())) # Add the value to the first queue
        q2.put(i) # Add the index to the second queue

    # Variable to store the final answer (the index of the last processed element)
    ans = 0 

    # Process the elements in the queue until it is empty
    while not q1.empty(): 
        # Check if the front element of q1 is less than or equal to m
        if q1.queue[0] <= m: 
            # If yes, remove it from q1 and update the answer with the corresponding index from q2
            q1.get() 
            ans = q2.get() 
        # If the front element is greater than m
        else: 
            # Remove the element, reduce it by m, and add it back to q1
            x = q1.get() 
            val = x - m 
            q1.put(val) 

            # Remove the index from q2 and add it back to maintain the order
            val2 = q2.get() 
            q2.put(val2) 

    # Output the final answer
    print(ans) 

if __name__ == "__main__": 
    main() 


def main_function():
    # Read an integer input which represents the number of elements
    n = int(input())
    
    # Read a line of input, split it by spaces, and convert it to a list of integers
    a = [int(i) for i in input().split(" ")]
    
    # Initialize the current level and counters
    current_level = 0
    counter = 0
    counter_turns = -1  # Start with -1 to account for the first turn increment
    
    # Loop until all elements have been processed
    while counter < len(a):
        counter_turns += 1  # Increment the turn counter
        
        # Iterate through the list to find elements that can be processed
        for i in range(len(a)):
            # Check if the current element is not marked (-1) and is less than or equal to the current counter
            if a[i] != -1 and a[i] <= counter:
                counter += 1  # Increment the counter as we can process this element
                a[i] = -1  # Mark the element as processed by setting it to -1
        
        # Reverse the list to prepare for the next round of processing
        a.reverse()
    
    # Print the total number of turns taken to process all elements
    print(counter_turns)

# Call the main function to execute the code
main_function()

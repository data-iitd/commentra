
def main_function ( ) :
    # Read the number of elements from the user
    n = int ( input ( ) )
    # Read the list of integers from the user input
    a = [ int ( i ) for i in input ( ).split ( " " ) ]
    
    # Initialize variables to track the current level and the number of turns
    current_level = 0
    counter = 0
    counter_turns = - 1
    
    # Start a while loop that continues until all elements are processed
    while counter < len ( a ) :
        # Increment the turn counter
        counter_turns += 1
        # Iterate over the list 'a' to process each element
        for i in range ( len ( a ) ) :
            # Check if the element is not -1 and is less than or equal to the current level
            if a [ i ] != - 1 and a [ i ] <= counter :
                # Increment the counter and mark the element as processed
                counter += 1
                a [ i ] = - 1
        # Reverse the list 'a' to process elements in a different order in the next iteration
        a.reverse ( )
    
    # Print the number of turns taken to process all elements
    print ( counter_turns )
main_function ( )


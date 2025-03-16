
# Define a function named s that takes no arguments
def s ( ):

    # Read input as a list of integers
    input_list = list( map( int, input().split() ) )

    # Sort the input list in ascending order
    input_list.sort()

    # Initialize a variable to store the result
    result = ''

    # Iterate through the sorted list starting from the second element
    for i in range( 1, len( input_list ) ):

        # Compare the current element with the previous one
        current_element = input_list[i]
        previous_element = input_list[i-1]

        # Check if the current element is less than twice the previous element
        # and if it is not equal to the previous element
        if current_element < previous_element * 2 and current_element != previous_element:

            # If the condition is true, set the result to 'YES'
            result = 'YES'

            # Break out of the loop since we have found the answer
            break

    # Print the result
    print( result )

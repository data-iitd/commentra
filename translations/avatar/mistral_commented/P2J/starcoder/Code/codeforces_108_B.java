
// Define a function named s that takes no arguments
public static void s ( ) {

    // Read input as a list of integers
    List<Integer> input_list = new ArrayList<Integer>( Arrays.asList( input().split(" ") ) );

    // Sort the input list in ascending order
    Collections.sort( input_list );

    // Initialize a variable to store the result
    String result = "";

    // Iterate through the sorted list starting from the second element
    for ( int i = 1; i < input_list.size(); i++ ) {

        // Compare the current element with the previous one
        int current_element = input_list.get(i);
        int previous_element = input_list.get(i-1);

        // Check if the current element is less than twice the previous element
        // and if it is not equal to the previous element
        if ( current_element < previous_element * 2 && current_element!= previous_element ) {

            // If the condition is true, set the result to 'YES'
            result = "YES";

            // Break out of the loop since we have found the answer
            break;
        }
    }

    // Print the result
    System.out.println( result );
}


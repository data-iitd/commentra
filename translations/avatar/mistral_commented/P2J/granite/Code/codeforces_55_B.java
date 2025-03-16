
#####
// This function is named'rememberTheNumber' and takes four arguments: 'nums' (a list of numbers), 'i' (an index), 'operations' (a list of operations), and 'ans' (a list to store the answer).
// The function is designed to process the given list of numbers and operations in a specific way.
// If the index 'i' is less than 3, the function continues to process further.
########

public static void rememberTheNumber ( int [ ] nums, int i, String [ ] operations, int [ ] ans ) {
    if ( i >= 3 ) {
        // If the index 'i' is greater than or equal to 3, the function returns without doing anything further.
        return;
    }

    for ( int j = 0 ; j < 4 ; j ++ ) {
        for ( int k = j + 1 ; k < 4 ; k ++ ) {
            // The inner for loop iterates through the range of indices from 0 to 3 (exclusive).
            // The variable 'j' is used as the index for the first number in the pair to be processed.
            if ( nums [ j ]!= - 1 && nums [ k ]!= - 1 ) {
                // If both numbers at indices 'j' and 'k' are not -1 (meaning they have not been processed), the following code is executed.
                int s = nums [ j ] ;
                // Assign the value of the number at index 'j' to the variable's'.
                nums [ j ] = - 1 ;
                int t = nums [ k ] ;
                // Assign the value of the number at index 'k' to the variable 't'.
                if ( operations [ i ]. equals ( " + " ) ) {
                    // If the current operation is '+', perform the addition of the numbers's' and 't' and assign the result to the number at index 'k'.
                    nums [ k ] = s + t ;
                } else if ( operations [ i ]. equals ( " * " ) ) {
                    // If the current operation is '*', perform the multiplication of the numbers's' and 't' and assign the result to the number at index 'k'.
                    nums [ k ] = s * t ;
                }
                if ( i == 2 && nums [ k ] < ans [ 0 ] ) {
                    // If the index 'i' is 2 and the number at index 'k' is less than the current answer, update the answer.
                    ans [ 0 ] = nums [ k ] ;
                }
                rememberTheNumber ( nums, i + 1, operations, ans ) ;
                // Recursively call the function'rememberTheNumber' with updated index 'i+1'.
                nums [ j ] = s ;
                // Restore the original value of the number at index 'j'.
                nums [ k ] = t ;
                // Restore the original value of the number at index 'k'.
            }
        }
    }
}

########
// The following lines of code initialize the list 'nums' with input numbers, initialize the list 'operations' with input operations, initialize the list 'ans' with a large number, and call the function'rememberTheNumber' with initial index '0'.
########

int [ ] nums = Arrays. stream ( input ( ). split ( " " ) ). mapToInt ( Integer :: parseInt ).toArray ( ) ;
// Read the list of numbers as input and convert them to integers.
String [ ] operations = input ( ). split ( " " ) ;
// Read the list of operations as input.
int [ ] ans = { 1000000000000000000L } ;
// Initialize the answer list with a large number.
rememberTheNumber ( nums, 0, operations, ans ) ;
// Call the function'rememberTheNumber' with initial index '0'.
System. out. println ( ans [ 0 ] ) ;
// Print the final answer.


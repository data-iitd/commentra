

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "sort"
)

func main() {
    reader := bufio.NewReader( os.Stdin )

    // Read input as a list of integers
    input_list, _ := reader.ReadString( '\n' )
    input_list = input_list[:len( input_list )-1]
    input_list_split := strings.Split( input_list, " " )
    input_list_int := make( []int, len( input_list_split ) )
    for i := 0; i < len( input_list_split ); i++ {
        input_list_int[i], _ = strconv.Atoi( input_list_split[i] )
    }

    // Sort the input list in ascending order
    sort.Ints( input_list_int )

    // Initialize a variable to store the result
    result := "NO"

    // Iterate through the sorted list starting from the second element
    for i := 1; i < len( input_list_int ); i++ {

        // Compare the current element with the previous one
        current_element := input_list_int[i]
        previous_element := input_list_int[i-1]

        // Check if the current element is less than twice the previous element
        // and if it is not equal to the previous element
        if current_element < previous_element * 2 && current_element!= previous_element {

            // If the condition is true, set the result to 'YES'
            result = "YES"

            // Break out of the loop since we have found the answer
            break
        }
    }

    // Print the result
    fmt.Println( result )
}


<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)
 
import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)
 
// Function to sort the vector in ascending order using insertion sort algorithm
func sort(a_rvecIntValue []int) {
 
    // Iterate through each element in the vector starting from the second element
    for i := 0; i < len(a_rvecIntValue); i++ {
        if i!= 0 { // Check if we are not at the first element
 
            iIntValue := a_rvecIntValue[i] // Get the value of the current element
            j := i - 1 // Initialize a variable to store the index of the previous element
            for ; j >= 0 && a_rvecIntValue[j] > iIntValue; j-- { // While the previous element is greater than the current element
                a_rvecIntValue[j+1] = a_rvecIntValue[j] // Swap the previous and next elements
            }
            a_rvecIntValue[j+1] = iIntValue // Place the current element at its correct position
        }
 
        // Print the sorted vector after each insertion
        for k := 0; k < len(a_rvecIntValue); k++ {
            fmt.Printf("%d", a_rvecIntValue[k]) // Print the value of the current element
            if k!= len(a_rvecIntValue) - 1 { // Check if we are not at the last element
                fmt.Printf(" ") // Print a space if not
            }
        }
        fmt.Printf("\n") // Print a newline after each pass
    }
}
 
func main() {
 
    var iNum int // Initialize a variable to store the number of elements in the vector
    fmt.Scanf("%d", &iNum) // Read the number of elements from the standard input
 
    var vecIntValue []int // Create an empty vector to store the integers
    for i := 0; i < iNum; i++ {
        var iIntValue int // Initialize a variable to store the next integer to be added to the vector
        fmt.Scanf("%d", &iIntValue) // Read the next integer from the standard input
        vecIntValue = append(vecIntValue, iIntValue) // Add the integer to the vector
    }
 
    // Call the sorting function to sort the vector
    sort(vecIntValue)
}


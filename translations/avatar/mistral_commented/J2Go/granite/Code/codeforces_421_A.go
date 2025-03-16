
// Import necessary packages
import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

// Create the main function
func main() {
    // Initialize variables
    var n, a, b int
    var list1, list2 []int

    // Create a new Scanner object to read input from the standard input
    scanner := bufio.NewScanner(os.Stdin)

    // Read the number of test cases, the number of elements in the first list, and the number of elements in the second list
    fmt.Fscanf(scanner, "%d %d %d\n", &n, &a, &b)

    // Read and store the elements of the first and second lists
    for i := 0; i < a; i++ {
        fmt.Fscanf(scanner, "%d", &num) // Read and store an element in list1
        list1 = append(list1, num)
    }
    for i := 0; i < b; i++ {
        fmt.Fscanf(scanner, "%d", &num) // Read and store an element in list2
        list2 = append(list2, num)
    }

    // Iterate through the input array and print the corresponding number based on the presence of the element in list1
    for i := 0; i < n; i++ {
        if contains(list1, i+1) { // Check if the current input element is present in list1
            fmt.Print(1 + " ") // If present, print 1
        } else {
            fmt.Print(2 + " ") // If not present, print 2
        }
    }

    // Close the Scanner object
    scanner.Close()
}

// Define a function to check if an element is present in a list
func contains(list []int, element int) bool {
    for _, value := range list {
        if value == element {
            return true
        }
    }
    return false
}

Translate the above Go code to C++ and end with comment "
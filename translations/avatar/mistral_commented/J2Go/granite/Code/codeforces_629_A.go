
// Importing necessary packages
import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

// Declaring the main function'main'
func main() {

    // Creating a new scanner object to read input from the console
    scanner := bufio.NewScanner(os.Stdin)

    // Reading the number of strings 'num' from the user input
    scanner.Scan()
    num, _ := strconv.Atoi(scanner.Text())

    // Initializing a slice of strings 'arr' with a length equal to 'num'
    arr := make([]string, num)

    // Reading each string's' from the user input and adding it to the slice 'arr'
    for i := 0; i < num; i++ {
        scanner.Scan()
        arr[i] = scanner.Text()
    }

    // Initializing two variables 'counter' and 'fine'
    counter := 0
    fine := 0

    // The first nested loop to iterate through each character in each string
    for i := 0; i < num; i++ {
        for k := 0; k < num; k++ {
            // Checking if the character at position (i,k) in the string at index 'i' is 'C'
            if string(arr[i][k]) == "C" {
                // Incrementing the counter variable
                counter++
            }
        }
        // Calculating the fine based on the number of 'C' characters in the current string
        fine += (counter * (counter - 1)) / 2
        // Resetting the counter variable for the next string
        counter = 0
    }

    // The second nested loop to iterate through each character in each string again
    for i := 0; i < num; i++ {
        for k := 0; k < num; k++ {
            // Checking if the character at position (i,k) in the string at index 'k' is 'C'
            if string(arr[k][i]) == "C" {
                // Incrementing the counter variable
                counter++
            }
        }
        // Calculating the fine based on the number of 'C' characters in the current string
        fine += (counter * (counter - 1)) / 2
        // Resetting the counter variable for the next string
        counter = 0
    }

    // Printing the final result 'fine'
    fmt.Println(fine)

    // Closing the scanner object
    scanner.Close()

    // Ending the program with the comment "
// Importing the Scanner class from the java.util package
import "fmt"
import "strconv"

// Main method is the entry point of the Java application
func main() {
    // Initializing the Scanner object to read input from the console
    var pandu, vundu, urdu, c int64

    // Reading the values of pandu, vundu and urdu from the console using Scanner
    fmt.Scan(&pandu, &vundu, &urdu)

    // Using a for loop to calculate the sum of the series and store it in the variable c
    for i := int64(1); i <= urdu; i++ {
        c += i * pandu
        // Comment: Calculating the sum of the series using the formula: c = c + i * pandu
    }

    // Checking if the calculated sum is less than vundu
    if c < vundu {
        // Comment: If the calculated sum is less than vundu, then print "0"
        fmt.Print("0")
    } else {
        // Comment: If the calculated sum is greater than or equal to vundu, then print the difference between the calculated sum and vundu
        fmt.Print(c - vundu)
    }
}


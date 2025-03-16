#######
# Code
#######

// Import necessary libraries
import "fmt"

// Define constants
const (
    inf = 1000000000
    mod = 1000000007
)

// Function to read an integer list from standard input
func LI( ) (l []int) {
    s := bufio.NewScanner(os.Stdin)
    s.Scan()
    for _, x := range s.Text( ) {
        l = append(l, int(x) - '0')
    }
    return
}

// Function to read an integer from standard input
func I( ) int {
    return int(LI( )[0])
}

// Function to read a float from standard input
func F( ) float64 {
    return float64(LI( )[0])
}

// Function to read a list from standard input, split by space
func LS( ) (l []string) {
    s := bufio.NewScanner(os.Stdin)
    s.Scan()
    for _, x := range s.Text( ) {
        l = append(l, string(x))
    }
    return
}

// Function to read a string from standard input
func S( ) string {
    return LS( )[0]
}

// Main function
func main( ) {
    // Read input values
    a, b, c, d := LI( )

    // Calculate the maximum product of pairs of numbers
    result := max(a*c, b*d, a*d, b*c)

    // Print the result
    fmt.Println(result)
}

// Call the main function
func main( ) {
    main( )
}


// Importing the Scanner class for reading input from the console
import "fmt"
import "os"

// Defining the main method as the entry point of the program
func main() {
    // Creating a new Scanner object to read input from the console
    s := bufio.NewScanner(os.Stdin)

    // Reading the number of test cases
    var n int
    s.Scan()
    fmt.Sscan(s.Text(), &n)

    // Declaring an integer array dp of size 200001 to store the position of each number in the sequence
    dp := make([]int, 200001)

    // Initializing a long variable ans to store the answer
    var ans int64

    // Iterating through each test case
    for i := 0; i < n; i++ {
        // Reading the next number to be added to the sequence
        var num int
        s.Scan()
        fmt.Sscan(s.Text(), &num)

        // Storing the position of the number in the dp array
        dp[num] = i
    }

    // Calculating the answer by iterating through the dp array and finding the absolute difference between the positions of consecutive numbers
    for i := 2; i <= n; i++ {
        // Adding the absolute difference to the answer
        ans += int64(math.Abs(float64(dp[i] - dp[i-1])))
    }

    // Printing the answer to the console
    fmt.Println(ans)
}


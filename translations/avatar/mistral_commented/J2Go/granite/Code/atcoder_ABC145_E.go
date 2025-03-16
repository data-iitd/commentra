
// Import necessary Go utility packages
import (
    "bufio"
    "fmt"
    "os"
    "sort"
    "strconv"
    "strings"
)

// Main function to start the program
func main() {
    // Initialize a scanner object to read input from the console
    scanner := bufio.NewScanner(os.Stdin)

    // Read the number of activities N and the time limit T from the console
    scanner.Scan()
    N, _ := strconv.Atoi(scanner.Text())
    scanner.Scan()
    T, _ := strconv.Atoi(scanner.Text())

    // Initialize a 2D slice AB to store the start time and value of each activity
    AB := make([][]int, N)

    // Read the start time and value of each activity from the console and store it in the AB slice
    for i := 0; i < N; i++ {
        scanner.Scan()
        line := strings.Split(scanner.Text(), " ")
        AB[i] = make([]int, 2)
        AB[i][0], _ = strconv.Atoi(line[0]) // Read the start time of activity i
        AB[i][1], _ = strconv.Atoi(line[1]) // Read the value of activity i
    }

    // Sort the AB slice based on the start time of each activity
    sort.Slice(AB, func(i, j int) bool {
        return AB[i][0] < AB[j][0]
    })

    // Initialize a 2D slice dp to store the maximum value that can be obtained up to a certain time after eating an activity
    dp := make([][]int, N+1)
    for i := 0; i <= N; i++ {
        dp[i] = make([]int, 6001)
    }

    // For each activity i from 1 to N, calculate the maximum value that can be obtained up to a certain time after eating the activity
    for i := 1; i <= N; i++ {
        for timeAfterEat := 0; timeAfterEat <= 6000; timeAfterEat++ {
            // Set the value of dp[i][timeAfterEat] to be the maximum of its previous value and the value obtained by eating the activity i at timeAfterEat
            dp[i][timeAfterEat] = max(dp[i][timeAfterEat], dp[i-1][timeAfterEat])

            // If the timeAfterEat is within the time limit T after the start time of activity i, update the value of dp[i][timeAfterEat] with the maximum value that can be obtained by eating activity i at timeAfterEat and adding the value of the activity to the previous value
            time := AB[i-1][0]
            value := AB[i-1][1]
            if timeAfterEat >= time && timeAfterEat < time+T {
                dp[i][timeAfterEat] = max(dp[i][timeAfterEat], dp[i-1][timeAfterEat-time]+value)
            }
        }
    }

    // Print the maximum value that can be obtained after eating all the activities
    fmt.Println(max(dp[N]...))
}

// Function to find the maximum value in a slice of integers
func max(a...int) int {
    m := a[0]
    for _, n := range a {
        if n > m {
            m = n
        }
    }
    return m
}

// End of code

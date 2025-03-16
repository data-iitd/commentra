// Import the fmt module and assign the stdin.ReadLine() function to a variable named input()
import "fmt"

// Read an integer n from the standard input
var n int
fmt.Scan(&n)

// Create a list a of size n by reading n integers from the standard input and applying the map() function to convert each input integer to an integer
a := make([]int, n)
for i := 0; i < n; i++ {
    fmt.Scan(&a[i])
}

// Initialize two variables, pre and ans, to float('inf') and 0, respectively
var pre float64 = float64(^uint(0) >> 1)
var ans int = 0

// Sort the list a in descending order using the sort() method
sort.Sort(sort.Reverse(sort.IntSlice(a)))

// Iterate through the list a using a for loop
for j := 0; j < n; j++ {
    // Calculate the maximum of 0 and the minimum of pre - 1 and a[j]. This value is added to ans.
    ans += int(math.Max(0, math.Min(pre-1, float64(a[j]))))
    
    // Update the value of pre to be the minimum of pre - 1 and a[j].
    pre = math.Min(pre-1, float64(a[j]))
}

// After the loop, print the value of ans.
fmt.Println(ans)


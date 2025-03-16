// Define constants and variables
var ans, mx, sum, mn int64 = 1e8
var cnt int64 = 1

func main() {
    // Input the value of h
    var h int64
    fmt.Scan(&h)

    // Loop to calculate the answer
    for h != 1 {
        if h % 2 != 0 {
            h-- // Decrement h if it is odd
        }
        h /= 2 // Divide h by 2
        cnt *= 2 // Double the count
        ans += cnt // Increment the sum by the current count
    }

    // Output the final result
    fmt.Println(ans + 1)
}



// Function to take input and convert it into list of integers
func main() {
    // Take input of number of test cases and number of elements in each test case
    var n, x int
    fmt.Scan(&n, &x)

    // Initialize an empty list 'a' to store the given elements
    a := make([]int, n)
    for i := range a {
        fmt.Scan(&a[i])
    }

    // Initialize a 2D list 'b' of size n x n with None values
    b := make([][]int, n)
    for i := range b {
        b[i] = make([]int, n)
    }

    // Iterate through each row of list 'a'
    for i := range a {
        // Initialize a variable'm' to store the minimum element in the current row
        m := a[i]

        // Iterate through each column of list 'b'
        for j := range b[i] {
            // Calculate the index 'k' based on the current row and column indices
            k := i - j

            // If the index 'k' is negative, add the size of list 'n' to make it positive
            if k < 0 {
                k += n
            }

            // Update the minimum value of'm' with the minimum value of 'a[k]'
            m = min(m, a[k])

            // Update the corresponding cell in list 'b' with the minimum value of'm'
            b[j][i] = m
        }
    }

    // Initialize a variable'm' with a large value to keep track of the minimum sum
    m := 1000000000
    for i, j := range b {
        // Calculate the sum of elements in the current row and add 'x * i' to it
        sumRow := sum(j) + x*i

        // Update the minimum value of'm' with the sum of the current row
        m = min(m, sumRow)
    }

    // Print the minimum sum
    fmt.Println(m)
}


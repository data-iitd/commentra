// Function to find the greatest common divisor (GCD) of two numbers
func gcd(a, b int) int {
    // Base case: if b is 0, return a as the GCD
    if b == 0 {
        return a
    }
    // Recursive case: find the GCD of b and the remainder of a divided by b
    return gcd(b, a % b)
}

// Function to perform Ruiseki algorithm on a given array
func ruiseki_lr(array []int) ([]int, []int) {
    // Define a helper function to find the GCD of two numbers
    op := func(a, b int) int {
        return gcd(a, b)
    }
    // Initialize empty lists 'left' and 'right' of size 'n+1'
    e := 0
    n := len(array)
    left := make([]int, n+1)
    right := make([]int, n+1)
    // Iterate through the array and calculate the left and right arrays
    for i := 0; i < n; i++ {
        left[i+1] = op(left[i], array[i])
    }
    // Iterate through the array in reverse order and calculate the right arrays
    for i := n-1; i >= 0; i-- {
        right[i] = op(right[i+1], array[i])
    }
    // Return the calculated left and right arrays
    return left, right
}

// Read input from the user: number of elements in the array and the array itself
var n int
fmt.Scanf("%d\n", &n)
var a []int
for i := 0; i < n; i++ {
    var x int
    fmt.Scanf("%d\n", &x)
    a = append(a, x)
}
// Perform Ruiseki algorithm on the given array and get the left and right arrays
left, right := ruiseki_lr(a)
// Initialize answer variable with 0
ans := 0
// Iterate through the array and find the maximum GCD between adjacent elements in the left and right arrays
for i := 0; i < n; i++ {
    ans = max(gcd(left[i], right[i+1]), ans)
}
// Print the final answer
fmt.Printf("%d\n", ans)


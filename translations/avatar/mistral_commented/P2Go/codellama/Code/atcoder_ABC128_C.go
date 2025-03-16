// Define the main function
func main() {
    // Read input: number of test cases, number of lists, and the lists themselves
    import "fmt"
    import "strconv"
    var n, m int
    fmt.Scan(&n, &m)
    li := make([][]int, m)
    for i := 0; i < m; i++ {
        li[i] = make([]int, n)
        for j := 0; j < n; j++ {
            fmt.Scan(&li[i][j])
        }
    }

    // Read input: pattern
    var p []int
    fmt.Scan(&p)

    // Create a set of all elements in the lists
    q := make(map[int]bool)
    for i := 0; i < m; i++ {
        for j := 0; j < n; j++ {
            q[li[i][j]] = true
        }
    }

    // Create a set of numbers from 1 to n (excluding n)
    r := make(map[int]bool)
    for i := 1; i < n+1; i++ {
        r[i] = true
    }

    // Find the set of numbers in r that are not in q
    v := make(map[int]bool)
    for i := 1; i < n+1; i++ {
        if !q[i] {
            v[i] = true
        }
    }

    // Initialize answer to 0
    ans := 0

    // Iterate through all possible subsets of q, from empty to the full set
    for i := 0; i < len(q)+1; i++ {
        // Iterate through all combinations of i elements from q
        for s := range itertools.Combinations(q, i) {
            // Iterate through each list and pattern
            for u, w := range li {
                // Convert s to a set
                s := make(map[int]bool)
                for _, j := range s {
                    s[j] = true
                }
                // Check if the current combination of lists and pattern match the current subset of q
                if len(s & q) % 2 != w {
                    // If not, break out of the inner loop and move on to the next combination
                    break
                }
            }
            // If all combinations of lists and pattern match the current subset of q, increment the answer
            else {
                ans += 2 ** len(v)
            }
        }
    }

    // Print the answer
    fmt.Println(ans)
}

// Run the main function if the script is executed directly
if len(os.Args) > 1 {
    main()
}


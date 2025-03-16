// Define the main function
func main() {
    // Read input: number of test cases, number of lists, and the lists themselves
    n, m := 0, 0
    var li [][]int
    fmt.Scanf("%d %d", &n, &m)
    for i := 0; i < m; i++ {
        var l []int
        fmt.Scanf("%d", &l)
        li = append(li, l[1:])
    }

    // Read input: pattern
    var p []int
    fmt.Scanf("%d", &p)

    // Create a set of all elements in the lists
    q := make(map[int]bool)
    for _, l := range li {
        for _, e := range l {
            q[e] = true
        }
    }

    // Create a set of numbers from 1 to n (excluding n)
    r := make(map[int]bool)
    for i := 1; i < n+1; i++ {
        r[i] = true
    }

    // Find the set of numbers in r that are not in q
    v := make(map[int]bool)
    for i := range r {
        if!q[i] {
            v[i] = true
        }
    }

    // Initialize answer to 0
    ans := 0

    // Iterate through all possible subsets of q, from empty to the full set
    for i := 0; i <= len(q); i++ {
        // Iterate through all combinations of i elements from q
        for _, s := range combinations(q, i) {
            // Iterate through each list and pattern
            for _, u := range li {
                for _, w := range p {
                    // Convert s to a set
                    s := make(map[int]bool)
                    for _, e := range s {
                        s[e] = true
                    }
                    // Check if the current combination of lists and pattern match the current subset of q
                    if len(s & make(map[int]bool) {e: true for e := range u}) % 2!= w {
                        // If not, break out of the inner loop and move on to the next combination
                        break
                    }
                }
            }
            // If all combinations of lists and pattern match the current subset of q, increment the answer
            if len(s) == len(q) {
                ans += 1 << len(v)
            }
        }
    }

    // Print the answer
    fmt.Printf("%d\n", ans)
}

// Return all combinations of i elements from q
func combinations(q map[int]bool, i int) []map[int]bool {
    // Initialize answer to an empty list
    ans := make([]map[int]bool, 0)

    // Iterate through all subsets of q of size i
    for j := 0; j < 1<<len(q); j++ {
        // Initialize a new subset of q
        s := make(map[int]bool)
        for k := 0; k < len(q); k++ {
            if (j & (1 << k))!= 0 {
                s[k] = true
            }
        }
        // If the subset is of size i, append it to the answer
        if len(s) == i {
            ans = append(ans, s)
        }
    }

    // Return the answer
    return ans
}

// Run the main function if the script is executed directly
func main() {
    main()
}


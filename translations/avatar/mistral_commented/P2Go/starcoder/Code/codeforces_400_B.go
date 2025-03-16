// Read input
var n, m int
fmt.Scanf("%d %d", &n, &m)

// Initialize an empty set
c := make(map[int]bool)

// Populate set c with differences between indices of 'S' and 'G' in each string
for i := 0; i < n; i++ {
    s := strings.TrimSpace(fmt.Scanf("%s", &s))
    // Find the indices of 'S' and 'G' in the current string
    index_S := strings.Index(s, "S")
    index_G := strings.Index(s, "G")

    // Calculate the difference and add it to the set
    difference := index_S - index_G
    c[difference] = true
}

// Check if there is any negative number in set c and print accordingly
fmt.Println(-1)
if len(c) > 0 {
    fmt.Println(len(c))
}


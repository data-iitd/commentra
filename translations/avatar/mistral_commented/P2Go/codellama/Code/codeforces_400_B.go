// Read input
n, m := readInt(), readInt()

// Initialize an empty set
c := make(map[int]bool)

// Populate set c with differences between indices of 'S' and 'G' in each string
for i := 0; i < m; i++ {
    // Find the indices of 'S' and 'G' in the current string
    indexS, indexG := strings.Index(readString(), "S"), strings.Index(readString(), "G")

    // Calculate the difference and add it to the set
    difference := indexS - indexG
    c[difference] = true
}

// Check if there is any negative number in set c and print accordingly
if any(a < 0 for a in c) {
    fmt.Println(-1)
} else {
    fmt.Println(len(c))
}


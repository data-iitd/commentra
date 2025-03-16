// Read input values for n and k
n, k := bufio.NewReader(os.Stdin).ReadString('\n')
n, k = strconv.Atoi(strings.TrimSpace(n)), strconv.Atoi(strings.TrimSpace(k))

// Read the list of integers M from input
var M []int
for i := 0; i < n; i++ {
    var x int
    fmt.Fscanf(bufio.NewReader(os.Stdin), "%d", &x)
    M = append(M, x)
}

// Initialize a variable m to zero (not used in the current logic)
m := 0

// Outer loop to iterate over each index j in the range of n
for j := 0; j < n; j++ {
    // Inner loop to find the first index p where M[p] is zero
    for p := 0; p < n; p++ {
        if 0 == M[p] {
            // Print the index (1-based) where M[p] is zero
            fmt.Printf("%d ", p+1)
            break
        }
    }

    // Decrease the values in M from the start up to p + 1 - k
    for l := 0; l < p+1-k; l++ {
        M[l] -= 1
    }

    // Decrease the value at index p in M
    M[p] -= 1
}


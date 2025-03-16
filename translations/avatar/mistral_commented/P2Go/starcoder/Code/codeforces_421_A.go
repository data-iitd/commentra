// Assigning the values of input variables to n, a, and b
var n, a, b int
fmt.Scanf("%d %d %d", &n, &a, &b)

// Creating two lists, lista and listb, from the input
lista := make([]int, n)
listb := make([]int, n)
for i := 0; i < n; i++ {
    fmt.Scanf("%d", &lista[i])
}
for i := 0; i < n; i++ {
    fmt.Scanf("%d", &listb[i])
}

// Iterating through the range of n
for k := 0; k < n; k++ {
    // Checking if k+1 is present in the lista list
    if k+1 == lista[k] {
        // Printing 1 if k+1 is present in the lista list
        fmt.Printf("1 ")
    } else {
        // Printing 2 if k+1 is not present in the lista list
        fmt.Printf("2 ")
    }
}


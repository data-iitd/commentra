// Take input from the user
var n, a []int
fmt.Scanf("%d", &n)
a = make([]int, n)
for i := 0; i < n; i++ {
    fmt.Scanf("%d", &a[i])
}

// Check if the sum of the elements in the list is divisible by the formula
if sum(a)%(n*(n+1)/2)!= 0 {
    fmt.Println("NO")
    return
}

// Calculate the average of the elements in the list
k := sum(a)/(n*(n+1)/2)

// Add the first element to the end of the list for simplification
a = append(a, a[0])

// Check if the differences between consecutive elements (modulo n) or the ratios of the differences to n are valid
if sum([(k-i+j)%n for i, j := range a[1:]])!= 0 || sum([(k-i+j)/n >= 0 for i, j := range a[1:]])!= n {
    fmt.Println("NO")
    return
}

// If all checks pass, print YES
fmt.Println("YES")


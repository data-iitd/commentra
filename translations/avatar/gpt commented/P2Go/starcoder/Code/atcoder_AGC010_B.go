// Read the number of elements and the list of integers from input
n, a := 0, []int{}
fmt.Scanf("%d", &n)
for i := 0; i < n; i++ {
    var x int
    fmt.Scanf("%d", &x)
    a = append(a, x)
}

// Check if the sum of the list 'a' is divisible by the sum of the first n natural numbers
if sum(a)%(n*(n+1)/2)!= 0 {
    // If not divisible, print "NO" and exit
    fmt.Println("NO")
    return
}

// Calculate the average value 'k' that each element should contribute
k := sum(a)/(n*(n+1)/2)

// Append the first element of 'a' to the end of the list to facilitate circular calculations
a = append(a, a[0])

// Check if the sum of the adjusted values is zero and if all adjusted values are non-negative
if sum([(k-i+j)%n for i, j := range a[1:]])!= 0 || sum([(k-i+j)/n >= 0 for i, j := range a[1:]])!= n {
    // If either condition fails, print "NO"
    fmt.Println("NO")
    return
}

// If both conditions are satisfied, print "YES"
fmt.Println("YES")


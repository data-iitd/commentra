// Read two integers n and k from input, where n is the total number of elements 
// and k is the number of smallest elements to sum.
n, k := 0, 0
fmt.Scanf("%d %d", &n, &k)

// Read a list of n integers from input, convert them to integers, and sort the list.
// Then, take the first k elements from the sorted list.
// Finally, calculate the sum of these k smallest elements.
var a []int
for i := 0; i < n; i++ {
    var x int
    fmt.Scanf("%d", &x)
    a = append(a, x)
}
sort.Ints(a)
fmt.Printf("%d\n", sum(a[:k]))


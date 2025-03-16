// Read an integer input which represents the number of elements in the lists
n := int(input())

// Read three lists of integers from input
a := make([]int, n)
b := make([]int, n)
c := make([]int, n)
for i := 0; i < n; i++ {
    a[i], b[i], c[i] = fmt.Scanf("%d", &a[i], &b[i], &c[i])
}

// Initialize variables to hold the sum of each list
x := 0
y := 0
z := 0

// Calculate the sum of elements in list 'a'
for i := 0; i < n; i++ {
    x += a[i]
}

// Calculate the sum of elements in list 'b'
for i := 0; i < n; i++ {
    y += b[i]
}

// Calculate the sum of elements in list 'c'
for i := 0; i < n; i++ {
    z += c[i]
}

// Print the absolute difference between the sums of list 'a' and list 'b'
fmt.Printf("%d\n", abs(x - y))

// Print the absolute difference between the sums of list 'b' and list 'c'
fmt.Printf("%d\n", abs(y - z))


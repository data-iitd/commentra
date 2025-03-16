// Read two integers n and m from input, where n is the number of elements and m is the divisor
n, m := 0, 0
fmt.Scanf("%d %d", &n, &m)

// Read a list of n integers from input
l := make([]int, n)
for i := 0; i < n; i++ {
    fmt.Scanf("%d", &l[i])
}

// Initialize an empty list to store the results after processing the input list
l2 := make([]int, 0)

// Iterate through each element in the input list
for _, i := range l {
    // If the current element is divisible by m, append the quotient to l2
    if i%m == 0 {
        l2 = append(l2, i/m)
    } else {
        l2 = append(l2, (i/m)+1)
    }
}

// Find the maximum value in the processed list l2
mx := 0
for _, i := range l2 {
    if i > mx {
        mx = i
    }
}

// Iterate through the range of n to find the index of the maximum value in l2
for i := 0; i < n; i++ {
    if l2[i] == mx {
        fmt.Printf("%d\n", i+1)
        break
    }
}


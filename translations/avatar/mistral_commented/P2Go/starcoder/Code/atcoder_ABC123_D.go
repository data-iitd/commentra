// Read input: four integers x, y, z, and k followed by x * y integers each for lists a, b, and c
x, y, z, k := 0, 0, 0, 0
fmt.Scanf("%d %d %d %d", &x, &y, &z, &k)

// Initialize an empty list ab to store the sum of each element from list a with each element from list b
ab := make([]int, 0)

// Iterate through each element in list a for i, and for each element in list b for j, append their sum to list ab
for i := 0; i < x; i++ {
    for j := 0; j < y; j++ {
        ab = append(ab, a[i] + b[j])
    }
}

// Sort list ab in descending order
sort.Slice(ab, func(i, j int) bool { return ab[i] > ab[j] })

// Initialize an empty list abc to store the sum of each element from list ab with each element from list c
abc := make([]int, 0)

// Iterate through each valid index i in the range of min(k, x * y), and for each index j in the range of z, append their sum to list abc
for i := 0; i < min(k, x * y); i++ {
    for j := 0; j < z; j++ {
        abc = append(abc, ab[i] + c[j])
    }
}

// Sort list abc in descending order
sort.Slice(abc, func(i, j int) bool { return abc[i] > abc[j] })

// Iterate through the first k elements of list abc and print each element
for i := 0; i < k; i++ {
    fmt.Println(abc[i])
}


// Take the number of rows as input
n := int(input())

// Initialize an empty list's' to store the rows
s := make([][]int, n)

// Read each row and append it to the list's'
for i := 0; i < n; i++ {
    // Read a row as a string and convert it to a list
    k := strings.Split(input(), " ")
    // Append the list to the list's'
    s[i] = make([]int, len(k))
    for j := 0; j < len(k); j++ {
        s[i][j], _ = strconv.Atoi(k[j])
    }
}

// Initialize flags and empty lists 'd1' and 'd2'
flag := 0
d1 := make([]int, n)
d2 := make([]int, n)

// Iterate through each element in the list's'
for i := 0; i < n; i++ {
    // Iterate through each element in the same row and in the reverse order
    for j := 0; j < n; j++ {
        // If the current indices are same, append the element to 'd1'
        if i == j {
            d1[i] = s[i][j]
        }
        // If the current indices are reverse of each other, append the element to 'd2'
        if i == n-j-1 {
            d2[i] = s[i][j]
        }
    }
}

// Check if the size of'rem' set is not equal to 1
if len(rem)!= 1 {
    // If the condition is true, print 'NO' and exit
    fmt.Println("NO")
    os.Exit(0)
}

// Check if 'd1' and 'd2' lists are equal
for i := 0; i < n; i++ {
    if d1[i]!= d2[i] {
        // If the condition is true, print 'NO' and exit
        fmt.Println("NO")
        os.Exit(0)
    }
}

// Check if all elements in 'd1' are same
if len(set(d1))!= 1 {
    // If the condition is true, print 'NO' and exit
    fmt.Println("NO")
    os.Exit(0)
}

// Check if all elements in 'd1' are present in'rem' set
if set(d1) == rem {
    // If the condition is true, print 'NO' and exit
    fmt.Println("NO")
    os.Exit(0)
}

// If all the above conditions are false, print 'YES'
fmt.Println("YES")


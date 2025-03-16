// Take input string 'soz' from the user
soz := input()

// Initialize an array 'a' of size 'len(soz)+1' with zeros
a := make([]int, len(soz)+1)

// Iterate through the string 'soz' starting from index 1
for i := 1; i < len(soz); i++ {
    // Assign the value of the previous index to the current index
    a[i] = a[i-1]
    
    // If the current character is same as the previous character, increment the count
    if soz[i-1] == soz[i] {
        a[i] += 1
    }
}

// Take the number of test cases 'n' as input
n := input()

// Initialize an empty list 'arr' to store the differences
arr := make([]int, 0)

// Iterate through the test cases
for i := 0; i < n; i++ {
    // Take two integers 'm' and 'l' as input, separated by a space
    m, l := input().split()
    
    // Calculate the difference between the count at index 'l' and index 'm'
    arr = append(arr, a[int(l)-1] - a[int(m)-1])
}

// Iterate through the list 'arr' and print each difference
for _, i := range arr {
    fmt.Println(i)
}


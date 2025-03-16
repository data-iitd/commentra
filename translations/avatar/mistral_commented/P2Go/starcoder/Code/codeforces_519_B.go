// Take the number of test cases as input
n := int(input())

// Read the first list 'a' of numbers from the standard input
a := make([]int, n)
for i := 0; i < n; i++ {
    a[i], _ = strconv.Atoi(input())
}

// Read the second list 'b' of numbers from the standard input
b := make([]int, n)
for i := 0; i < n; i++ {
    b[i], _ = strconv.Atoi(input())
}

// Read the third list 'c' of numbers from the standard input
c := make([]int, n)
for i := 0; i < n; i++ {
    c[i], _ = strconv.Atoi(input())
}

// Initialize variables x, y, and z to 0
x := 0
y := 0
z := 0

// Iterate through each number in list 'a' and add it to the variable 'x'
for _, v := range a {
    x += v
}

// Iterate through each number in list 'b' and add it to the variable 'y'
for _, v := range b {
    y += v
}

// Iterate through each number in list 'c' and add it to the variable 'z'
for _, v := range c {
    z += v
}

// Print the absolute difference between 'x' and 'y'
fmt.Println(abs(x - y))

// Print the absolute difference between 'y' and 'z'
fmt.Println(abs(y - z))


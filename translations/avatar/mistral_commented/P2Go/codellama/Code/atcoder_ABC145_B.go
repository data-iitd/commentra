// Read an integer value from the user
n, _ := strconv.Atoi(input())

// Read a string value from the user
s := input()

// Check if n is odd
if n % 2 != 0 {
    fmt.Println("No")
}

// Check if the first half of the string is equal to the second half
if s[:n/2] == s[n/2:] {
    fmt.Println("Yes")
}

// If the first half is not equal to the second half, print 'No'
else {
    fmt.Println("No")
}


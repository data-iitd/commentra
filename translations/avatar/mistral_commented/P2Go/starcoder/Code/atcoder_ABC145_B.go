// Read an integer value from the user
n, err := strconv.Atoi(os.Stdin.ReadString('\n'))
if err!= nil {
    log.Fatal(err)
}

// Read a string value from the user
s := bufio.NewReader(os.Stdin).ReadString('\n')

// Check if n is odd
if n%2!= 0 {
    fmt.Println("No")
}

// Check if the first half of the string is equal to the second half
if s[:int(n/2)] == s[int(n/2):] {
    fmt.Println("Yes")
}

// If the first half is not equal to the second half, print 'No'
else {
    fmt.Println("No")
}


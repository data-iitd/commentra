// Read input from the user
l := bufio.NewReader(os.Stdin)
var s string
var p string
var i int
fmt.Fscanln(l, &s, &p)
i = int(p[0])

// Check if the last character of the first part is '9'
if s[len(s)-1] == '9' {
    // If it is '9', print the message "GOTO Vasilisa."
    fmt.Println("GOTO Vasilisa.")
} else if s[len(s)-1]!= '9' && i < 5 {
    // If both conditions are true, join the list of characters into a string and print it
    fmt.Println(strings.Join(s, ""))
} else {
    // If the last character is not '9' and i is 5 or more
    // Join the list of characters into a string, convert it to an integer, increment it by 1, and convert it back to a string
    s = strings.Join(s, "")
    s = strconv.Itoa(int(s) + 1)
    // Print the incremented value
    fmt.Println(s)
}


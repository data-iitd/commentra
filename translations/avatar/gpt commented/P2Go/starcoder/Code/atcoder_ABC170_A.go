// Read a line of input, split it into components, and convert each component to an integer
a := strings.Split(bufio.NewReader(os.Stdin).ReadString(), " ")
a = make([]int, len(a))
for i, v := range a {
    a[i], _ = strconv.Atoi(v)
}

// Iterate over the list 'a' using 'range' to get both the index (e) and the value (i)
for e, i := range a {
    // Check if the current value is zero
    if i == 0 {
        // Print the index (1-based) of the first occurrence of zero
        fmt.Println(e + 1)
        // Exit the loop after finding the first zero
        break
    }
}


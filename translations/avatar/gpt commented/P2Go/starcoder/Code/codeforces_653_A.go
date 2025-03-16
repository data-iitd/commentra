// Read an integer input which represents the number of elements in the list
n, err := strconv.Atoi(os.Stdin.ReadString('\n'))
if err!= nil {
    log.Fatal(err)
}

// Read a line of input, split it into individual string elements, convert them to integers, and store them in a list
l := make([]int, n)
for i := 0; i < n; i++ {
    l[i], err = strconv.Atoi(os.Stdin.ReadString('\n'))
    if err!= nil {
        log.Fatal(err)
    }
}

// Sort the list in ascending order
sort.Ints(l)

// Iterate through each element in the sorted list
for i := 0; i < len(l); i++ {
    // Check if both i + 1 and i + 2 exist in the list
    if l[i]+1 < len(l) && l[i]+2 < len(l) {
        // If the condition is met, print 'YES' and exit the loop
        fmt.Println("YES")
        break
    }
} else {
    // If the loop completes without finding the condition, print 'NO'
    fmt.Println("NO")
}


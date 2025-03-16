// Read an integer input which represents the number of elements in the list
n, _ := strconv.Atoi(input())

// Read a line of input, split it into individual string elements, convert them to integers, and store them in a list
l := strings.Split(input(), " ")

// Sort the list in ascending order
sort.Ints(l)

// Iterate through each element in the sorted list
for _, i := range l {
    // Check if both i + 1 and i + 2 exist in the list
    if (i + 1) in l && (i + 2) in l {
        // If the condition is met, print 'YES' and exit the loop
        fmt.Println("YES")
        break
    }
}

// If the loop completes without finding the condition, print 'NO'
fmt.Println("NO")


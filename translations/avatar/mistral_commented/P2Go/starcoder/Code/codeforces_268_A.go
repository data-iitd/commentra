// Ask user for the number of arrays (n) they want to input
n := int(input())

// Create an empty list called 'q' to store these arrays
q := []string{}

// Use a for loop to iterate through the range of 'n' and for each iteration,
// ask the user for an array (a) and append it to our list 'q'
for i := 0; i < n; i++ {
    // Ask user for an array (a)
    a := strings.Split(input(), " ")
    // Append array 'a' to our list 'q'
    q = append(q, a)
}

// Use another for loop to iterate through each array in our list 'q'
for j := range q {
    // For each array 'j', use another for loop to iterate through every other array in our list 'q'
    for k := range q {
        // Exclude the current array 'j' from comparison using 'continue' statement if they are the same
        if j == k {
            continue
        }
        // Check if the last element of the second array 'k' matches the first element of the first array 'j'
        if q[j][0] == q[k][len(q[k])-1] {
            // If it does, increment our 'count' variable
            count++
        }
    }
}

// Finally, print out the value of our 'count' variable
fmt.Println(count)


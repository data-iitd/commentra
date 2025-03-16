// Ask user for the number of elements in the list
n := int(input())

// Get the list of numbers from user input
number := strings.Split(input(), " ")

// Initialize variables h1 and h2 to 0
h1 := 0
h2 := 0

// Iterate through the list of numbers
for i := 0; i < n; i++ {
    // Check if the current number is not 4 and not 7
    if number[i]!= "4" && number[i]!= "7" {
        // Print "NO" and break the loop if the condition is met
        fmt.Println("NO")
        break
    }

    // If the index is less than half the length of the list, add the number to h1
    if i < n/2 {
        h1 += int(number[i])
    }

    // If the index is greater than or equal to half the length of the list, add the number to h2
    else {
        h2 += int(number[i])
    }
}

// Check if the loop was broken due to a non-4 and non-7 number
if h1 == h2 {
    // If h1 and h2 are equal, print "YES"
    fmt.Println("YES")
}

// If h1 and h2 are not equal, print "NO"
else {
    fmt.Println("NO")
}


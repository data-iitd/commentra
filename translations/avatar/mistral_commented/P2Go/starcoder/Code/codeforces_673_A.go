// Take the number of elements in the list as input
n := int(input())

// Initialize an empty list 'arr' to store the input elements
arr := make([]int, n)

// Read the input elements into the list
for i := 0; i < n; i++ {
    arr[i], _ = strconv.Atoi(input())
}

// Check if the first element of the list is greater than 15
if arr[0] > 15 {
    // If it is, print 15
    fmt.Println(15)
} else {
    // Else, iterate through the list starting from the second element
    for i := 1; i < len(arr); i++ {
        // Check if the difference between the current and previous elements is greater than 15
        if arr[i] - arr[i-1] > 15 {
            // If it is, print the index of the previous element and add 15 to it
            fmt.Println(arr[i-1] + 15)
            // Break the loop as we have found the answer
            break
        }
    }
    // Else, if we reach here, it means that no difference was greater than 15
    else {
        // Check if the last element of the list is 90 or if adding 15 to it results in 90 or more
        if arr[len(arr)-1] == 90 || arr[len(arr)-1] + 15 >= 90 {
            // If it is, print 90
            fmt.Println(90)
        } else {
            // Else, print the last element plus 15
            fmt.Println(arr[len(arr)-1] + 15)
        }
    }
}


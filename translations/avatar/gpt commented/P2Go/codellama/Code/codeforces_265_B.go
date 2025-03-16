// Read the number of elements from user input
n, _ := strconv.Atoi(input())

// Initialize an empty list to store the elements
l := make([]int, 0)

// Loop to read 'n' integers from user input and append them to the list
for i := 0; i < n; i++ {
    l = append(l, input())
}

// Initialize the answer variable to n - 1 (to account for n-1 gaps between n elements)
ans := n - 1

// Initialize a variable to keep track of the last element processed
last := 0

// Loop through each element in the list
for _, i := range l {
    // Calculate the distance from the last element to the current element
    // and add 1 for the step to the current element
    ans += abs(last - i) + 1
    
    // Update 'last' to the current element for the next iteration
    last = i
}

// Print the final calculated answer
fmt.Println(ans)


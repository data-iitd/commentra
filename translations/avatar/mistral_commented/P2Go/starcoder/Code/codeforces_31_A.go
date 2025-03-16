// Take an integer input from the user
y := int(input())

// Take a list of integers as input from the user
arr := []int{}
for _, v := range strings.Fields(input()) {
    arr = append(arr, int(v))
}

// Iterate through each index 'i' in the list 'arr'
for i := 0; i < len(arr); i++ {
    // Iterate through each index 'j' in the list 'arr' (excluding the current index 'i')
    for j := 0; j < len(arr); j++ {
        // Check if the current indices 'i' and 'j' are equal, if yes then skip the current iteration
        if i == j {
            continue
        }
        // Iterate through each index 'k' in the list 'arr' (excluding the indices 'i' and 'j')
        for k := 0; k < len(arr); k++ {
            // Check if the current indices 'i', 'j' and 'k' satisfy the given condition
            if arr[k]!= arr[j] && arr[k]!= arr[i] && arr[k] == arr[i] + arr[j] {
                // If the condition is true, print the indices 'i', 'j' and 'k' and exit the function
                fmt.Printf("%d %d %d\n", k+1, j+1, i+1)
                return
            }
        }
    }
}
// If no such indices are found, print -1
fmt.Println(-1)


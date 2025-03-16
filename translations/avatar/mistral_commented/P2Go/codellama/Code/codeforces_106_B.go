// Define the number of items in the input array
n := 0

// Initialize an empty list to store the input data
input_array := make([][4]int, 0)

// Read n items from the standard input and append them to the input_array
for i := 0; i < n; i++ {
    var s, r, h, c int
    fmt.Scan(&s, &r, &h, &c)
    input_array = append(input_array, [4]int{s, r, h, c})
}

// Initialize an empty list to store the outdated items
outdated := make([][4]int, 0)

// Check for outdated items in the input array
for i := 0; i < n; i++ {
    for j := 0; j < n; j++ {
        // Check if the current item is older and smaller than the next one
        if (input_array[i][0] < input_array[j][0] &&
            input_array[i][1] < input_array[j][1] &&
            input_array[i][2] < input_array[j][2]) {
            // Append the current item to the outdated list
            outdated = append(outdated, input_array[i])
        }
    }
}

// Convert the outdated list to a set to remove duplicates
outdated_set := make(map[int]bool)
for _, item := range outdated {
    outdated_set[item[0]] = true
}

// Initialize minimum_cost and input_number to large initial values
minimum_cost := 100000
input_number := 0

// Find the item with the minimum cost that is not outdated
for i := 0; i < n; i++ {
    current_item := input_array[i]
    cost := current_item[3]
    // Check if the current item is not outdated and has a smaller cost than minimum_cost
    if (current_item[0] != outdated_set[current_item[0]] && cost < minimum_cost) {
        // Update minimum_cost and input_number
        minimum_cost = cost
        input_number = i + 1
    }
}

// Print the index of the item with the minimum cost that is not outdated
fmt.Println(input_number)


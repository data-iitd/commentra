// Read the number of items from user input
n := int(input())

// Initialize an empty list to store the input items
input_array := []

// Loop to read each item's attributes (S, R, H, C)
for i := 0; i < n; i++ {
    // Read the attributes S, R, H, C and convert them to integers
    s, r, h, c := strings.Split(input(), " ")
    s, r, h, c := strconv.Atoi(s), strconv.Atoi(r), strconv.Atoi(h), strconv.Atoi(c)
    // Append the attributes as a tuple to the input_array
    input_array = append(input_array, []int{s, r, h, c})
}

// Initialize a list to keep track of outdated items
outdated := []

// Compare each item with every other item to find outdated ones
for i := 0; i < n; i++ {
    for j := 0; j < n; j++ {
        // Check if item i is outdated compared to item j
        if input_array[i][0] < input_array[j][0] && input_array[i][1] < input_array[j][1] && input_array[i][2] < input_array[j][2] {
            // If outdated, add item i to the outdated list
            outdated = append(outdated, input_array[i])
        }
    }
}

// Convert the outdated list to a set to remove duplicates
outdated = append(outdated)
outdated = make(map[int]bool)

// Initialize variables to track the minimum cost and corresponding item index
minimum_cost := 100000
input_number := 0

// Loop through the input items to find the one with the minimum cost that is not outdated
for i := 0; i < n; i++ {
    current_item := input_array[i]
    cost := current_item[3]  // Get the cost of the current item
    // Check if the current item is not outdated and has a lower cost than the current minimum
    if current_item not in outdated && cost < minimum_cost {
        minimum_cost = current_item[3]  // Update the minimum cost
        input_number = i + 1  // Store the index of the current item (1-based index)
}

// Print the index of the item with the minimum cost that is not outdated
fmt.Println(input_number)


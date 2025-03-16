// Read two integers n and d from input
n, d := 0, 0
fmt.Scanf("%d %d", &n, &d)

// Initialize an empty list to store the elements
x := []int{}
// Initialize variables to keep track of the total adjustments (m) and the current adjustment count (q)
m, q := 0, 0

// Read the elements of the list from input and split them into individual strings
x_temp := strings.Split(fmt.Sprintf("%v", readLine()), " ")

// Convert the list of strings into a list of integers
for i := 0; i < len(x_temp); i++ {
    x_item := strconv.Atoi(x_temp[i])
    x = append(x, x_item)
}

// Iterate through the list to compare adjacent elements
for a := 0; a < len(x) - 1; a++ {
    // Check if the current element is greater than or equal to the next element
    if x[a] >= x[a + 1] {
        // Calculate how many increments of d are needed to make x[a + 1] greater than x[a]
        q = int((x[a] - x[a + 1]) / d + 1)
        // Update the total adjustments made
        m = m + q
        // Adjust the next element by adding the necessary increments of d
        x[a + 1] = x[a + 1] + q * d
}

// Print the total number of adjustments made
fmt.Printf("%v\n", m)


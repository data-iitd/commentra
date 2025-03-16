// Read input values for x, y, a, and b and convert them to integers
x, y, a, b := strconv.Atoi(os.Args[1])

// Initialize an empty list to store valid game pairs
games := [][2]int{}

// Iterate over the range from a to x (inclusive)
for i := a; i <= x; i++ {
    // Skip the iteration if i is less than or equal to b
    if i <= b {
        continue
    }

    // Iterate over the range from b to y (inclusive)
    for j := b; j <= y; j++ {
        // Check if the current i is greater than j
        if i > j {
            // If the condition is met, append the pair (i, j) to the games list
            games = append(games, [2]int{i, j})
        }
    }
}

// Print the total number of valid game pairs found
fmt.Println(len(games))

// Print each valid game pair
for _, game := range games {
    fmt.Printf("%d %d\n", game[0], game[1])
}


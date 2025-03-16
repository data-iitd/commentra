// Get user input as a string and convert it to a list of integers
x, y, a, b := strings.Split(fmt.Scanf("%d %d %d %d"), " ")
// Initialize an empty list to store the games
games := []

// Iterate through a range of numbers from a to x+1
for i := a; i <= x+1; i++ {
    // If i is less than or equal to b, skip to the next iteration
    if i <= b {
        continue
    }
    // Iterate through a range of numbers from b to y+1
    for j := b; j <= y+1; j++ {
        // If i is greater than j, append the tuple (i, j) to the games list
        if i > j {
            games = append(games, []int{i, j})
        }
    }
}

// Print the length of the games list
fmt.Println(len(games))
// Iterate through the games list and print each tuple
for _, i := range games {
    // Print the tuple as a string in the format "i j"
    fmt.Printf("%d %d\n", i[0], i[1])
}


// Read the number of lines (n) from user input
n := int(input())

// Initialize a list to store the cake representation and variables for happiness and chocolate count
cake := make([]string, n)
happiness := 0
chocCount := 0
nfat := 1

// Process each line of cake input
for i := 0; i < n; i++ {
    // Read a line of cake representation
    fmt.Scanln(&cake[i])
    
    // Count the number of chocolates ('C') in the current line
    for j := 0; j < len(cake[i]); j++ {
        if (cake[i][j] == 'C') {
            chocCount += 1
        }
    }
    
    // If there are more than one chocolate, calculate the happiness contribution
    if (chocCount > 1) {
        // Calculate the factorial of (chocCount - 1) and (chocCount - 2)
        for i := chocCount; i > chocCount - 2; i-- {
            nfat *= i
        }
        // Update happiness based on the calculated factorial
        happiness += nfat / 2
    }
    
    // Reset variables for the next line
    nfat = 1
    chocCount = 0
}

// Initialize a counter for vertical chocolate counting
posCount := 0

// Count chocolates in each column of the cake
for j := 0; j < n; j++ {
    for i := 0; i < n; i++ {
        // Count the number of chocolates ('C') in the current column
        if (cake[i][j] == 'C') {
            chocCount += 1
        }
    }
    
    // If there are more than one chocolate in the column, calculate the happiness contribution
    if (chocCount > 1) {
        // Calculate the factorial of (chocCount - 1) and (chocCount - 2)
        for i := chocCount; i > chocCount - 2; i-- {
            nfat *= i
        }
        // Update happiness based on the calculated factorial
        happiness += nfat / 2
    }
    
    // Reset variables for the next column
    nfat = 1
    chocCount = 0
}

// Print the total happiness as an integer
fmt.Println(int(happiness))


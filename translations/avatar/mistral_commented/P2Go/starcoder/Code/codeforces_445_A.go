// Define the number of rows (n) and columns (m) of the grid
n, m := 0, 0
fmt.Scanf("%d %d", &n, &m)

// Initialize an empty list 'l' to store the rows of the grid
l := make([][]byte, n)

// Iterate through each row 'i' in the grid
for i := 0; i < n; i++ {
    // Read the row as a string from user input
    row := make([]byte, m)
    fmt.Scanf("%s", &row)

    // Iterate through each cell 'j' in the row
    for j := 0; j < m; j++ {
        
        // If the cell contains a '.', assign it a color based on its position in the grid
        if row[j] == '.' {
            if (i + j) % 2 == 1 {  // If the row index and column index have different parity
                row[j] = 'W'   // Assign the cell the color 'W'
            } else {
                row[j] = 'B'   // Assign the cell the color 'B'
            }
        }
    }

    // Append the processed row to the list 'l'
    l[i] = row
}

// Print each row of the grid
for _, row := range l {
    fmt.Printf("%s\n", string(row))
}


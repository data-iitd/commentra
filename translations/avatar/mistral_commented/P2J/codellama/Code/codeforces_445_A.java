// Define the number of rows (n) and columns (m) of the grid
int n, m;

// Initialize an empty list 'l' to store the rows of the grid
List<String> l = new ArrayList<>();

// Iterate through each row 'i' in the grid
for (int i = 0; i < n; i++) {
    // Read the row as a string from user input
    String row = scanner.nextLine();
    
    // Convert the row string into a list for further processing
    List<Character> rowList = new ArrayList<>();
    for (int j = 0; j < row.length(); j++) {
        rowList.add(row.charAt(j));
    }

    // Iterate through each cell 'j' in the row
    for (int j = 0; j < m; j++) {
        
        // If the cell contains a '.', assign it a color based on its position in the grid
        if (rowList.get(j) == '.') {
            if ((i + j) % 2 == 0) {  // If the row index and column index have different parity
                rowList.set(j, 'W');   // Assign the cell the color 'W'
            } else {
                rowList.set(j, 'B');   // Assign the cell the color 'B'
            }
        }
    }

    // Append the processed row to the list 'l'
    l.add(rowList.toString());
}

// Print each row of the grid
for (String row : l) {
    System.out.println(row);
}


// Read two integers n and m from input, representing the number of rows and columns
Scanner sc = new Scanner(System.in);
int n = sc.nextInt();
int m = sc.nextInt();

// Initialize an empty list to store the resulting grid
List<String> l = new ArrayList<>();

// Iterate over each row index i from 0 to n-1
for (int i = 0; i < n; i++) {
    // Read a string input for the current row
    String s = sc.next();
    // Convert the string into a list of characters for mutability
    char[] sArr = s.toCharArray();
    
    // Iterate over each column index j from 0 to m-1
    for (int j = 0; j < m; j++) {
        // Check if the current cell is empty (represented by '.')
        if (sArr[j] == '.') {
            // Assign 'W' or 'B' based on the parity of the sum of indices (i + j)
            if ((i + j) % 2 == 1) {
                sArr[j] = 'W';  // Assign 'W' for odd sums
            } else {
                sArr[j] = 'B';  // Assign 'B' for even sums
            }
        }
    }
    
    // Append the modified row (as a string) to the grid
    l.add(new String(sArr));
}

// Print each row of the grid as a string
for (String c : l) {
    System.out.println(c);
}


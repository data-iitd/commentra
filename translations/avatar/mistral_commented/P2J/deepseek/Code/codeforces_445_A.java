public class GridColoring {
    public static void main(String[] args) {
        // Define the number of rows (n) and columns (m) of the grid
        int n, m;
        String[] nm = System.console().readLine().split(" ");
        n = Integer.parseInt(nm[0]);
        m = Integer.parseInt(nm[1]);

        // Initialize an empty list 'l' to store the rows of the grid
        char[][] l = new char[n][m];

        // Iterate through each row 'i' in the grid
        for (int i = 0; i < n; i++) {
            // Read the row as a string from user input
            String row = System.console().readLine();

            // Convert the row string into a list for further processing
            char[] rowArray = row.toCharArray();

            // Iterate through each cell 'j' in the row
            for (int j = 0; j < m; j++) {
                // If the cell contains a '.', assign it a color based on its position in the grid
                if (rowArray[j] == '.') {
                    if ((i + j) % 2 == 1) {  // If the row index and column index have different parity
                        rowArray[j] = 'W';   // Assign the cell the color 'W'
                    } else {
                        rowArray[j] = 'B';   // Assign the cell the color 'B'
                    }
                }
            }

            // Append the processed row to the list 'l'
            l[i] = rowArray;
        }

        // Print each row of the grid
        for (int i = 0; i < n; i++) {
            System.out.println(new String(l[i]));
        }
    }
}

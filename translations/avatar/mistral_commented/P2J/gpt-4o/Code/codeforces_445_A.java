import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class GridColoring {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Define the number of rows (n) and columns (m) of the grid
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character
        
        // Initialize a list to store the rows of the grid
        List<String> grid = new ArrayList<>();
        
        // Iterate through each row 'i' in the grid
        for (int i = 0; i < n; i++) {
            // Read the row as a string from user input
            String row = scanner.nextLine();
            char[] rowArray = row.toCharArray(); // Convert the row string into a char array
            
            // Iterate through each cell 'j' in the row
            for (int j = 0; j < m; j++) {
                // If the cell contains a '.', assign it a color based on its position in the grid
                if (rowArray[j] == '.') {
                    if ((i + j) % 2 == 1) { // If the row index and column index have different parity
                        rowArray[j] = 'W'; // Assign the cell the color 'W'
                    } else {
                        rowArray[j] = 'B'; // Assign the cell the color 'B'
                    }
                }
            }
            
            // Append the processed row to the list 'grid'
            grid.add(new String(rowArray));
        }
        
        // Print each row of the grid
        for (String row : grid) {
            System.out.println(row);
        }
        
        scanner.close();
    }
}
// <END-OF-CODE>

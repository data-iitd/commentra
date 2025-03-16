import java.util.Scanner;

public class CakeHappiness {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of lines (n) from user input
        int n = Integer.parseInt(scanner.nextLine());
        
        // Initialize a list to store the cake representation and variables for happiness and chocolate count
        String[] cake = new String[n];
        double happiness = 0;
        
        // Process each line of cake input
        for (int i = 0; i < n; i++) {
            // Read a line of cake representation
            cake[i] = scanner.nextLine();
            
            // Count the number of chocolates ('C') in the current line
            int chocCount = 0;
            for (char j : cake[i].toCharArray()) {
                if (j == 'C') {
                    chocCount++;
                }
            }
            
            // If there are more than one chocolate, calculate the happiness contribution
            if (chocCount > 1) {
                // Calculate the factorial of (chocCount - 1) and (chocCount - 2)
                double nfat = 1;
                for (int k = chocCount; k > chocCount - 2; k--) {
                    nfat *= k;
                }
                // Update happiness based on the calculated factorial
                happiness += nfat / 2;
            }
        }
        
        // Count chocolates in each column of the cake
        for (int j = 0; j < n; j++) {
            int chocCount = 0;
            for (int i = 0; i < n; i++) {
                // Count the number of chocolates ('C') in the current column
                if (cake[i].charAt(j) == 'C') {
                    chocCount++;
                }
            }
            
            // If there are more than one chocolate in the column, calculate the happiness contribution
            if (chocCount > 1) {
                // Calculate the factorial of (chocCount - 1) and (chocCount - 2)
                double nfat = 1;
                for (int k = chocCount; k > chocCount - 2; k--) {
                    nfat *= k;
                }
                // Update happiness based on the calculated factorial
                happiness += nfat / 2;
            }
        }
        
        // Print the total happiness as an integer
        System.out.println((int) happiness);
        
        scanner.close();
    }
}
// <END-OF-CODE>

import java.util.Scanner;

public class ChocolateHappiness {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();  // Take the size of the cake as input
        char[][] cake = new char[n][n];  // Initialize a 2D array to store the rows of the cake
        int happiness = 0;  // Initialize the happiness score to 0
        int chocCount = 0;  // Initialize the chocolate count to 0
        int nfat = 1;  // Initialize nfat to 1 for calculating factorial

        // Loop through each row of the cake
        for (int i = 0; i < n; i++) {
            String line = scanner.next();  // Take each row as input
            cake[i] = line.toCharArray();  // Convert the row to a char array and store it in the cake array
            for (char j : cake[i]) {  // Loop through each character in the row
                if (j == 'C') {  // If the character is a chocolate
                    chocCount++;  // Increment the chocolate count
                }
            }
            if (chocCount > 1) {  // If there is more than one chocolate in the row
                // Calculate the factorial of chocCount and update happiness
                for (int j = chocCount; j > chocCount - 2; j--) {
                    nfat *= j;
                }
                happiness += nfat / 2;
            }
            nfat = 1;  // Reset nfat to 1
            chocCount = 0;  // Reset chocCount to 0
        }

        // Loop through each column of the cake
        for (int j = 0; j < n; j++) {
            chocCount = 0;  // Reset the chocolate count for each column
            for (int i = 0; i < n; i++) {
                if (cake[i][j] == 'C') {  // If the character is a chocolate
                    chocCount++;  // Increment the chocolate count
                }
            }
            if (chocCount > 1) {  // If there is more than one chocolate in the column
                // Calculate the factorial of chocCount and update happiness
                for (int i = chocCount; i > chocCount - 2; i--) {
                    nfat *= i;
                }
                happiness += nfat / 2;
            }
            nfat = 1;  // Reset nfat to 1
            chocCount = 0;  // Reset chocCount to 0
        }

        System.out.println(happiness);  // Print the integer value of happiness
    }
}

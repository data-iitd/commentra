import java.util.Scanner;

public class ChocolateHappiness {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();  // Read the number of lines in the input
        char[][] cake = new char[n][n];  // Initialize a 2D array to store each line
        int happiness = 0;  // Initialize happiness variable to zero
        int chocCount = 0;  // Initialize chocolate count variable to zero
        int nfat = 1;  // Initialize nFAT variable to 1

        for (int i = 0; i < n; i++) {  // Iterate through each line in the input
            String line = scanner.next();  // Read a line and convert it to a string
            for (int j = 0; j < n; j++) {  // Iterate through each character in the line
                cake[i][j] = line.charAt(j);  // Store the character in the 2D array
            }
        }

        for (int i = 0; i < n; i++) {  // Iterate through each line in the cake
            chocCount = 0;  // Reset chocolate count to zero
            for (int j = 0; j < n; j++) {  // Iterate through each character in the line
                if (cake[i][j] == 'C') {  // If the character is 'C', increment chocolate count
                    chocCount++;
                }
            }
            if (chocCount > 1) {  // If there are more than one 'C' in the line
                nfat = 1;  // Reset nFAT to 1
                for (int k = chocCount; k > chocCount - 2; k--) {  // Calculate nFAT using the chocolate count
                    nfat *= k;
                }
                happiness += nfat / 2;  // Add happiness based on the nFAT value
            }
        }

        for (int j = 0; j < n; j++) {  // Iterate through each column in the cake
            chocCount = 0;  // Reset chocolate count to zero
            for (int i = 0; i < n; i++) {  // Iterate through each line in the cake
                if (cake[i][j] == 'C') {  // If the character at the position (i,j) is 'C', increment chocolate count
                    chocCount++;
                }
            }
            if (chocCount > 1) {  // If there are more than one 'C' in the column
                nfat = 1;  // Reset nFAT to 1
                for (int k = chocCount; k > chocCount - 2; k--) {  // Calculate nFAT using the chocolate count
                    nfat *= k;
                }
                happiness += nfat / 2;  // Add happiness based on the nFAT value
            }
        }

        System.out.println(happiness);  // Print the final happiness value
    }
}

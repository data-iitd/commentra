import java.util.Scanner;

public class CakeHappiness {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = Integer.parseInt(scanner.nextLine());  // Read the number of lines in the input
        String[] cake = new String[n];                  // Initialize an array to store each line
        double happiness = 0;                            // Initialize happiness variable to zero
        int chocCount = 0;                              // Initialize chocolate count variable to zero
        int nfat = 1;                                   // Initialize nFAT variable to 1

        for (int i = 0; i < n; i++) {                  // Iterate through each line in the input
            cake[i] = scanner.nextLine();              // Read a line and store it in the array

            for (char j : cake[i].toCharArray()) {     // Iterate through each character in the line
                if (j == 'C') {                         // If the character is 'C', increment chocolate count
                    chocCount++;
                }
            }

            if (chocCount > 1) {                       // If there are more than one 'C' in the line
                nfat = 1;                              // Reset nFAT to 1
                for (int k = chocCount; k > chocCount - 2; k--) {  // Calculate nFAT using the chocolate count
                    nfat *= k;
                }
                happiness += nfat / 2;                 // Add happiness based on the nFAT value
            }

            chocCount = 0;                             // Reset chocolate count to zero
        }

        chocCount = 0;                                 // Reset chocolate count for column calculation
        for (int j = 0; j < n; j++) {                  // Iterate through each column in the cake
            for (int i = 0; i < n; i++) {              // Iterate through each line in the cake
                if (cake[i].charAt(j) == 'C') {       // If the character at the position (i,j) is 'C', increment chocolate count
                    chocCount++;
                }
            }

            if (chocCount > 1) {                       // If there are more than one 'C' in the column
                nfat = 1;                              // Reset nFAT to 1
                for (int k = chocCount; k > chocCount - 2; k--) {  // Calculate nFAT using the chocolate count
                    nfat *= k;
                }
                happiness += nfat / 2;                 // Add happiness based on the nFAT value
            }

            chocCount = 0;                             // Reset chocolate count to zero
        }

        System.out.println((int) happiness);          // Print the final happiness value as an integer.
        
        scanner.close();                               // Close the scanner
    }
}
// <END-OF-CODE>

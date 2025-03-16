import java.util.Scanner;

public class CakeHappiness {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = Integer.parseInt(scanner.nextLine());  // Take the size of the cake as input
        String[] cake = new String[n];  // Initialize an array to store the rows of the cake
        double happiness = 0;  // Initialize the happiness score to 0
        
        // Loop through each row of the cake
        for (int i = 0; i < n; i++) {
            cake[i] = scanner.nextLine();  // Take each row as input
        }
        
        // Loop through each row of the cake
        for (int i = 0; i < n; i++) {
            int chocCount = 0;  // Initialize the chocolate count to 0
            for (char j : cake[i].toCharArray()) {  // Loop through each character in the row
                if (j == 'C') {  // If the character is a chocolate
                    chocCount++;  // Increment the chocolate count
                }
            }
            if (chocCount > 1) {  // If there is more than one chocolate in the row
                // Calculate the factorial of chocCount and update happiness
                int nfat = 1;  // Initialize nfat to 1 for calculating factorial
                for (int k = chocCount; k > chocCount - 2; k--) {
                    nfat *= k;
                }
                happiness += nfat / 2.0;
            }
        }

        // Loop through each column of the cake
        for (int j = 0; j < n; j++) {
            int chocCount = 0;  // Reset the chocolate count for each column
            for (int i = 0; i < n; i++) {
                if (cake[i].charAt(j) == 'C') {  // If the character is a chocolate
                    chocCount++;  // Increment the chocolate count
                }
            }
            if (chocCount > 1) {  // If there is more than one chocolate in the column
                // Calculate the factorial of chocCount and update happiness
                int nfat = 1;  // Initialize nfat to 1 for calculating factorial
                for (int k = chocCount; k > chocCount - 2; k--) {
                    nfat *= k;
                }
                happiness += nfat / 2.0;
            }
        }

        System.out.println((int) happiness);  // Print the integer value of happiness
        scanner.close();
    }
}
// <END-OF-CODE>

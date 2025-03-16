

import java.util.Scanner;

public class codeforces_629_A{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();  // Take the size of the cake as input
        String[] cake = new String[n];  // Initialize an array to store the rows of the cake
        int happiness = 0;  // Initialize the happiness score to 0
        int chocCount = 0;  // Initialize the chocolate count to 0
        int nfat = 1;  // Initialize nfat to 1 for calculating factorial

        // Loop through each row of the cake
        for (int i = 0; i < n; i++) {
            String line = scanner.next();  // Take each row as input
            cake[i] = line;  // Store the row in the cake array
            for (int j = 0; j < line.length(); j++) {  // Loop through each character in the row
                if (line.charAt(j) == 'C') {  // If the character is a chocolate
                    chocCount++;  // Increment the chocolate count
                }
            }
            if (chocCount > 1) {  // If there is more than one chocolate in the row
                // Calculate the factorial of chocCount and update happiness
                for (int i1 = chocCount; i1 > chocCount - 2; i1--) {
                    nfat *= i1;
                }
                happiness += nfat / 2;
            }
            nfat = 1;  // Reset nfat to 1
            chocCount = 0;  // Reset chocCount to 0
        }

        int posCount = 0;  // Initialize posCount to 0 (not used in the code)

        // Loop through each column of the cake
        for (int j = 0; j < n; j++) {
            chocCount = 0;  // Reset the chocolate count for each column
            for (int i = 0; i < n; i++) {
                if (cake[i].charAt(j) == 'C') {  // If the character is a chocolate
                    chocCount++;  // Increment the chocolate count
                }
            }
            if (chocCount > 1) {  // If there is more than one chocolate in the column
                // Calculate the factorial of chocCount and update happiness
                for (int i1 = chocCount; i1 > chocCount - 2; i1--) {
                    nfat *= i1;
                }
                happiness += nfat / 2;
            }
            nfat = 1;  // Reset nfat to 1
            chocCount = 0;  // Reset chocCount to 0
        }

        System.out.println(happiness);  // Print the happiness score
    }
}

Translate the above Java code to C++ and end with comment "
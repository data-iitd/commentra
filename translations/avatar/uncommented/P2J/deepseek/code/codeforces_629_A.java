import java.util.Scanner;

public class CakeHappiness {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        char[][] cake = new char[n][n];
        int happiness = 0;
        int chocCount = 0;
        int nfat = 1;

        // Read the cake matrix
        for (int i = 0; i < n; i++) {
            String line = scanner.next();
            for (int j = 0; j < n; j++) {
                cake[i][j] = line.charAt(j);
            }
        }

        // Calculate happiness for rows
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (cake[i][j] == 'C') {
                    chocCount++;
                }
            }
            if (chocCount > 1) {
                for (int k = chocCount; k > chocCount - 2; k--) {
                    nfat *= k;
                }
                happiness += nfat / 2;
            }
            nfat = 1;
            chocCount = 0;
        }

        // Calculate happiness for columns
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < n; i++) {
                if (cake[i][j] == 'C') {
                    chocCount++;
                }
            }
            if (chocCount > 1) {
                for (int k = chocCount; k > chocCount - 2; k--) {
                    nfat *= k;
                }
                happiness += nfat / 2;
            }
            nfat = 1;
            chocCount = 0;
        }

        System.out.println(happiness);
    }
}

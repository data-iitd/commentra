import java.util.Scanner;

public class CakeHappiness {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = Integer.parseInt(scanner.nextLine());
        String[] cake = new String[n];
        double happiness = 0;
        int chocCount = 0;
        int nfat;

        for (int i = 0; i < n; i++) {
            cake[i] = scanner.nextLine();
            chocCount = 0;
            for (char j : cake[i].toCharArray()) {
                if (j == 'C') {
                    chocCount++;
                }
            }
            if (chocCount > 1) {
                nfat = 1;
                for (int k = chocCount; k > chocCount - 2; k--) {
                    nfat *= k;
                }
                happiness += nfat / 2.0;
            }
        }

        for (int j = 0; j < n; j++) {
            chocCount = 0;
            for (int i = 0; i < n; i++) {
                if (cake[i].charAt(j) == 'C') {
                    chocCount++;
                }
            }
            if (chocCount > 1) {
                nfat = 1;
                for (int k = chocCount; k > chocCount - 2; k--) {
                    nfat *= k;
                }
                happiness += nfat / 2.0;
            }
        }

        System.out.println((int) happiness);
        scanner.close();
    }
}
// <END-OF-CODE>

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        
        int[] roundComplexity = new int[n];
        for (int i = 0; i < n; i++) {
            roundComplexity[i] = scanner.nextInt();
        }
        
        int[] georgeComplexity = new int[m];
        for (int j = 0; j < m; j++) {
            georgeComplexity[j] = scanner.nextInt();
        }
        
        int i = 0, j = 0;
        while (i < n && j < m) {
            if (roundComplexity[i] <= georgeComplexity[j]) {
                i++;
            }
            j++;
        }
        
        System.out.println(n - i);
        scanner.close();
    }
}

// <END-OF-CODE>

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();
        int[] x = new int[10000];
        
        for (int i = 0; i < n; i++) {
            x[i] = scanner.nextInt();
        }
        
        int q = scanner.nextInt();
        int[] y = new int[500];
        
        for (int i = 0; i < q; i++) {
            y[i] = scanner.nextInt();
        }
        
        int sum = 0;
        
        for (int i = 0; i < q; i++) {
            for (int j = 0; j < n; j++) {
                if (y[i] == x[j]) {
                    sum++;
                    break;
                }
            }
        }
        
        System.out.println(sum);
        
        scanner.close();
    }
}

// <END-OF-CODE>

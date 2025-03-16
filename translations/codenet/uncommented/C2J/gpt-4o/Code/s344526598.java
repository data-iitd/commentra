import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int[] x = new int[10000];
        int i = 0;
        Scanner scanner = new Scanner(System.in);
        
        // Initialize the array
        for (i = 0; i < 10000; i++) {
            x[i] = 0;
        }
        
        i = 0;
        x[i] = scanner.nextInt();
        
        while (x[i] != 0) {
            i++;
            x[i] = scanner.nextInt();
        }
        
        for (int j = 0; j < i; j++) {
            System.out.printf("Case %d: %d\n", j + 1, x[j]);
        }
        
        scanner.close();
    }
}

// <END-OF-CODE>

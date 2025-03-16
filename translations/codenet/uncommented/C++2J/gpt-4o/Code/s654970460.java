import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] a = new int[101];
        
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        
        System.out.print(a[n - 1]);
        for (int i = 1; i < n; i++) {
            System.out.print(" " + a[n - i - 1]);
        }
        System.out.println();
        
        scanner.close();
    }
}

// <END-OF-CODE>

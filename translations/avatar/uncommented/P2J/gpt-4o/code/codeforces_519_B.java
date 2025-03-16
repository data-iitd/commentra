import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();
        int[] a = new int[n];
        int[] b = new int[n];
        int[] c = new int[n];
        
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        
        for (int i = 0; i < n; i++) {
            b[i] = scanner.nextInt();
        }
        
        for (int i = 0; i < n; i++) {
            c[i] = scanner.nextInt();
        }
        
        int x = 0, y = 0, z = 0;
        
        for (int i : a) {
            x += i;
        }
        
        for (int i : b) {
            y += i;
        }
        
        for (int i : c) {
            z += i;
        }
        
        System.out.println(Math.abs(x - y));
        System.out.println(Math.abs(y - z));
        
        scanner.close();
    }
}

// <END-OF-CODE>

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int[] a = new int[1000];
        int n = scanner.nextInt();
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        
        int d = 0;
        for (int i = 0; i < n; i++) {
            for (int j = n - 1; j >= i + 1; j--) {
                if (a[j] < a[j - 1]) {
                    int temp = a[j];
                    a[j] = a[j - 1];
                    a[j - 1] = temp;
                    d++;
                }
            }
        }
        
        System.out.print(a[0]);
        for (int i = 1; i < n; i++) {
            System.out.print(" " + a[i]);
        }
        System.out.println();
        System.out.println(d);
        
        scanner.close();
    }
}

// <END-OF-CODE>

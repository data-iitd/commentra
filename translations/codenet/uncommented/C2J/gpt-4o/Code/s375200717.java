import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        
        for (int i = 1; i <= n; i++) {
            int a = i;
            if (a % 3 == 0) {
                System.out.print(" " + i);
            } else {
                while (a > 0) {
                    if (a % 10 == 3) {
                        System.out.print(" " + i);
                        a = 0; // Break the loop
                    }
                    a = a / 10;
                }
            }
        }
        System.out.println();
        scanner.close();
    }
}

// <END-OF-CODE>

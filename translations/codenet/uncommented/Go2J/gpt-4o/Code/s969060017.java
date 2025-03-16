import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        int b = scanner.nextInt();

        if (b % a == 0) {
            System.out.println(a + b);
        } else {
            System.out.println(b - a);
        }
        
        scanner.close();
    }
}

// <END-OF-CODE>

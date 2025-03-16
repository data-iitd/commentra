import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int ar = a * b;
        int le = 2 * (a + b);
        System.out.println(ar + " " + le);
        scanner.close();
    }
}

// <END-OF-CODE>

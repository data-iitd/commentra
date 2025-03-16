import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        System.out.println(((b - 1) + (a - 2)) / (a - 1));
        scanner.close();
    }
}

// <END-OF-CODE>

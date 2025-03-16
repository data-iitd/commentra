import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long a = scanner.nextLong();
        long b = scanner.nextLong();
        long c = scanner.nextLong();
        long d = scanner.nextLong();
        System.out.println(Math.max(Math.max(a * c, b * d), Math.max(a * d, b * c)));
        scanner.close();
    }
}

// <END-OF-CODE>

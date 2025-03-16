import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();
        long b = (n * (n - 1)) / 2;
        System.out.println(b);
        scanner.close();
    }
}

// <END-OF-CODE>

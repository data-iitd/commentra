import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int x = scanner.nextInt();
        int a = scanner.nextInt();
        System.out.println((x >= a) ? 10 : 0);
        scanner.close();
    }
}

// <END-OF-CODE>

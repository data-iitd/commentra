import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int h = scanner.nextInt();
        int w = scanner.nextInt();
        int hh = scanner.nextInt();
        int ww = scanner.nextInt();
        System.out.println((h - hh) * (w - ww));
        scanner.close();
    }
}

// <END-OF-CODE>

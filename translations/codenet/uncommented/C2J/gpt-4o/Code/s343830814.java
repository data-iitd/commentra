import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String buf = scanner.nextLine();
        int len = buf.length();
        System.out.printf("%c%d%c%n", buf.charAt(0), len - 3, buf.charAt(len - 2));
        scanner.close();
    }
}

// <END-OF-CODE>

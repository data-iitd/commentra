import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int x = scanner.nextInt();
        if (x >= 1200) {
            System.out.println("ARC");
        } else {
            System.out.println("ABC");
        }
        scanner.close();
    }
}

// <END-OF-CODE>

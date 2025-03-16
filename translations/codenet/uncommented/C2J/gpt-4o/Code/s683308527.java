import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character after the integer input

        while (n-- > 0) {
            String s = scanner.nextLine();
            int index;
            while ((index = s.indexOf("Hoshino")) != -1) {
                s = s.substring(0, index + 6) + 'a' + s.substring(index + 7);
            }
            System.out.println(s);
        }
        scanner.close();
    }
}

// <END-OF-CODE>

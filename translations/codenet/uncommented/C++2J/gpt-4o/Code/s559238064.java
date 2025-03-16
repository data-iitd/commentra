import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String z = scanner.nextLine();
        int a = z.length();
        
        for (int i = 0; i < a - 1; i++) {
            if (z.charAt(i) == z.charAt(i + 1)) {
                System.out.println("Bad");
                return;
            }
        }
        System.out.println("Good");
    }
}

// <END-OF-CODE>

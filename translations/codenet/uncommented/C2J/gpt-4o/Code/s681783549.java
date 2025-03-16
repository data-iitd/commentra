import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String S = scanner.nextLine();
        boolean found = false;

        for (int i = 0; i < S.length() - 1; i++) {
            if (S.charAt(i) == 'A' && S.charAt(i + 1) == 'C') {
                System.out.println("Yes");
                found = true;
                break;
            }
        }

        if (!found) {
            System.out.println("No");
        }

        scanner.close();
    }
}

// <END-OF-CODE>

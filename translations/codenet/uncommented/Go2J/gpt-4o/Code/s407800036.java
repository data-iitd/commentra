import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Code for A - Between Two Integers
        Scanner scanner = new Scanner(System.in);
        int A = scanner.nextInt();
        int B = scanner.nextInt();
        int C = scanner.nextInt();

        if (C >= A && C <= B) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
        
        scanner.close();
    }
}

// <END-OF-CODE>

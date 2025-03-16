import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int product = a * b;
        
        if (product % 2 == 0) {
            System.out.println("Even");
        } else {
            System.out.println("Odd");
        }
        
        scanner.close();
    }
}

// <END-OF-CODE>

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int x = scanner.nextInt();
        
        if (x == 0) {
            System.out.println("1");
        }
        if (x == 1) {
            System.out.println("0");
        }
        
        scanner.close();
    }
}

// <END-OF-CODE>

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        
        int x = a * b;
        int y = (a + b) * 2;
        
        System.out.println(x + " " + y);
        
        scanner.close();
    }
}

// <END-OF-CODE>

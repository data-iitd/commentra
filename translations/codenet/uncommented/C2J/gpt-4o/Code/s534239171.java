import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int n = (a + b) / 2;
        
        System.out.println(n);
        scanner.close();
    }
}

// <END-OF-CODE>

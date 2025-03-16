import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        
        int s = (a * b) - (a + b) + 1;
        
        System.out.println(s);
        
        scanner.close();
    }
}

// <END-OF-CODE>

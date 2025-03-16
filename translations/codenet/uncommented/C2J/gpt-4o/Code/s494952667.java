import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String str = scanner.next();
        
        int len = str.length();
        
        for (int i = len - 1; i >= 0; i--) {
            System.out.print(str.charAt(i));
        }
        System.out.println();
        
        scanner.close();
    }
}

// <END-OF-CODE>

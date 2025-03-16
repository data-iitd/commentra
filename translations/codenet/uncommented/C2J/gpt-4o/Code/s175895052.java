import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String n = scanner.nextLine();
        
        if (((n.charAt(0) == n.charAt(1)) && (n.charAt(1) == n.charAt(2))) || 
            ((n.charAt(1) == n.charAt(2)) && (n.charAt(2) == n.charAt(3)))) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
        
        scanner.close();
    }
}

// <END-OF-CODE>

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String str = scanner.nextLine();
        
        if (str.charAt(2) == str.charAt(3) && str.charAt(4) == str.charAt(5)) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
        
        scanner.close();
    }
}

// <END-OF-CODE>

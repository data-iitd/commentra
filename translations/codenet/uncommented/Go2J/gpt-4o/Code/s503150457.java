import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        String s1 = scanner.next();
        String s2 = scanner.next();
        String s3 = scanner.next();
        
        String result = Character.toUpperCase(s1.charAt(0)) +
                        Character.toUpperCase(s2.charAt(0)) +
                        Character.toUpperCase(s3.charAt(0));
        
        System.out.println(result);
        
        scanner.close();
    }
}

// <END-OF-CODE>

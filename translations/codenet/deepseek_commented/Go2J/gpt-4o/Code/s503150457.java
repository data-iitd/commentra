import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare three string variables to hold the input values
        Scanner scanner = new Scanner(System.in);
        String s1 = scanner.next();
        String s2 = scanner.next();
        String s3 = scanner.next();

        // Print the uppercase version of the first character of each input string
        System.out.println(Character.toUpperCase(s1.charAt(0)) 
                         + Character.toUpperCase(s2.charAt(0)) 
                         + Character.toUpperCase(s3.charAt(0)));
        
        scanner.close();
    }
}

// <END-OF-CODE>

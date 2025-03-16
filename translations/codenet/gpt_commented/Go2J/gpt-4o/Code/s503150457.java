import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare three string variables to hold user input
        Scanner scanner = new Scanner(System.in);
        String s1 = scanner.next();
        String s2 = scanner.next();
        String s3 = scanner.next();
        
        // Convert the first character of each string to uppercase and concatenate them
        String result = Character.toUpperCase(s1.charAt(0)) + 
                        Character.toUpperCase(s2.charAt(0)) + 
                        Character.toUpperCase(s3.charAt(0));
        
        // Print the concatenated result
        System.out.println(result);
        
        scanner.close();
    }
}

// <END-OF-CODE>

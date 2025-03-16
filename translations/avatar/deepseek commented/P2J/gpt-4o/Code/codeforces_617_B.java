import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Take an input from the user and store it in variable 'a'
        String a = scanner.nextLine();
        
        // Print the result based on the input
        if (a.chars().filter(ch -> ch == '1').count() == 0) {
            System.out.println(0);
        } else {
            String[] parts = a.trim().split("1");
            int result = 1;
            for (String part : parts) {
                result *= (part.length() + 1);
            }
            System.out.println(result);
        }
        
        scanner.close();
    }
}
// <END-OF-CODE>

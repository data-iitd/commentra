import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        scanner.nextLine(); // Read the first input line
        String a = scanner.nextLine(); // Read the second input line

        if (a.chars().filter(ch -> ch == '1').count() == 0) {
            System.out.println(0);
        } else {
            String[] segments = a.trim().split("1");
            int product = 1;
            for (String segment : segments) {
                product *= (segment.length() + 1);
            }
            System.out.println(product);
        }
        
        scanner.close();
    }
}
// <END-OF-CODE>

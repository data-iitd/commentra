
import java.util.Scanner;

public class s683308527{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Read the number of lines to process
        scanner.nextLine(); // Ignore the newline character

        for(int i = 0; i < n; i++) {
            String s = scanner.nextLine(); // Read a line of input from stdin
            int index = s.indexOf("Hoshino"); // Search for the substring "Hoshino" in the input line

            while(index!= -1) {
                s = s.substring(0, index + 6) + "a" + s.substring(index + 7); // Replace the character after "Hoshino" with 'a'
                index = s.indexOf("Hoshino", index + 1); // Search for the substring "Hoshino" again
            }

            System.out.println(s); // Print the modified line
        }
    }
}

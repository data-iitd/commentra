
import java.util.Scanner;

public class s079891640{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine(); // Read the input string from standard input

        for (int i = 0; i < s.length(); i++) { // Iterate over each character in the string
            if (s.substring(i + 1).contains(String.valueOf(s.charAt(i)))) { // Check if the character appears again in the substring
                System.out.println("no"); // If it does, print "no" and exit
                return;
            }
        }

        System.out.println("yes"); // If no character appears again, print "yes"
    }
}


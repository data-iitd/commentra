import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Declare three String variables to store strings A, B, and C
        String A = "", B = "", C = "";

        // Initialize the String variables A, B, and C using scanner.next() function
        A = scanner.next();
        B = scanner.next();
        C = scanner.next();

        // Calculate the length of strings A and B using length() method and store the lengths in la and lb respectively
        int la = A.length(), lb = B.length();

        // Logical block to check if the last character of string A is same as the first character of string B
        // and the last character of string B is same as the first character of string C
        if (A.charAt(la - 1) == B.charAt(0) && B.charAt(lb - 1) == C.charAt(0)) {
            // If the condition is true, print YES on the console
            System.out.println("YES");
        }
        // Logical block to check if the condition in if block is false
        else {
            // If the condition is false, print NO on the console
            System.out.println("NO");
        }

        // Return 0 to indicate successful execution of the program
    }
}

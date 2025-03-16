import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner sc = new Scanner(System.in);
        
        // Read two integers from user input
        int a = sc.nextInt();
        int b = sc.nextInt();
        
        // Calculate half of the second integer
        int hb = b / 2;
        
        // Output the sum of the first integer and half of the second integer
        System.out.println(a + hb);
    }
}

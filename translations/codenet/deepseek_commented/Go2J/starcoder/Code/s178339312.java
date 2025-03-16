import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare a variable to store the input integer
        int x;
        
        // Read an integer from the standard input and store it in x
        Scanner sc = new Scanner(System.in);
        x = sc.nextInt();
        
        // Calculate the cube of x (x*x*x)
        int result = x * x * x;
        
        // Print the result
        System.out.println(result);
    }
}

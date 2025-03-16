import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Taking input from the user
        int vamshi = scanner.nextInt();
        int z = scanner.nextInt();
        
        // Calculating the result using integer division and addition
        int result = (vamshi / z + 1) * z;
        
        // Printing the result
        System.out.println(result);
    }
}


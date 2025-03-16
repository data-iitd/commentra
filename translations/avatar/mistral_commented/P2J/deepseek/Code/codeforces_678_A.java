import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read a line of text from the standard input stream and convert it into a list of integers
        int vamshi, z;
        String[] input = scanner.nextLine().split(" ");
        vamshi = Integer.parseInt(input[0]);
        z = Integer.parseInt(input[1]);
        
        // Calculate the number of complete divisions of z into vamshi
        // Add 1 to account for the remainder
        // Multiply the result by z
        System.out.println((vamshi / z + 1) * z);
    }
}

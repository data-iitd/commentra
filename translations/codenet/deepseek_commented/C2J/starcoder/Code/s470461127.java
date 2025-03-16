import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int x, y;
        x = 0; y = 0;   

        // Read two integers from the standard input and store them in x and y
        x = sc.nextInt();
        y = sc.nextInt();
        
        // Calculate the product of x and y
        // Also, calculate the perimeter of a rectangle with sides x and y
        System.out.println(x * y);
        System.out.println((2*x) + (2*y));
    }
}

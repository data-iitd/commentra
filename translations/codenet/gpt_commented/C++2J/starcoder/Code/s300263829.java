import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int a, b;
        System.out.print("Enter two integers: ");
        a = input.nextInt();
        b = input.nextInt();
        System.out.println("The product is: " + a * b);
    }
}

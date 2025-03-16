import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // Declare variables to hold the lengths of the two bases (a and b) and the height (h)
        int a, b, h;

        // Read the values of the two bases and the height from user input
        Scanner sc = new Scanner(System.in);
        a = sc.nextInt();
        b = sc.nextInt();
        h = sc.nextInt();

        // Calculate the area of the trapezoid using the formula: Area = ((base1 + base2) * height) / 2
        // and print the result
        System.out.println((a + b) * h / 2);
    }
}

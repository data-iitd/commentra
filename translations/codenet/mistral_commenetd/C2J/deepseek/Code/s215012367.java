public class Main {
    public static void main(String[] args) {
        int a, b, s; // Declaring three integer variables a, b, and s

        java.util.Scanner scanner = new java.util.Scanner(System.in); // Creating a Scanner object to read input
        a = scanner.nextInt(); // Reading the first integer from the user and storing it in variable a
        b = scanner.nextInt(); // Reading the second integer from the user and storing it in variable b

        s = (a * b) - (a + b) + 1; // Calculating the value of s by multiplying a and b, subtracting the sum of a and b, and adding 1

        // The following line prints the value of s to the console
        System.out.println(s);
    }
}

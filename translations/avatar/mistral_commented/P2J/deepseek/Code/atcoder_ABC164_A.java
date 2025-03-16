public class Main {
    public static void main(String[] args) {
        // Get the input as a list of two integers, S and W, using the Scanner class
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int S = scanner.nextInt();
        int W = scanner.nextInt();

        // Check if the condition S <= W is true or false and print the corresponding message
        if (S <= W) {
            System.out.println("unsafe");
        } else {
            System.out.println("safe");
        }
    }
}

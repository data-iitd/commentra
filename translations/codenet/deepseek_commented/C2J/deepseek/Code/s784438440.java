public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        
        // Read two integers a and b from the user
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        
        // Compute a value based on these inputs
        int result = ((b - 1) + (a - 2)) / (a - 1);
        
        // Print the computed value
        System.out.println(result);
    }
}

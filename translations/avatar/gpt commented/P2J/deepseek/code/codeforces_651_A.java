import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read two integers from input and assign them to x and y
        int x = scanner.nextInt();
        int y = scanner.nextInt();
        
        // Calculate the maximum value based on the formula and print it
        // The formula computes x + y - 3 and adjusts based on the difference between y and x
        // It ensures the result is not negative by taking the maximum with 0
        int result = Math.max(x + y - 3 + ((y - x) % 3 > 0) ? 1 : 0, 0);
        System.out.println(result);
        
        // Define a lambda function to read a single integer from input
        java.util.function.IntSupplier num_inp = () -> scanner.nextInt();
        
        // Define a lambda function to read a list of integers from input
        java.util.function.IntSupplier arr_inp = () -> {
            Scanner scanner1 = new Scanner(System.in);
            String[] parts = scanner1.nextLine().split(" ");
            int[] arr = new int[parts.length];
            for (int i = 0; i < parts.length; i++) {
                arr[i] = Integer.parseInt(parts[i]);
            }
            return arr;
        };
        
        // Define a lambda function to read a space-separated list of integers from input
        java.util.function.IntSupplier sp_inp = () -> {
            Scanner scanner1 = new Scanner(System.in);
            String[] parts = scanner1.nextLine().split(" ");
            int[] arr = new int[parts.length];
            for (int i = 0; i < parts.length; i++) {
                arr[i] = Integer.parseInt(parts[i]);
            }
            return arr;
        };
        
        // Define a lambda function to read a string from input
        java.util.function.Supplier<String> str_inp = () -> {
            Scanner scanner1 = new Scanner(System.in);
            return scanner1.nextLine();
        };
    }
}

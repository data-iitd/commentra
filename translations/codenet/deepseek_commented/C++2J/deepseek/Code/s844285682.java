public class Main {
    public static void main(String[] args) {
        int a; // Declare an integer variable a
        
        java.util.Scanner scanner = new java.util.Scanner(System.in); // Create a Scanner object to read input
        
        a = scanner.nextInt(); // Read an integer input from the user and store it in variable a
        
        System.out.println(a / (60 * 60) + ":" + a % (60 * 60) / 60 + ":" + a % (60 * 60) % 60); // Calculate and output the hours, minutes, and seconds
        
        scanner.close(); // Close the Scanner object
    }
}

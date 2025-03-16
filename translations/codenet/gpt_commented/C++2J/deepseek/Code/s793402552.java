public class Main {
    public static void main(String[] args) {
        // Read two integers a and b from input
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int a = scanner.nextInt();
        int b = scanner.nextInt();

        // Convert b to string to determine its length
        String bstr = String.valueOf(b);
        
        // Calculate the number formed by concatenating a and b
        int num = a * (int)Math.pow(10, bstr.length()) + b;

        // Initialize a variable to find the square root of num
        int i;
        // Loop to check if there exists an integer i such that i*i equals num
        for (i = 1; i <= 100100; i++) {
            if (i * i == num) break; // If found, exit the loop
        }

        // Check if a valid integer i was found within the range
        if (i > 100100) 
            System.out.println("No"); // If no such i exists, print "No"
        else 
            System.out.println("Yes"); // If such i exists, print "Yes"
    }
}

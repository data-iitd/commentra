import java.util.*; // We import the Java Util library to use the Scanner class

public class Main { // This is the main class of the program
    public static void main(String[] args) throws Exception { // This is the main method, it is the entry point of the program
        Scanner sc = new Scanner(System.in); // We create a new Scanner object to read input from the console

        // Read the first time in hours and minutes
        int h1 = sc.nextInt();
        int m1 = sc.nextInt();

        // Read the second time in hours and minutes
        int h2 = sc.nextInt();
        int m2 = sc.nextInt();

        // Read the number of minutes to add
        int k = sc.nextInt();

        // Calculate the total minutes of the first time
        int t1 = h1 * 60 + m1;

        // Calculate the total minutes of the second time
        int t2 = h2 * 60 + m2;

        // Calculate the difference between the total minutes of the second time and the first time, and subtract the number of minutes to add
        int result = t2 - t1 - k;

        // Print the result to the console
        System.out.println(result);

        // Close the Scanner to free system resources
        sc.close();
    }
}

import java.util.Scanner; // Importing Scanner class for input

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Creating a Scanner object
        int n = sc.nextInt(); // Reading an integer input
        long[] ryuka = new long[n + 1]; // Initializing the array
        ryuka[0] = 2; // Setting the first element
        ryuka[1] = 1; // Setting the second element
        for (int i = 2; i < n + 1; i++) { // Filling the array
            ryuka[i] = ryuka[i - 1] + ryuka[i - 2]; // Calculating each element
        }
        System.out.println(ryuka[n]); // Outputting the result
    }
}

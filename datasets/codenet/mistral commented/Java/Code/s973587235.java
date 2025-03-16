import java.util.*; // Importing the utility class Scanner from the java.util package

public class Main { // Defining the main class named Main
    public static void main(String[] args) { // Defining the main method that is the entry point of the program
        Scanner sc = new Scanner(System.in); // Creating a new Scanner object to read input from the standard input stream

        // Reading the first integer input
        int n = sc.nextInt();
        // Reading the second integer input and storing the index of the minimum height in it
        int minN = sc.nextInt()-1;

        for(int i=0;i<n-1;i++){ // Iterating through the n-1 height inputs
            int h = sc.nextInt(); // Reading the height input for the current iteration

            // Checking if the current height is equal to the index of the minimum height
            if( minN == h){
                minN = h; // If yes, updating the index of the minimum height
            }
            // Checking if the current height is one less than the index of the minimum height
            else if(minN == h-1){
                minN = h-1; // If yes, updating the index of the minimum height
            }
            // Checking if the current height is less than the index of the minimum height
            else if(minN < h){
                minN = h-1; // If yes, updating the index of the minimum height
            }
            // Checking if the current height is greater than the index of the minimum height
            else if(minN > h){
                System.out.println("No"); // If yes, printing "No" and returning from the method
            }
        }
        System.out.println("Yes"); // If the loop completes without printing "No", then printing "Yes"
    }
}

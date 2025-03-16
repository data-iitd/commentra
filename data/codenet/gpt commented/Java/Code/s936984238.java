import java.util.*;

public class Main {
    static Scanner sc = new Scanner(System.in); // Scanner to read input from the console
    static int[] score; // Array to hold the scores
    static int number; // Variable to hold the number of scores

    public static void main(String[] args) {
        // Continuously read input and process scores until a termination condition is met
        while(read()){
            slove(); // Solve the problem for the current set of scores
        }
    }

    static boolean read(){
        // Read the number of scores from input
        number = sc.nextInt();
        
        // Check for termination condition (0 indicates no more scores)
        if(number == 0)
            return false; // Exit the loop if the input is 0
        
        // Initialize the scores array with the number of scores
        score = new int[number];
        
        // Read each score into the scores array
        for(int i = 0; i < number; i++){
            score[i] = sc.nextInt();
        }
        return true; // Return true to indicate successful reading of scores
    }

    static void slove(){
        // Sort the scores array to facilitate calculation of the average
        java.util.Arrays.sort(score);
        
        int sum = 0; // Variable to hold the sum of the middle scores
        
        // Calculate the sum of the scores excluding the highest and lowest
        for(int i = 1; i < number-1; i++){
            sum = sum + score[i]; // Add the current score to the sum
        }
        
        // Calculate and print the average of the middle scores
        System.out.println(sum/(number-2));
    }
}

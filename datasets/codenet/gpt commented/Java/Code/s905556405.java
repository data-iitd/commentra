import java.util.*;

public class Main { 
    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner sc = new Scanner(System.in);
		
        // Initialize an array to hold 5 integers
        int[] numlist  = new int[5];
        int k;
      
        // Loop to read 5 integers from the user and store them in numlist
        for(int i = 0; i < 5; i++){
            numlist[i] = sc.nextInt(); // Read an integer and store it in the array
        }
        
        // Read the integer k from the user
        k = sc.nextInt();
        
        // Check if the difference between the largest and smallest number in numlist is greater than k
        if((numlist[4] - numlist[0]) > k){
            System.out.println(":("); // Output sad face if the condition is true
        } else {
            System.out.println("Yay!"); // Output happy message if the condition is false
        }
    }
}


import java.util.*;

public class Main { 
    public static void main(String[] args) {
        // Initialize Scanner to read input from the user
        Scanner sc = new Scanner(System.in);
		
        // Declare and initialize an array to store 5 integers
        int[] numlist  = new int[5];
        int k;
      
        // Read 5 integers from the user and store them in the array
        for(int i=0;i<5;i++){
            numlist[i] = sc.nextInt(); 
        }
      
        // Read the value of k from the user
        k = sc.nextInt();
      
        // Check if the difference between the last and first elements of the array is greater than k
        if((numlist[4] - numlist[0])>k){
            // Print :( if the condition is true
            System.out.println(":("); 
        }else{
            // Print Yay! if the condition is false
            System.out.println("Yay!");
        }
    }
}


import java.util.PriorityQueue; 
import java.util.Queue; 
import java.util.Scanner; 

public class Main { 
    public static void main(String[] args) { 
        // Call the solve method and print the result
        System.out.println(solve()); 
    } 

    public static int solve() { 
        // Create a Scanner object to read input from the user
        Scanner sc = new Scanner(System.in); 
        
        // Read the number of elements in the array
        int N = sc.nextInt(); 
        
        // Initialize an array to hold the input values
        int[] arr = new int[N]; 
        
        // Populate the array with user input
        for (int i = 0; i < N; i++) { 
            arr[i] = sc.nextInt(); 
        } 
        
        // Initialize a variable to keep track of the count of elements
        int sum = 0; 
        
        // Create a priority queue to manage the elements
        Queue<Integer> q = new PriorityQueue<>(); 
        
        // Iterate through the array to process each element
        for (int i = 0; i < arr.length; i++) { 
            // Add the current element to the priority queue
            q.add(arr[i]); 
            
            // Check if the current element is less than or equal to the smallest element in the queue
            if (arr[i] <= q.peek()) { 
                // Increment the count if the condition is met
                sum++; 
            } 
        } 
        
        // Return the final count of elements that met the condition
        return sum; 
    } 
}

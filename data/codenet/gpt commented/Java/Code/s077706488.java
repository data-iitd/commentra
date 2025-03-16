import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner stdIn = new Scanner(System.in);
        
        // Read the number of elements (N) and the initial value (X) from the input
        int N = stdIn.nextInt();
        int X = stdIn.nextInt();
        
        // Initialize an array to hold the elements
        int[] m = new int[N];
        
        // Read the first element into the array and adjust X
        m[0] = stdIn.nextInt();
        X -= m[0];
        
        // Initialize min with the first element
        int min = m[0];
        
        // Loop through the remaining elements to read them and update X and min
        for(int i = 1; i < N; i++) {
            // Read the next element into the array
            m[i] = stdIn.nextInt();
            // Subtract the current element from X
            X -= m[i];
            // Update min if the current element is smaller
            if(m[i] < min) {
                min = m[i];
            }
        }
        
        // Calculate and print the result based on the number of elements, remaining X, and minimum value
        System.out.println(N + X / min);
    }
}

public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt(); // Read the number of integers to be input
        int min = Integer.MAX_VALUE; // Initialize min to the maximum possible integer value
        int max = Integer.MIN_VALUE; // Initialize max to the minimum possible integer value
        long sum = 0; // Initialize sum to 0
        
        // Iterate through each integer input
        for(int i = 0; i < n; i++){
            int m = scanner.nextInt(); // Read an integer input and assign it to m
            sum += m; // Add the current integer input to the sum
            
            // Update min and max values if the current input is smaller or larger
            if(min > m){
                min = m; // Set min to the current input if it's smaller
            }
            if(max < m){
                max = m; // Set max to the current input if it's larger
            }
        }
        
        // Print the minimum value, maximum value, and sum of the input integers
        System.out.println(min + " " + max + " " + sum);
    }
}

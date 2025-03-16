public class SumArray {
    public static void main(String[] args) {
        int[] v = new int[10]; // Step 2: Declare an array of 10 integers
        int sum = 0; // Step 2: Declare and initialize a variable to store the sum
        
        // Step 3: Initialize a loop to read 10 integers from the user
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        for(int i = 0; i < 10; i++) {
            v[i] = scanner.nextInt(); // Step 3: Read an integer and store it in the array
        }
        
        // Step 4: Initialize a loop to calculate the sum of the integers
        for(int i = 0; i < 10; i++) {
            sum += v[i]; // Step 4: Add the current element to the sum
        }
        
        // Step 5: Print the sum of the integers
        System.out.println(sum); // Step 5: Print the sum of the integers
    }
}


public class Main {
    public static void main(String[] args) {
        int[] v = new int[10]; // Step 2: Declare an array of 10 integers
        int sum = 0; // Step 2: Declare and initialize a variable to store the sum
        int i; // Step 2: Declare a loop variable
        
        for(i = 0; i < 10; i++) { // Step 3: Initialize a loop to read 10 integers from the user
            v[i] = scanner.nextInt(); // Step 3: Read an integer and store it in the array
        }
        
        for(i = 0; i < 10; i++) { // Step 4: Initialize a loop to calculate the sum of the integers
            sum += v[i]; // Step 4: Add the current element to the sum
        }
        
        System.out.println(sum); // Step 5: Print the sum of the integers
    }
}


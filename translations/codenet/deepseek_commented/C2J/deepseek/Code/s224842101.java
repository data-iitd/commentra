public class Main {
    public static void main(String[] args) {
        int i, a, b, s; // Step 3: Declare necessary variables
        int[] count = new int[4]; // Declare an array to store the count of connections for each node

        for(i = 0; i < 4; i++) count[i] = 0; // Step 4: Initialize the count array

        for(i = 0; i < 3; i++){ // Step 5: Read input values and update the count array
            java.util.Scanner scanner = new java.util.Scanner(System.in);
            a = scanner.nextInt();
            b = scanner.nextInt();
            count[a-1]++; // Increment the count for node a
            count[b-1]++; // Increment the count for node b
        }

        s = 1; // Initialize s to 1
        for(i = 0; i < 4; i++) s *= count[i]; // Step 6: Calculate the product of the counts

        if(s == 4) System.out.println("YES"); // Step 7: Check if the product is 4 and print the result
        else System.out.println("NO");
    }
}

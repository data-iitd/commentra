public class Main {
    public static void main(String[] args) {
        // Step 3: Create a array of integers with a length of 3
        int[] in = new int[3];
        
        // Step 4: Prompt the user to input three integers
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        in[0] = scanner.nextInt();
        in[1] = scanner.nextInt();
        in[2] = scanner.nextInt();
        
        // Step 5: Sort the array of integers in ascending order
        java.util.Arrays.sort(in);
        
        // Step 6: Perform a calculation using the sorted integers and print the result
        System.out.println(in[2] * 10 + in[1] + in[0]);
    }
}

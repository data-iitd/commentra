public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);  // Step 1: Create a Scanner object to read input from the user.

        int sheep = scanner.nextInt();  // Step 2: Read the number of sheep from the user.
        int wolf = scanner.nextInt();  // Step 3: Read the number of wolves from the user.

        if(wolf >= sheep){  // Step 4: Check if the number of wolves is greater than or equal to the number of sheep.
            System.out.println("unsafe");  // Step 5: If the condition is true, print "unsafe".
        } else {
            System.out.println("safe");  // Step 6: Otherwise, print "safe".
        }

        scanner.close();  // Step 7: Close the Scanner object to free up resources.
    }
}

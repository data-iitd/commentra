public class Main {
    public static void main(String[] args) {
        // Get two integers from user input, separated by a space
        String[] input = System.console().readLine().split(" ");
        int a = Integer.parseInt(input[0]);
        int b = Integer.parseInt(input[1]);

        // Initialize the variable 'hole' to 1
        int hole = 1;

        // Initialize the variable 'i' to 0
        int i = 0;

        // Initialize the variable 'check' to True
        boolean check = true;

        // Loop until the condition is not met
        while (check) {
            // Check if the value of 'hole' is greater than or equal to 'b'
            if (hole >= b) {
                // If the condition is met, set 'check' to False to terminate the loop
                check = false;
            } else {
                // If the condition is not met, update the value of 'hole'
                hole = a * (i + 1) - i;
                // Increment the value of 'i' by 1
                i += 1;
            }
        }

        // Once the loop terminates, print out the value of 'i' as the result
        System.out.println(i);
    }
}

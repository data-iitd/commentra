public class Main {
    public static void main(String[] args) {
        // Variable declaration and initialization
        int n = 0;
        String s = "";

        // Reading input from the user (assuming input is provided through command line arguments or other means)
        // For simplicity, we will use hardcoded values in this example
        n = 5;
        s = "IIDII";

        // Variable declaration and initialization for maximum count and current count
        int max = 0;
        int cnt = 0;

        // Iterating through each character in the string 's'
        for (char r : s.toCharArray()) {
            // Checking if the character is 'I'
            if (r == 'I') {
                // Incrementing the current count
                cnt++;
            } else {
                // Decrementing the current count
                cnt--;
            }

            // Updating the maximum count if the current count is greater
            if (cnt > max) {
                max = cnt;
            }
        }

        // Printing the maximum count
        System.out.println(max);
    }
}

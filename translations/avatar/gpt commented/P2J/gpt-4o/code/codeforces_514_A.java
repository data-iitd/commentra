import java.util.Scanner;

public class TransformNumber {
    public static void main(String[] args) {
        // Get user input
        Scanner scanner = new Scanner(System.in);
        String ip = scanner.nextLine();

        // Initialize an empty string to store the transformed number
        StringBuilder st = new StringBuilder();

        // Check if the input length is not equal to 1
        if (ip.length() != 1) {
            // If the first character is '9', keep it and remove it from the input
            if (ip.charAt(0) == '9') {
                st.append('9');  // Start the output string with '9'
                ip = ip.substring(1);  // Remove the first character from the input
            }

            // Iterate through each character in the remaining input
            for (char i : ip.toCharArray()) {
                // If the digit is greater than 4, calculate its complement to 9
                if (Character.getNumericValue(i) > 4) {
                    int n = 9 - Character.getNumericValue(i);  // Calculate the complement
                    st.append(n);  // Append the complement to the output string
                } else {
                    // If the digit is 4 or less, keep it unchanged
                    st.append(i);  // Append the original digit to the output string
                }
            }
        } else {
            // If the input length is 1, simply assign it to the output
            st.append(ip);
        }

        // Print the final transformed number as an integer
        System.out.println(Integer.parseInt(st.toString()));
    }
}
// <END-OF-CODE>

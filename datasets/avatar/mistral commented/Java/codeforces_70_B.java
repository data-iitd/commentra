
import java.io.BufferedReader; // BufferedReader to read input from System.in
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); // Initialize BufferedReader to read input

        int n = Integer.parseInt(br.readLine()); // Read the number of messages
        String input = br.readLine(); // Read the string of messages

        int max = -1; // Initialize max to -1
        int msgLength[] = new int[input.length() / 2]; // Initialize msgLength array with size n/2
        int count = 0; // Initialize count to 0
        int idx = 0; // Initialize index to 0

        // Loop through each character in the input string
        for (int i = 0; i < input.length(); i++) {
            char c = input.charAt(i); // Read the character at index i

            if (c == '.' || c == '?' || c == '!') { // If character is a question mark, exclamation mark or period
                msgLength[idx++] = ++count; // Increment count and store it in msgLength array
                if (count > max) max = count; // Update max if count is greater than current max
                i++; // Increment i as we have read one more character
                count = 0; // Reset count as we have started a new message
            } else count++; // Increment count if character is not a question mark, exclamation mark or period
        }

        // Check if the total length of messages is greater than n
        if (max > n) {
            System.out.println("Impossible"); // Print "Impossible" if total length is greater than n
            return;
        }

        int ans = 0; // Initialize answer to 0

        // Loop through each message and find the maximum number of messages that can be sent
        for (int i = 0; i < idx; i++) {
            int l = msgLength[i]; // Initialize length of current message

            while (i < idx - 1 && l + msgLength[i + 1] + 1 <= n) { // While we can add next message to current message
                l += msgLength[i + 1] + 1; // Add length of next message and 1 for separator
                i++; // Increment i to move to next message
            }
            ans++; // Increment answer as we have added one more message
        }

        System.out.println(ans); // Print the answer
    }
}

These comments should provide a clear understanding of what each part of the code does. Let me know if you need any further assistance!
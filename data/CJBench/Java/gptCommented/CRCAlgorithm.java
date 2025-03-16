import java.util.ArrayList;
import java.util.Scanner;
import java.util.concurrent.ThreadLocalRandom;

public class Main {
    // Variables to track message statistics
    private int correctMess; // Count of correctly received messages
    private int wrongMess; // Count of total wrong messages
    private int wrongMessCaught; // Count of wrong messages that were detected
    private int wrongMessNotCaught; // Count of wrong messages that were not detected
    private int messSize; // Size of the message to be generated
    private double ber; // Bit Error Rate
    private boolean messageChanged; // Flag to indicate if the message has been altered
    private ArrayList<Integer> message; // List to hold the generated message
    private ArrayList<Integer> p; // List to hold the divisor polynomial coefficients

    // Constructor to initialize the Main class with a divisor string, message size, and bit error rate
    public Main(String str, int size, double ber) {
        messageChanged = false; // Initialize messageChanged to false
        message = new ArrayList<>(); // Initialize the message list
        messSize = size; // Set the size of the message
        p = new ArrayList<>(); // Initialize the divisor list

        // Convert the divisor string into a list of integers
        for (int i = 0; i < str.length(); i++) {
            p.add(Character.getNumericValue(str.charAt(i)));
        }

        // Initialize message statistics counters
        correctMess = 0;
        wrongMess = 0;
        wrongMessCaught = 0;
        wrongMessNotCaught = 0;
        this.ber = ber; // Set the bit error rate
    }

    // Getter methods to retrieve message statistics
    public int getWrongMess() {
        return wrongMess;
    }

    public int getWrongMessCaught() {
        return wrongMessCaught;
    }

    public int getWrongMessNotCaught() {
        return wrongMessNotCaught;
    }

    public int getCorrectMess() {
        return correctMess;
    }

    // Method to reset the message and the messageChanged flag
    public void refactor() {
        messageChanged = false; // Reset the messageChanged flag
        message = new ArrayList<>(); // Clear the message list
    }

    // Method to generate a random message of specified size
    public void generateRandomMess() {
        for (int i = 0; i < messSize; i++) {
            // Generate a random bit (0 or 1) and add it to the message list
            int x = ThreadLocalRandom.current().nextInt(0, 2);
            message.add(x);
        }
    }

    // Method to divide the message by the polynomial p and check for errors
    public void divideMessageWithP(boolean check) {
        ArrayList<Integer> x = new ArrayList<>(); // Temporary list to hold the current segment of the message
        ArrayList<Integer> k = new ArrayList<>(message); // Copy of the message for processing

        // If not checking for errors, append zeros to the message
        if (!check) {
            for (int i = 0; i < p.size() - 1; i++) {
                k.add(0);
            }
        }

        // Perform polynomial division
        while (!k.isEmpty()) {
            // Fill the temporary list x with bits from k
            while (x.size() < p.size() && !k.isEmpty()) {
                x.add(k.remove(0));
            }
            // If x is filled, perform XOR operation with the polynomial p
            if (x.size() == p.size()) {
                for (int i = 0; i < p.size(); i++) {
                    x.set(i, x.get(i) ^ p.get(i)); 
                }
                // Remove leading zeros from x
                while (!x.isEmpty() && x.get(0) == 0) {
                    x.remove(0);
                }
            }
        }

        // If not checking, append the result to the message
        if (!check) {
            message.addAll(x);
        } else {
            // Check for errors in the received message
            if (x.contains(1) && messageChanged) {
                wrongMessCaught++; // Increment caught wrong messages
            } else if (!x.contains(1) && messageChanged) {
                wrongMessNotCaught++; // Increment not caught wrong messages
            } else if (!messageChanged) {
                correctMess++; // Increment correct messages
            }
        }
    }

    // Method to change bits in the message based on the bit error rate
    public void changeMess() {
        for (int i = 0; i < message.size(); i++) {
            // Randomly change bits based on the bit error rate
            if (Math.random() < ber) {
                messageChanged = true; // Mark the message as changed
                message.set(i, message.get(i) ^ 1); // Flip the bit
            }
        }
        // If the message was changed, increment the wrong message count
        if (messageChanged) {
            wrongMess++;
        }
    }

    // Main method to execute the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a scanner for user input
        String divisor = scanner.next(); // Read the divisor polynomial as a string
        int messageSize = scanner.nextInt(); // Read the size of the message
        double ber = scanner.nextDouble(); // Read the bit error rate
        int numMessages = scanner.nextInt(); // Read the number of messages to process

        // Create an instance of the Main class with the provided parameters
        Main crc = new Main(divisor, messageSize, ber);

        // Process the specified number of messages
        for (int i = 0; i < numMessages; i++) {
            crc.refactor(); // Reset the message
            crc.generateRandomMess(); // Generate a new random message
            crc.divideMessageWithP(false); // Divide the message to append CRC
            crc.changeMess(); // Introduce errors in the message
            crc.divideMessageWithP(true); // Check for errors in the modified message
        }

        // Output the results of the message processing
        System.out.println("Correct Messages: " + crc.getCorrectMess());
        System.out.println("Wrong Messages: " + crc.getWrongMess());
        System.out.println("Wrong Messages Caught: " + crc.getWrongMessCaught());
        System.out.println("Wrong Messages Not Caught: " + crc.getWrongMessNotCaught());
        scanner.close(); // Close the scanner
    }
}

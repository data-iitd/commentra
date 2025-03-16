
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.concurrent.ThreadLocalRandom;

public class Main {
    // Declare instance variables
    private int correctMess;
    private int wrongMess;
    private int wrongMessCaught;
    private int wrongMessNotCaught;
    private int messSize;
    private double ber;
    private boolean messageChanged;
    private List<Integer> message;
    private List<Integer> p;

    public Main(String divisor, int messageSize, double ber) {
        // Initialize instance variables
        this.messageChanged = false;
        this.message = new ArrayList<>();
        this.messSize = messageSize;
        this.p = new ArrayList<>();

        // Initialize p list with the given divisor string
        for (int i = 0; i < divisor.length(); i++) {
            p.add(Character.getNumericValue(divisor.charAt(i)));
        }

        // Initialize counter variables
        this.correctMess = 0;
        this.wrongMess = 0;
        this.wrongMessCaught = 0;
        this.wrongMessNotCaught = 0;
        this.ber = ber;
    }

    // Getters for counter variables
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

    // Refactor method to reset instance variables
    public void refactor() {
        this.messageChanged = false;
        this.message = new ArrayList<>();
    }

    // Generate random message method
    public void generateRandomMess() {
        // Generate random message of given size
        for (int i = 0; i < messSize; i++) {
            int x = ThreadLocalRandom.current().nextInt(0, 2);
            message.add(x);
        }
    }

    // Divide message with p method without checking
    public void divideMessageWithP(boolean check) {
        List<Integer> x = new ArrayList<>(); // Initialize x list
        List<Integer> k = new ArrayList<>(message); // Initialize k list as a copy of message list

        // If not checking, fill k list with zeros
        if (!check) {
            for (int i = 0; i < p.size() - 1; i++) {
                k.add(0);
            }
        }

        // Divide message with p
        while (!k.isEmpty()) {
            while (x.size() < p.size() && !k.isEmpty()) {
                x.add(k.remove(0));
            }

            // If message size is equal to p size
            if (x.size() == p.size()) {
                // Xor each element in x list with corresponding element in p list
                for (int i = 0; i < p.size(); i++) {
                    x.set(i, x.get(i) ^ p.get(i));
                }

                // Remove leading zeros from x list
                while (!x.isEmpty() && x.get(0) == 0) {
                    x.remove(0);
                }
            }
        }

        // Update counter variables based on the result
        if (!check) {
            message.addAll(x);
        } else {
            // If message has been changed and 1 is present in x list
            if (messageChanged && x.contains(1)) {
                wrongMessCaught++;
            }
            // If message has been changed and 1 is not present in x list
            else if (messageChanged && !x.contains(1)) {
                wrongMessNotCaught++;
            }
            // If message has not been changed
            else if (!messageChanged) {
                correctMess++;
            }
        }
    }

    // Change message method
    public void changeMess() {
        // Change each element in message list with probability ber
        for (int i = 0; i < message.size(); i++) {
            if (Math.random() < ber) {
                messageChanged = true;
                message.set(i, message.get(i) ^ 1);
            }
        }

        // Update counter variable if message has been changed
        if (messageChanged) {
            wrongMess++;
        }
    }

    // Main method to run the simulation
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read input from user
        String divisor = scanner.next();
        int messageSize = scanner.nextInt();
        double ber = scanner.nextDouble();
        int numMessages = scanner.nextInt();

        // Create Main object with given input
        Main crc = new Main(divisor, messageSize, ber);

        // Generate and check messages for given number of times
        for (int i = 0; i < numMessages; i++) {
            crc.refactor(); // Refactor before each iteration
            crc.generateRandomMess(); // Generate random message
            crc.divideMessageWithP(false); // Divide message with p without checking
            crc.changeMess(); // Change message
            crc.divideMessageWithP(true); // Divide message with p and check
        }

        // Print the results
        System.out.println("Correct Messages: " + crc.getCorrectMess());
        System.out.println("Wrong Messages: " + crc.getWrongMess());
        System.out.println("Wrong Messages Caught: " + crc.getWrongMessCaught());
        System.out.println("Wrong Messages Not Caught: " + crc.getWrongMessNotCaught());

        scanner.close();
    }
}
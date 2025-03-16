import java.util.ArrayList;
import java.util.Scanner;
import java.util.concurrent.ThreadLocalRandom;
public class Main {
    private int correctMess; // Counter for correctly transmitted messages
    private int wrongMess; // Counter for messages with errors
    private int wrongMessCaught; // Counter for errors that were caught
    private int wrongMessNotCaught; // Counter for errors that were not caught
    private int messSize; // Size of the message
    private double ber; // Bit error rate
    private boolean messageChanged; // Flag to check if message has changed
    private ArrayList<Integer> message; // The message as a list of integers (0s and 1s)
    private ArrayList<Integer> p; // The polynomial used for CRC checking

    // Constructor to initialize the message and polynomial
    public Main(String str, int size, double ber) {
        messageChanged = false;
        message = new ArrayList<>();
        messSize = size;
        p = new ArrayList<>();
        for (int i = 0; i < str.length(); i++) {
            p.add(Character.getNumericValue(str.charAt(i)));
        }
        correctMess = 0;
        wrongMess = 0;
        wrongMessCaught = 0;
        wrongMessNotCaught = 0;
        this.ber = ber;
    }

    // Getter method to return the number of wrong messages
    public int getWrongMess() {
        return wrongMess;
    }

    // Getter method to return the number of wrong messages that were caught
    public int getWrongMessCaught() {
        return wrongMessCaught;
    }

    // Getter method to return the number of wrong messages that were not caught
    public int getWrongMessNotCaught() {
        return wrongMessNotCaught;
    }

    // Getter method to return the number of correct messages
    public int getCorrectMess() {
        return correctMess;
    }

    // Method to reset the message and set messageChanged to false
    public void refactor() {
        messageChanged = false;
        message = new ArrayList<>();
    }

    // Method to generate a random binary message of specified size
    public void generateRandomMess() {
        for (int i = 0; i < messSize; i++) {
            int x = ThreadLocalRandom.current().nextInt(0, 2);
            message.add(x);
        }
    }

    // Method to divide the message by the polynomial and check for errors
    public void divideMessageWithP(boolean check) {
        ArrayList<Integer> x = new ArrayList<>();
        ArrayList<Integer> k = new ArrayList<>(message);
        if (!check) {
            for (int i = 0; i < p.size() - 1; i++) {
                k.add(0);
            }
        }
        while (!k.isEmpty()) {
            while (x.size() < p.size() && !k.isEmpty()) {
                x.add(k.remove(0));
            }
            if (x.size() == p.size()) {
                for (int i = 0; i < p.size(); i++) {
                    x.set(i, x.get(i) ^ p.get(i)); 
                }
                while (!x.isEmpty() && x.get(0) == 0) {
                    x.remove(0);
                }
            }
        }
        if (!check) {
            message.addAll(x);
        } else {
            if (x.contains(1) && messageChanged) {
                wrongMessCaught++;
            } else if (!x.contains(1) && messageChanged) {
                wrongMessNotCaught++;
            } else if (!messageChanged) {
                correctMess++;
            }
        }
    }

    // Method to introduce errors into the message based on the BER
    public void changeMess() {
        for (int i = 0; i < message.size(); i++) {
            if (Math.random() < ber) {
                messageChanged = true;
                message.set(i, message.get(i) ^ 1); 
            }
        }
        if (messageChanged) {
            wrongMess++;
        }
    }

    // Main function to read input, create an instance, and process messages
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String divisor = scanner.next();
        int messageSize = scanner.nextInt();
        double ber = scanner.nextDouble();
        int numMessages = scanner.nextInt();
        Main crc = new Main(divisor, messageSize, ber);
        for (int i = 0; i < numMessages; i++) {
            crc.refactor();
            crc.generateRandomMess();
            crc.divideMessageWithP(false); 
            crc.changeMess(); 
            crc.divideMessageWithP(true); 
        }
        System.out.println("Correct Messages: " + crc.getCorrectMess());
        System.out.println("Wrong Messages: " + crc.getWrongMess());
        System.out.println("Wrong Messages Caught: " + crc.getWrongMessCaught());
        System.out.println("Wrong Messages Not Caught: " + crc.getWrongMessNotCaught());
        scanner.close();
    }
}

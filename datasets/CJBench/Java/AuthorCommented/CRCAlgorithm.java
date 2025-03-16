import java.util.ArrayList;
import java.util.Scanner;
import java.util.concurrent.ThreadLocalRandom;

/**
 * @author dimgrichr
 */
public class CRCAlgorithm {

    private int correctMess;
    private int wrongMess;
    private int wrongMessCaught;
    private int wrongMessNotCaught;
    private int messSize;
    private double ber;
    private boolean messageChanged;
    private ArrayList<Integer> message;
    private ArrayList<Integer> p;

    /**
     * The algorithm's main constructor. The most significant variables, used in
     * the algorithm, are set in their initial values.
     *
     * @param str The binary number P, in a string form, which is used by the
     * CRC algorithm
     * @param size The size of every transmitted message
     * @param ber The Bit Error Rate
     */
    public CRCAlgorithm(String str, int size, double ber) {
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

    /**
     * Returns the counter wrongMess
     *
     * @return wrongMess, the number of Wrong Messages
     */
    public int getWrongMess() {
        return wrongMess;
    }

    /**
     * Returns the counter wrongMessCaught
     *
     * @return wrongMessCaught, the number of wrong messages, which are caught
     * by the CRC algoriithm
     */
    public int getWrongMessCaught() {
        return wrongMessCaught;
    }

    /**
     * Returns the counter wrongMessNotCaught
     *
     * @return wrongMessNotCaught, the number of wrong messages, which are not
     * caught by the CRC algorithm
     */
    public int getWrongMessNotCaught() {
        return wrongMessNotCaught;
    }

    /**
     * Returns the counter correctMess
     *
     * @return correctMess, the number of the Correct Messages
     */
    public int getCorrectMess() {
        return correctMess;
    }

    /**
     * Resets some of the object's values, used on the main function, so that it
     * can be re-used, in order not to waste too much memory and time, by
     * creating new objects.
     */
    public void refactor() {
        messageChanged = false;
        message = new ArrayList<>();
    }

    /**
     * Random messages, consisted of 0's and 1's, are generated, so that they
     * can later be transmitted
     */
    public void generateRandomMess() {
        for (int i = 0; i < messSize; i++) {
            int x = ThreadLocalRandom.current().nextInt(0, 2);
            message.add(x);
        }
    }

    /**
     * The most significant part of the CRC algorithm. The message is divided by
     * P, so the dividedMessage ArrayList<Integer> is created. If check == true,
     * the dividedMessaage is examined, in order to see if it contains any 1's.
     * If it does, the message is considered to be wrong by the receiver,so the
     * variable wrongMessCaught changes. If it does not, it is accepted, so one
     * of the variables correctMess, wrongMessNotCaught, changes. If check ==
     * false, the diviided Message is added at the end of the ArrayList<integer>
     * message.
     *
     * @param check the variable used to determine, if the message is going to
     * be checked from the receiver if true, it is checked otherwise, it is not
     */
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
                    x.set(i, x.get(i) ^ p.get(i)); // XOR operation
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

    /**
     * Once the message is transmitted, some of it's elements, is possible to
     * change from 1 to 0, or from 0 to 1, because of the Bit Error Rate (ber).
     * For every element of the message, a random double number is created. If
     * that number is smaller than ber, then the spesific element changes. On
     * the other hand, if it's bigger than ber, it does not. Based on these
     * changes. the boolean variable messageChanged, gets the value: true, or
     * false.
     */
    public void changeMess() {
        for (int i = 0; i < message.size(); i++) {
            if (Math.random() < ber) {
                messageChanged = true;
                message.set(i, message.get(i) ^ 1); // Flip bit
            }
        }
        if (messageChanged) {
            wrongMess++;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read CRC divisor (binary string), message size, and BER
        String divisor = scanner.next();
        int messageSize = scanner.nextInt();
        double ber = scanner.nextDouble();

        // Number of messages to transmit
        int numMessages = scanner.nextInt();

        CRCAlgorithm crc = new CRCAlgorithm(divisor, messageSize, ber);

        for (int i = 0; i < numMessages; i++) {
            crc.refactor();
            crc.generateRandomMess();
            crc.divideMessageWithP(false); // Append CRC to the message
            crc.changeMess(); // Simulate errors in transmission
            crc.divideMessageWithP(true); // Check received message
        }

        // Output results
        System.out.println("Correct Messages: " + crc.getCorrectMess());
        System.out.println("Wrong Messages: " + crc.getWrongMess());
        System.out.println("Wrong Messages Caught: " + crc.getWrongMessCaught());
        System.out.println("Wrong Messages Not Caught: " + crc.getWrongMessNotCaught());

        scanner.close();
    }
}

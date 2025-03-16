import java.util.ArrayList;
import java.util.Scanner;
import java.util.concurrent.ThreadLocalRandom;
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
    public void refactor() {
        messageChanged = false;
        message = new ArrayList<>();
    }
    public void generateRandomMess() {
        for (int i = 0; i < messSize; i++) {
            int x = ThreadLocalRandom.current().nextInt(0, 2);
            message.add(x);
        }
    }
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
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String divisor = scanner.next();
        int messageSize = scanner.nextInt();
        double ber = scanner.nextDouble();
        int numMessages = scanner.nextInt();
        CRCAlgorithm crc = new CRCAlgorithm(divisor, messageSize, ber);
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

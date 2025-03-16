import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String n = scanner.nextLine();
        String[] a = {"10", "100", "1000", "10000", "100000"};
        int newSum = 0;
        
        for (char digit : n.toCharArray()) {
            newSum += Character.getNumericValue(digit);
        }
        
        boolean isInArray = false;
        for (String s : a) {
            if (n.equals(s)) {
                isInArray = true;
                break;
            }
        }
        
        if (isInArray) {
            System.out.println(10);
        } else {
            System.out.println(newSum);
        }
    }
}


import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();

        int count = 0;
        int[] counter = new int[1];

        if (s.equals("")) {
            return;
        }
        counter[0] = 0;
        String[] li = s.split("");

        for (String s : li) {
            if (s.equals("A") || s.equals("C") || s.equals("G") || s.equals("T")) {
                count++;
            } else {
                counter = append(counter, count);
                count = 0;
            }
        }

        counter = append(counter, count);
        sort(counter);
        System.out.println(counter[counter.length - 1]);
    }

    public static int[] append(int[] counter, int count) {
        int[] newCounter = new int[counter.length + 1];
        for (int i = 0; i < counter.length; i++) {
            newCounter[i] = counter[i];
        }
        newCounter[counter.length] = count;
        return newCounter;
    }

    public static void sort(int[] counter) {
        for (int i = 0; i < counter.length - 1; i++) {
            for (int j = i + 1; j < counter.length; j++) {
                if (counter[i] < counter[j]) {
                    int temp = counter[i];
                    counter[i] = counter[j];
                    counter[j] = temp;
                }
            }
        }
    }
}



import java.util.Scanner;
import java.util.Arrays;

public class s120583500{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();

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
        Arrays.sort(counter);
        System.out.println(counter[counter.length - 1]);
    }

    public static int[] append(int[] array, int value) {
        int[] newArray = new int[array.length + 1];
        System.arraycopy(array, 0, newArray, 0, array.length);
        newArray[newArray.length - 1] = value;
        return newArray;
    }
}


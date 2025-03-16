

import java.util.Scanner;

public class codeforces_474_B{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String[] input1 = scanner.nextLine().split(" ");
        int[] array = new int[input1.length];
        int r = 1;
        for (int i = 0; i < input1.length; i++) {
            array[i] = r;
            r++;
        }
        String[] input2 = scanner.nextLine().split(" ");
        for (int i = 0; i < input2.length; i++) {
            System.out.println(array[Integer.parseInt(input2[i]) - 1]);
        }
    }
}

Translate the above Python code to JavaScript and end with comment "


import java.util.Scanner;

public class s134607050{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String text = scanner.nextLine();
        int limit = text.length();

        int start = 0;
        int middle = 0;
        int end = 0;
        boolean firstPrinted = false;

        while (end < limit) {
            start = searchRange(text, start, limit);
            middle = start;
            end = limit;

            for (int i = start; i < middle - 1; i++) {
                if (firstPrinted) {
                    System.out.print(" ");
                }
                System.out.print("0");
                firstPrinted = true;
            }

            if (firstPrinted) {
                System.out.print(" ");
            }
            System.out.printf("%v %v", (middle - start) / 2 + (end - middle) / 2, (middle - start) / 2 + (end - middle + 1) / 2);
            firstPrinted = true;

            for (int i = middle + 1; i < end; i++) {
                if (firstPrinted) {
                    System.out.print(" ");
                }
                System.out.print("0");
                firstPrinted = true;
            }
            start = end;
            firstPrinted = true;
        }
        System.out.println();
    }

    public static int searchRange(String text, int start, int limit) {
        int middle = -1;

        for (int i = start; i < limit; i++) {
            if (text.charAt(i)!= 'R') {
                middle = i;
                break;
            }
        }

        int end = limit;

        for (int i = middle; i < limit; i++) {
            if (text.charAt(i)!= 'L') {
                end = i;
                break;
            }
        }

        return start;
    }
}

// Translate the above Java code to Python and end with comment "
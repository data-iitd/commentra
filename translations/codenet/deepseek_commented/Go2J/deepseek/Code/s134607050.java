public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        String text = scanner.nextLine();
        int limit = text.length();

        int start = 0;
        int middle = 0;
        int end = 0;
        boolean firstPrinted = false;

        while (end < limit) {
            start = findFirstR(text, start, limit);
            middle = findFirstL(text, start, limit);
            end = findFirstL(text, middle, limit);

            int len1 = middle - start;
            int len2 = end - middle;

            for (int i = start; i < middle - 1; i++) {
                if (firstPrinted) {
                    System.out.print(" ");
                }
                System.out.print("0");
                firstPrinted = true;
            }

            int count1 = (len1 + 1) / 2 + len2 / 2;
            int count2 = len1 / 2 + (len2 + 1) / 2;

            if (firstPrinted) {
                System.out.print(" ");
            }
            System.out.print(count1 + " " + count2);
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

    private static int findFirstR(String text, int start, int limit) {
        for (int i = start; i < limit; i++) {
            if (text.charAt(i) == 'R') {
                return i;
            }
        }
        return limit;
    }

    private static int findFirstL(String text, int start, int limit) {
        for (int i = start; i < limit; i++) {
            if (text.charAt(i) == 'L') {
                return i;
            }
        }
        return limit;
    }
}

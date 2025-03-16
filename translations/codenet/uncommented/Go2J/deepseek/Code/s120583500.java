public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        String s = scanner.nextLine();

        int count = 0;
        int[] counter = new int[0];

        if (s.isEmpty()) {
            return;
        }
        counter = java.util.Arrays.copyOf(counter, counter.length + 1);
        counter[counter.length - 1] = 0;
        String[] li = s.split("");

        for (String str : li) {
            if (str.equals("A") || str.equals("C") || str.equals("G") || str.equals("T")) {
                count++;
            } else {
                int[] newCounter = new int[counter.length + 1];
                System.arraycopy(counter, 0, newCounter, 0, counter.length);
                newCounter[counter.length] = count;
                counter = newCounter;
                count = 0;
            }
        }

        counter = java.util.Arrays.copyOf(counter, counter.length + 1);
        counter[counter.length - 1] = count;
        java.util.Arrays.sort(counter);
        System.out.println(counter[counter.length - 1]);
    }
}

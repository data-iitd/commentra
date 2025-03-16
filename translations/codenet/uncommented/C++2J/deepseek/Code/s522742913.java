public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        String source = scanner.nextLine();

        if (source.length() > 10 || source.length() < 1) {
            return;
        }

        int max_i = (int) Math.pow(2, source.length() - 1);

        double sum = 0;

        for (int i = 0; i < max_i; ++i) {
            java.util.BitSet plus = java.util.BitSet.valueOf(new long[]{i});

            double number = 0;

            String working = source;
            while (plus.nextSetBit(0) != -1) {
                int index = plus.nextSetBit(0);
                sum += Double.parseDouble(working.substring(0, index + 1));
                working = working.substring(index + 1);
                plus.clear(0, index + 1);
            }
            sum += Double.parseDouble(working);
        }

        System.out.printf("%.0f%n", sum);
    }
}

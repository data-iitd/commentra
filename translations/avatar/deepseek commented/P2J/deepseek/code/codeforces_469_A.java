public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int maxLevel = scanner.nextInt();
        int[] x = new int[maxLevel];
        int[] y = new int[maxLevel];

        for (int i = 0; i < 2; i++) {
            int n = scanner.nextInt();
            for (int j = 0; j < n; j++) {
                int level = scanner.nextInt();
                if (i == 0) {
                    x[level - 1] = level;
                } else {
                    y[level - 1] = level;
                }
            }
        }

        Set<Integer> levels = new HashSet<>();
        for (int i = 0; i < maxLevel; i++) {
            if (x[i] != 0) {
                levels.add(x[i]);
            }
            if (y[i] != 0) {
                levels.add(y[i]);
            }
        }

        if (levels.size() == maxLevel) {
            System.out.println("I become the guy.");
        } else {
            System.out.println("Oh, my keyboard!");
        }
    }
}

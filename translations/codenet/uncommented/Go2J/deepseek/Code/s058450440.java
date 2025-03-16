public class Main {
    static int[] a;
    static int ans = 0;

    public static void dfs(int left, int i, int res) {
        if (left == 0) {
            ans += res;
            return;
        }
        for (int j = i; j < a.length; j++) {
            dfs(left - 1, j + 1, res * a[j]);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Map<Character, Integer> dic = new HashMap<>();

        for (int i = 0; i < n; i++) {
            char c = scanner.next().charAt(0);
            if (c == 'M' || c == 'A' || c == 'R' || c == 'C' || c == 'H') {
                dic.put(c, dic.getOrDefault(c, 0) + 1);
            }
        }

        int index = 0;
        a = new int[dic.size()];
        for (int value : dic.values()) {
            a[index++] = value;
        }

        dfs(3, 0, 1);
        System.out.println(ans);
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        System.out.println(nPairsWithCommonFX(scanner.nextLine().split(" ")));
    }

    public static int nPairsWithCommonFX(String[] sequence) {
        Map<Integer, List<Integer>> storage = new HashMap<>();
        List<Integer> FXs = new ArrayList<>();
        for (String value : sequence) {
            int y = f(Integer.parseInt(value));
            if (!storage.containsKey(y)) {
                storage.put(y, new ArrayList<>());
                FXs.add(y);
            }
            storage.get(y).add(Integer.parseInt(value));
        }
        int sum = 0;
        for (Integer y : FXs) {
            sum += storage.get(y).size() * (storage.get(y).size() - 1);
        }
        return sum / 2;
    }

    public static int f(int n) {
        int y = 1;
        while (n != 1) {
            if (n % 2 != 0) {
                y++;
            }
            n /= 2;
        }
        return y;
    }
}

public class Main {
    public static void main(String[] args) {
        int n;
        int[] array = new int[100];
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        for (int i = 0; i < n; i++) {
            array[i] = scanner.nextInt();
        }

        int sum = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                sum += array[i] * array[j];
            }
        }

        System.out.println(sum);
    }
}

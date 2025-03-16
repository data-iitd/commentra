public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int N = scanner.nextInt();
        int[] values = new int[N];
        int[] indices = new int[N];

        for (int i = 0; i < N; i++) {
            values[i] = scanner.nextInt();
            indices[i] = i + 1;
        }

        for (int i = 0; i < N - 1; i++) {
            for (int j = i + 1; j < N; j++) {
                if (values[i] > values[j]) {
                    // Swap values
                    int tempValue = values[i];
                    values[i] = values[j];
                    values[j] = tempValue;

                    // Swap indices
                    int tempIndex = indices[i];
                    indices[i] = indices[j];
                    indices[j] = tempIndex;
                }
            }
        }

        for (int i = 0; i < N - 1; i++) {
            System.out.print(indices[i] + " ");
        }
        System.out.println(indices[N - 1]);
    }
}


public class Main {
    public static void main(String[] args) {
        int[] io = {1, 2, 3, 4, 5};
        for (int i = 0; i < io.length; i++) {
            int max = io[i];
            int max_j = i;
            for (int j = i + 1; j < io.length; j++) {
                if (max < io[j]) {
                    max = io[j];
                    max_j = j;
                }
            }
            int buf = io[i];
            io[i] = io[max_j];
            io[max_j] = buf;
            if (i < io.length - 1) {
                System.out.print(io[i] + " ");
            } else {
                System.out.println(io[i]);
            }
        }
    }
}


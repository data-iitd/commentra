public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String[] firstLine = reader.readLine().split(" ");
        int N = Integer.parseInt(firstLine[0]);
        int D = Integer.parseInt(firstLine[1]);

        int[][] lines = new int[N][2];
        for (int i = 0; i < N; i++) {
            String[] line = reader.readLine().split(" ");
            lines[i][0] = Integer.parseInt(line[0]);
            lines[i][1] = Integer.parseInt(line[1]);
        }

        int count = 0;
        for (int[] line : lines) {
            double d = Math.sqrt(line[0] * line[0] + line[1] * line[1]);
            if (D >= d) {
                count++;
            }
        }

        System.out.println(count);
    }
}

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.lang.Math;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter writer = new PrintWriter(System.out);
        Run(reader, writer);
        writer.close();
    }

    public static void Run(BufferedReader reader, PrintWriter writer) throws IOException {
        Scanner scanner = new Scanner(reader);

        // Read the first line which contains two integers N and D.
        int[] a = scanner.readLine().ints();
        int N = a[0], D = a[1];

        // Read the next N lines which contain pairs of integers representing points.
        List<int[]> lines = scanner.readLines(N, scanner.readLine());

        // Initialize a counter to keep track of points within the given distance.
        int count = 0;

        // Iterate over each point and calculate the distance from the origin.
        for (int[] line : lines) {
            // Calculate the Euclidean distance of the point from the origin.
            double d = Math.sqrt(line[0] * line[0] + line[1] * line[1]);
            // Check if the distance is within the given limit.
            if (D >= d) {
                count++;
            }
        }

        // Write the count of points within the distance to the writer.
        writer.println(count);
    }

    static class Scanner {
        private BufferedReader reader;
        private StringTokenizer tokenizer;

        public Scanner(BufferedReader reader) {
            this.reader = reader;
        }

        public String nextLine() throws IOException {
            return reader.readLine();
        }

        public int[] ints(String line) {
            StringTokenizer tokenizer = new StringTokenizer(line);
            int[] a = new int[tokenizer.countTokens()];
            for (int i = 0; i < a.length; i++) {
                a[i] = Integer.parseInt(tokenizer.nextToken());
            }
            return a;
        }

        public List<int[]> readLines(int n, BufferedReader reader) throws IOException {
            List<int[]> lines = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                lines.add(ints(reader.readLine()));
            }
            return lines;
        }
    }
}

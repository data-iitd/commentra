import java.util.*;
import java.io.*;
import java.lang.Math;
import java.util.stream.Collectors;

public class Main {
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }

    static class Solution {
        public static void main(String[] args) {
            FastReader scanner = new FastReader();
            List<String> l = new ArrayList<>();
            for (int i = 0; i < 3; i++) {
                l.add(processString(scanner.nextLine()));
            }
            List<String> permutations = generatePermutations(l);
            Set<String> permutationSet = new HashSet<>(permutations);
            int testCases = scanner.nextInt();
            for (int i = 0; i < testCases; i++) {
                String input = processString(scanner.nextLine());
                if (permutationSet.contains(input)) {
                    System.out.println("ACC");
                } else {
                    System.out.println("WA");
                }
            }
        }

        private static String processString(String s) {
            return s.chars()
                    .filter(c -> c != '-' && c != ';' && c != '_')
                    .mapToObj(Character::toLowerCase)
                    .collect(StringBuilder::new, StringBuilder::appendCodePoint, StringBuilder::append)
                    .toString();
        }

        private static List<String> generatePermutations(List<String> list) {
            List<String> result = new ArrayList<>();
            generatePermutationsHelper(list, 0, result);
            return result;
        }

        private static void generatePermutationsHelper(List<String> list, int index, List<String> result) {
            if (index == list.size() - 1) {
                result.add(String.join("", list));
                return;
            }
            for (int i = index; i < list.size(); i++) {
                Collections.swap(list, index, i);
                generatePermutationsHelper(list, index + 1, result);
                Collections.swap(list, index, i);
            }
        }
    }
}

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        List<String> res = new ArrayList<>();
        String[] punctuation = {",", ".", "!", "?"};

        for (int i = 0; i < s.length(); i++) {
            if (i >= 1) {
                if (s.charAt(i) == ' ') {
                    if (!res.get(res.size() - 1).equals("")) {
                        res.add(String.valueOf(s.charAt(i)));
                    } else {
                        continue;
                    }
                } else {
                    if (contains(punctuation, s.charAt(i))) {
                        if (res.get(res.size() - 1).equals("")) {
                            res.remove(res.size() - 1);
                        }
                        res.add(String.valueOf(s.charAt(i)));
                        res.add(" ");
                    } else {
                        res.add(String.valueOf(s.charAt(i)));
                    }
                }
            } else {
                if (s.charAt(i) == ' ') {
                    continue;
                }
                if (contains(punctuation, s.charAt(i))) {
                    continue;
                } else {
                    res.add(String.valueOf(s.charAt(i)));
                }
            }
        }

        StringBuilder result = new StringBuilder();
        for (String str : res) {
            result.append(str);
        }
        System.out.println(result.toString());
    }

    public static boolean contains(String[] array, char value) {
        for (String str : array) {
            if (str.charAt(0) == value) {
                return true;
            }
        }
        return false;
    }
}

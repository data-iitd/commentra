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
            char currentChar = s.charAt(i);
            if (i >= 1) {
                if (currentChar == ' ') {
                    if (!res.isEmpty() && !res.get(res.size() - 1).equals("")) {
                        res.add(String.valueOf(currentChar));
                    }
                } else {
                    boolean isPunctuation = false;
                    for (String punc : punctuation) {
                        if (String.valueOf(currentChar).equals(punc)) {
                            isPunctuation = true;
                            break;
                        }
                    }
                    if (isPunctuation) {
                        if (!res.isEmpty() && res.get(res.size() - 1).equals("")) {
                            res.remove(res.size() - 1);
                        }
                        res.add(String.valueOf(currentChar));
                        res.add(" ");
                    } else {
                        res.add(String.valueOf(currentChar));
                    }
                }
            } else {
                if (currentChar == ' ') {
                    continue;
                }
                boolean isPunctuation = false;
                for (String punc : punctuation) {
                    if (String.valueOf(currentChar).equals(punc)) {
                        isPunctuation = true;
                        break;
                    }
                }
                if (!isPunctuation) {
                    res.add(String.valueOf(currentChar));
                }
            }
        }

        StringBuilder result = new StringBuilder();
        for (String str : res) {
            result.append(str);
        }
        System.out.println(result.toString());
    }
}

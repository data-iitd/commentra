import java.util.*;  // For utility classes like List, Map, etc.

public class Main {
    // Utility function to convert a string to a string representation.
    static String toString(String s) {
        return s;
    }

    // Utility function to convert a pair to a string representation.
    static <S, T> String toString(Pair<S, T> p) {
        return "{" + toString(p.first) + "," + toString(p.second) + "}";
    }

    // Utility function to convert a list to a string representation.
    static <T> String toString(List<T> v) {
        StringBuilder ret = new StringBuilder("{");
        for (int i = 0; i < v.size() - 1; ++i) {
            ret.append(toString(v.get(i))).append(",");
        }
        if (v.size() > 0) {
            ret.append(toString(v.get(v.size() - 1)));
        }
        ret.append("}");
        return ret.toString();
    }

    // Debug function to print debug information.
    static void debug(Object... args) {
        System.err.println(Arrays.toString(args));
    }

    // Print function to print multiple items.
    static void print(Object... args) {
        System.out.println(Arrays.toString(args));
    }

    // Main function to execute the program.
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String S = scanner.next();
        if (S.equals("Sunny")) {
            print("Cloudy");
        } else if (S.equals("Cloudy")) {
            print("Rainy");
        } else {
            print("Sunny");
        }
        scanner.close();
    }
}

// Pair class to hold two related objects.
class Pair<S, T> {
    S first;
    T second;

    Pair(S first, T second) {
        this.first = first;
        this.second = second;
    }
}

// <END-OF-CODE>

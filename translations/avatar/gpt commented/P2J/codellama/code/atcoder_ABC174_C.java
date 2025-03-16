
// Import necessary libraries
import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;
import java.util.Collections;
import java.util.Comparator;

// Define input functions for convenience
public static int ii1() {
    return sc.nextInt();
}

public static String is1() {
    return sc.next();
}

public static List<Integer> iia() {
    List<Integer> list = new ArrayList<>();
    for (int i = 0; i < sc.nextInt(); i++) {
        list.add(sc.nextInt());
    }
    return list;
}

public static List<String> isa() {
    List<String> list = new ArrayList<>();
    for (int i = 0; i < sc.nextInt(); i++) {
        list.add(sc.next());
    }
    return list;
}

// Define a constant for modulo operations
public static final int mod = 1000000007;

// Define a comparator for sorting integers in descending order
public static Comparator<Integer> desc = new Comparator<Integer>() {
    @Override
    public int compare(Integer a, Integer b) {
        return b - a;
    }
};

// Define a comparator for sorting strings in ascending order
public static Comparator<String> asc = new Comparator<String>() {
    @Override
    public int compare(String a, String b) {
        return a.compareTo(b);
    }
};

// Define a comparator for sorting strings in descending order
public static Comparator<String> desc = new Comparator<String>() {
    @Override
    public int compare(String a, String b) {
        return b.compareTo(a);
    }
};

// Define a comparator for sorting pairs of integers in descending order
public static Comparator<Pair<Integer, Integer>> desc = new Comparator<Pair<Integer, Integer>>() {
    @Override
    public int compare(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        return b.getKey() - a.getKey();
    }
};

// Define a comparator for sorting pairs of strings in ascending order
public static Comparator<Pair<String, String>> asc = new Comparator<Pair<String, String>>() {
    @Override
    public int compare(Pair<String, String> a, Pair<String, String> b) {
        return a.getKey().compareTo(b.getKey());
    }
};

// Define a comparator for sorting pairs of strings in descending order
public static Comparator<Pair<String, String>> desc = new Comparator<Pair<String, String>>() {
    @Override
    public int compare(Pair<String, String> a, Pair<String, String> b) {
        return b.getKey().compareTo(a.getKey());
    }
};

// Define a comparator for sorting pairs of integers in ascending order
public static Comparator<Pair<Integer, Integer>> asc = new Comparator<Pair<Integer, Integer>>() {
    @Override
    public int compare(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        return a.getKey() - b.getKey();
    }
};

// Define a comparator for sorting pairs of integers in descending order
public static Comparator<Pair<Integer, Integer>> desc = new Comparator<Pair<Integer, Integer>>() {
    @Override
    public int compare(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        return b.getKey() - a.getKey();
    }
};

// Define a comparator for sorting pairs of strings in ascending order
public static Comparator<Pair<String, String>> asc = new Comparator<Pair<String, String>>() {
    @Override
    public int compare(Pair<String, String> a, Pair<String, String> b) {
        return a.getKey().compareTo(b.getKey());
    }
};

// Define a comparator for sorting pairs of strings in descending order
public static Comparator<Pair<String, String>> desc = new Comparator<Pair<String, String>>() {
    @Override
    public int compare(Pair<String, String> a, Pair<String, String> b) {
        return b.getKey().compareTo(a.getKey());
    }
};

// Define a comparator for sorting pairs of integers in ascending order
public static Comparator<Pair<Integer, Integer>> asc = new Comparator<Pair<Integer, Integer>>() {
    @Override
    public int compare(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        return a.getKey() - b.getKey();
    }
};

// Define a comparator for sorting pairs of integers in descending order
public static Comparator<Pair<Integer, Integer>> desc = new Comparator<Pair<Integer, Integer>>() {
    @Override
    public int compare(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        return b.getKey() - a.getKey();
    }
};

// Define a comparator for sorting pairs of strings in ascending order
public static Comparator<Pair<String, String>> asc = new Comparator<Pair<String, String>>() {
    @Override
    public int compare(Pair<String, String> a, Pair<String, String> b) {
        return a.getKey().compareTo(b.getKey());
    }
};

// Define a comparator for sorting pairs of strings in descending order
public static Comparator<Pair<String, String>> desc = new Comparator<Pair<String, String>>() {
    @Override
    public int compare(Pair<String, String> a, Pair<String, String> b) {
        return b.getKey().compareTo(a.getKey());
    }
};

// Define a comparator for sorting pairs of integers in ascending order
public static Comparator<Pair<Integer, Integer>> asc = new Comparator<Pair<Integer, Integer>>() {
    @Override
    public int compare(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        return a.getKey() - b.getKey();
    }
};

// Define a comparator for sorting pairs of integers in descending order
public static Comparator<Pair<Integer, Integer>> desc = new Comparator<Pair<Integer, Integer>>() {
    @Override
    public int compare(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        return b.getKey() - a.getKey();
    }
};

// Define a comparator for sorting pairs of strings in ascending order
public static Comparator<Pair<String, String>> asc = new Comparator<Pair<String, String>>() {
    @Override
    public int compare(Pair<String, String> a, Pair<String, String> b) {
        return a.getKey().compareTo(b.getKey());
    }
};

// Define a comparator for sorting pairs of strings in descending order
public static Comparator<Pair<String, String>> desc = new Comparator<Pair<String, String>>() {
    @Override
    public int compare(Pair<String, String> a, Pair<String, String> b) {
        return b.getKey().compareTo(a.getKey());
    }
};

// Define a comparator for sorting pairs of integers in ascending order
public static Comparator<Pair<Integer, Integer>> asc = new Comparator<Pair<Integer, Integer>>() {
    @Override
    public int compare(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        return a.getKey() - b.getKey();
    }
};

// Define a comparator for sorting pairs of integers in descending order
public static Comparator<Pair<Integer, Integer>> desc = new Comparator<Pair<Integer, Integer>>() {
    @Override
    public int compare(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        return b.getKey() - a.getKey();
    }
};

// Define a comparator for sorting pairs of strings in ascending order
public static Comparator<Pair<String, String>> asc = new Comparator<Pair<String, String>>() {
    @Override
    public int compare(Pair<String, String> a, Pair<String, String> b) {
        return a.getKey().compareTo(b.getKey());
    }
};

// Define a comparator for sorting pairs of strings in descending order
public static Comparator<Pair<String, String>> desc = new Comparator<Pair<String, String>>() {
    @Override
    public int compare(Pair<String, String> a, Pair<String, String> b) {
        return b.getKey().compareTo(a.getKey());
    }
};

// Define a comparator for sorting pairs of integers in ascending order
public static Comparator<Pair<Integer, Integer>> asc = new Comparator<Pair<Integer, Integer>>() {
    @Override
    public int compare(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        return a.getKey() - b.getKey();
    }
};

// Define a comparator for sorting pairs of integers in descending order
public static Comparator<Pair<Integer, Integer>> desc = new Comparator<Pair<Integer, Integer>>() {
    @Override
    public int compare(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        return b.getKey() - a.getKey();
    }
};

// Define a comparator for sorting pairs of strings in ascending order
public static Comparator<Pair<String, String>> asc = new Comparator<Pair<String, String>>() {
    @Override
    public int compare(Pair<String, String> a, Pair<String, String> b) {
        return a.getKey().compareTo(b.getKey());
    }
};

// Define a comparator for sorting pairs of strings in descending order
public static Comparator<Pair<String, String>> desc = new Comparator<Pair<String, String>>() {
    @Override
    public int compare(Pair<String, String> a, Pair<String, String> b) {
        return b.getKey().compareTo(a.getKey());
    }
};

// Define a comparator for sorting pairs of integers in ascending order
public static Comparator<Pair<Integer, Integer>> asc = new Comparator<Pair<Integer, Integer>>() {
    @Override
    public int compare(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        return a.getKey() - b.getKey();
    }
};

// Define a comparator for sorting pairs of integers in descending order
public static Comparator<Pair<Integer, Integer>> desc = new Comparator<Pair<Integer, Integer>>() {
    @Override
    public int compare(Pair<Integer, Integer> a, Pair<Integer, Integer> b) {
        return b.getKey() - a.getKey();
    }
};

// Define a comparator for sorting pairs of strings in ascending order
public static Comparator<Pair<String, String>> asc = new Comparator<Pair<String, String>>() {
    @Override
    public int compare(Pair<String, String> a, Pair<String, String> b) {
        return a.getKey().compareTo(b.getKey());
    }
};

// Define a comparator for sorting pairs of strings in descending order
public static Comparator<Pair<String, String>> desc = new Comparator<Pair<String, String>>() {
    @Override
    public int compare(Pair<String, String> a, Pair<String, String> b) {
        return b.getKey().compareTo(a.getKey());
    }
};

// Define a comparator for sorting pairs of integers in ascending order
public static Comparator<Pair<Integer, Integer>> asc =
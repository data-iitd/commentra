import java.text.DecimalFormat;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.NoSuchElementException;
import java.util.Scanner;
import java.util.Set;
// Import statements for necessary classes

public final class Main {
    // The Main class is the entry point of the application

    private final Map<Pair<String, String>, AffineConverter> conversions;
    // Map to store all possible conversions

    private final Set<String> units;
    // Set to store all available units

    public Main(final Map<Pair<String, String>, AffineConverter> basicConversions) {
        // Constructor initializes the conversions and units
        conversions = computeAllConversions(basicConversions);
        units = extractUnits(conversions);
    }
    // Constructor that takes a map of basic conversions and computes all possible conversions

    public double convert(final String inputUnit, final String outputUnit, final double value) {
        // Method to convert a value from one unit to another
        if (inputUnit.equals(outputUnit)) {
            throw new IllegalArgumentException("Input and output units must be different.");
        }
        // Throws an exception if the input and output units are the same
        final var conversionKey = Pair.of(inputUnit, outputUnit);
        double result = conversions.computeIfAbsent(conversionKey, k -> {
            throw new NoSuchElementException("No converter for: " + k);
        }).convert(value);
        // Computes the conversion using the AffineConverter and throws an exception if no converter is found
        DecimalFormat df = new DecimalFormat("#.##");
        return Double.parseDouble(df.format(result));
        // Formats the result to two decimal places
    }
    // Method to convert a value from one unit to another

    public Set<String> availableUnits() {
        return units;
    }
    // Method to return all available units

    private static void putIfNeeded(Map<Pair<String, String>, AffineConverter> conversions, String inputUnit, String outputUnit, AffineConverter converter) {
        // Helper method to add conversions only if input and output units are different
        if (!inputUnit.equals(outputUnit)) {
            conversions.putIfAbsent(Pair.of(inputUnit, outputUnit), converter);
        }
    }
    // Helper method to add conversions only if input and output units are different

    private static Map<Pair<String, String>, AffineConverter> addInversions(Map<Pair<String, String>, AffineConverter> knownConversions) {
        // Helper method to add inversions of known conversions
        Map<Pair<String, String>, AffineConverter> res = new HashMap<>();
        for (var entry : knownConversions.entrySet()) {
            var inputUnit = entry.getKey().getKey();
            var outputUnit = entry.getKey().getValue();
            var converter = entry.getValue();
            putIfNeeded(res, inputUnit, outputUnit, converter);
            putIfNeeded(res, outputUnit, inputUnit, converter.invert());
        }
        return res;
    }
    // Helper method to add inversions of known conversions

    private static Map<Pair<String, String>, AffineConverter> addCompositions(Map<Pair<String, String>, AffineConverter> knownConversions) {
        // Helper method to add compositions of known conversions
        Map<Pair<String, String>, AffineConverter> res = new HashMap<>();
        for (var first : knownConversions.entrySet()) {
            var firstKey = first.getKey();
            putIfNeeded(res, firstKey.getKey(), firstKey.getValue(), first.getValue());
            for (var second : knownConversions.entrySet()) {
                var secondKey = second.getKey();
                if (firstKey.getValue().equals(secondKey.getKey())) {
                    var composedConverter = second.getValue().compose(first.getValue());
                    putIfNeeded(res, firstKey.getKey(), secondKey.getValue(), composedConverter);
                }
            }
        }
        return res;
    }
    // Helper method to add compositions of known conversions

    private static Map<Pair<String, String>, AffineConverter> computeAllConversions(Map<Pair<String, String>, AffineConverter> basicConversions) {
        var tmp = basicConversions;
        var res = addAll(tmp);
        while (res.size() != tmp.size()) {
            tmp = res;
            res = addAll(tmp);
        }
        return res;
    }
    // Helper method to compute all possible conversions

    private static Map<Pair<String, String>, AffineConverter> addAll(Map<Pair<String, String>, AffineConverter> knownConversions) {
        var res = addInversions(knownConversions);
        return addCompositions(res);
    }
    // Helper method to add inversions and compositions of known conversions

    private static Set<String> extractUnits(Map<Pair<String, String>, AffineConverter> conversions) {
        Set<String> res = new HashSet<>();
        for (var entry : conversions.entrySet()) {
            res.add(entry.getKey().getKey());
            res.add(entry.getKey().getValue());
        }
        return res;
    }
    // Helper method to extract all units from the conversions map

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Map<Pair<String, String>, AffineConverter> basicConversions = new HashMap<>();
        basicConversions.put(Pair.of("Celsius", "Fahrenheit"), new AffineConverter(9.0 / 5.0, 32.0));
        basicConversions.put(Pair.of("Kelvin", "Celsius"), new AffineConverter(1.0, -273.15));
        Main converter = new Main(basicConversions);
        String inputUnit = scanner.nextLine();
        String outputUnit = scanner.nextLine();
        double value = scanner.nextDouble();
        try {
            double result = converter.convert(inputUnit, outputUnit, value);
            System.out.println("Converted value: " + result);
        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
        }
        scanner.close();
    }
    // Main method to read input units, output units, and values from the user and convert the value
}
// The Main class is the entry point of the application

class Pair<K, V> {
    // Generic Pair class to represent pairs of keys and values
    private final K key;
    private final V value;
    private Pair(K key, V value) {
        this.key = key;
        this.value = value;
    }
    public static <K, V> Pair<K, V> of(K key, V value) {
        return new Pair<>(key, value);
    }
    public K getKey() {
        return key;
    }
    public V getValue() {
        return value;
    }
    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Pair<?, ?> pair = (Pair<?, ?>) o;
        return key.equals(pair.key) && value.equals(pair.value);
    }
    @Override
    public int hashCode() {
        return key.hashCode() * 31 + value.hashCode();
    }
    @Override
    public String toString() {
        return "(" + key + ", " + value + ")";
    }
}
// Pair class to represent pairs of keys and values

class AffineConverter {
    // Class to perform affine transformations (linear transformations with an offset)
    private final double scale;
    private final double offset;
    public AffineConverter(double scale, double offset) {
        this.scale = scale;
        this.offset = offset;
    }
    public double convert(double value) {
        return scale * value + offset;
    }
    public AffineConverter invert() {
        if (scale == 0) {
            throw new ArithmeticException("Cannot invert a scale of zero.");
        }
        return new AffineConverter(1 / scale, -offset / scale);
    }
    public AffineConverter compose(AffineConverter other) {
        return new AffineConverter(this.scale * other.scale, this.scale * other.offset + this.offset);
    }
    @Override
    public String toString() {
        return "AffineConverter(scale=" + scale + ", offset=" + offset + ")";
    }
}
// AffineConverter class to perform affine transformations (linear transformations with an offset)

import java.text.DecimalFormat;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.NoSuchElementException;
import java.util.Scanner;
import java.util.Set;

public final class Main {
    // Map to hold conversions between unit pairs and their corresponding converters
    private final Map<Pair<String, String>, AffineConverter> conversions;
    // Set to hold all unique units available for conversion
    private final Set<String> units;

    // Constructor that initializes conversions and units based on provided basic conversions
    public Main(final Map<Pair<String, String>, AffineConverter> basicConversions) {
        conversions = computeAllConversions(basicConversions);
        units = extractUnits(conversions);
    }

    // Method to convert a value from one unit to another
    public double convert(final String inputUnit, final String outputUnit, final double value) {
        // Check if input and output units are the same, which is not allowed
        if (inputUnit.equals(outputUnit)) {
            throw new IllegalArgumentException("Input and output units must be different.");
        }
        // Create a key for the conversion
        final var conversionKey = Pair.of(inputUnit, outputUnit);
        // Perform the conversion using the appropriate converter
        double result = conversions.computeIfAbsent(conversionKey, k -> {
            throw new NoSuchElementException("No converter for: " + k);
        }).convert(value);
        // Format the result to two decimal places
        DecimalFormat df = new DecimalFormat("#.##");
        return Double.parseDouble(df.format(result));
    }

    // Method to retrieve the set of available units for conversion
    public Set<String> availableUnits() {
        return units;
    }

    // Helper method to add a conversion to the map if input and output units are different
    private static void putIfNeeded(Map<Pair<String, String>, AffineConverter> conversions, String inputUnit, String outputUnit, AffineConverter converter) {
        if (!inputUnit.equals(outputUnit)) {
            conversions.putIfAbsent(Pair.of(inputUnit, outputUnit), converter);
        }
    }

    // Method to add inverses of known conversions to the conversion map
    private static Map<Pair<String, String>, AffineConverter> addInversions(Map<Pair<String, String>, AffineConverter> knownConversions) {
        Map<Pair<String, String>, AffineConverter> res = new HashMap<>();
        // Iterate through known conversions to add both directions
        for (var entry : knownConversions.entrySet()) {
            var inputUnit = entry.getKey().getKey();
            var outputUnit = entry.getKey().getValue();
            var converter = entry.getValue();
            putIfNeeded(res, inputUnit, outputUnit, converter);
            putIfNeeded(res, outputUnit, inputUnit, converter.invert());
        }
        return res;
    }

    // Method to add compositions of known conversions to the conversion map
    private static Map<Pair<String, String>, AffineConverter> addCompositions(Map<Pair<String, String>, AffineConverter> knownConversions) {
        Map<Pair<String, String>, AffineConverter> res = new HashMap<>();
        // Iterate through known conversions to find compositions
        for (var first : knownConversions.entrySet()) {
            var firstKey = first.getKey();
            putIfNeeded(res, firstKey.getKey(), firstKey.getValue(), first.getValue());
            for (var second : knownConversions.entrySet()) {
                var secondKey = second.getKey();
                // Check if the output unit of the first conversion matches the input unit of the second
                if (firstKey.getValue().equals(secondKey.getKey())) {
                    var composedConverter = second.getValue().compose(first.getValue());
                    putIfNeeded(res, firstKey.getKey(), secondKey.getValue(), composedConverter);
                }
            }
        }
        return res;
    }

    // Method to compute all conversions by adding inverses and compositions iteratively
    private static Map<Pair<String, String>, AffineConverter> computeAllConversions(Map<Pair<String, String>, AffineConverter> basicConversions) {
        var tmp = basicConversions;
        var res = addAll(tmp);
        // Continue adding conversions until no new conversions are found
        while (res.size() != tmp.size()) {
            tmp = res;
            res = addAll(tmp);
        }
        return res;
    }

    // Method to add all known conversions, including inverses and compositions
    private static Map<Pair<String, String>, AffineConverter> addAll(Map<Pair<String, String>, AffineConverter> knownConversions) {
        var res = addInversions(knownConversions);
        return addCompositions(res);
    }

    // Method to extract unique units from the conversion map
    private static Set<String> extractUnits(Map<Pair<String, String>, AffineConverter> conversions) {
        Set<String> res = new HashSet<>();
        // Add both input and output units to the set
        for (var entry : conversions.entrySet()) {
            res.add(entry.getKey().getKey());
            res.add(entry.getKey().getValue());
        }
        return res;
    }

    // Main method to run the conversion program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // Initialize basic conversions
        Map<Pair<String, String>, AffineConverter> basicConversions = new HashMap<>();
        basicConversions.put(Pair.of("Celsius", "Fahrenheit"), new AffineConverter(9.0 / 5.0, 32.0));
        basicConversions.put(Pair.of("Kelvin", "Celsius"), new AffineConverter(1.0, -273.15));
        // Create a converter instance with the basic conversions
        Main converter = new Main(basicConversions);
        // Read input unit, output unit, and value from the user
        String inputUnit = scanner.nextLine();
        String outputUnit = scanner.nextLine();
        double value = scanner.nextDouble();
        try {
            // Perform the conversion and display the result
            double result = converter.convert(inputUnit, outputUnit, value);
            System.out.println("Converted value: " + result);
        } catch (Exception e) {
            // Handle any exceptions that occur during conversion
            System.out.println("Error: " + e.getMessage());
        }
        // Close the scanner to free resources
        scanner.close();
    }
}

// Pair class to hold a key-value pair
class Pair<K, V> {
    private final K key;
    private final V value;

    // Constructor for Pair
    private Pair(K key, V value) {
        this.key = key;
        this.value = value;
    }

    // Static factory method to create a Pair
    public static <K, V> Pair<K, V> of(K key, V value) {
        return new Pair<>(key, value);
    }

    // Getter for the key
    public K getKey() {
        return key;
    }

    // Getter for the value
    public V getValue() {
        return value;
    }

    // Override equals method for proper comparison
    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Pair<?, ?> pair = (Pair<?, ?>) o;
        return key.equals(pair.key) && value.equals(pair.value);
    }

    // Override hashCode method for proper hashing
    @Override
    public int hashCode() {
        return key.hashCode() * 31 + value.hashCode();
    }

    // Override toString method for better representation
    @Override
    public String toString() {
        return "(" + key + ", " + value + ")";
    }
}

// AffineConverter class to handle unit conversions
class AffineConverter {
    private final double scale; // Scale factor for conversion
    private final double offset; // Offset for conversion

    // Constructor for AffineConverter
    public AffineConverter(double scale, double offset) {
        this.scale = scale;
        this.offset = offset;
    }

    // Method to convert a value using the scale and offset
    public double convert(double value) {
        return scale * value + offset;
    }

    // Method to invert the conversion
    public AffineConverter invert() {
        if (scale == 0) {
            throw new ArithmeticException("Cannot invert a scale of zero.");
        }
        return new AffineConverter(1 / scale, -offset / scale);
    }

    // Method to compose this converter with another
    public AffineConverter compose(AffineConverter other) {
        return new AffineConverter(this.scale * other.scale, this.scale * other.offset + this.offset);
    }

    // Override toString method for better representation
    @Override
    public String toString() {
        return "AffineConverter(scale=" + scale + ", offset=" + offset + ")";
    }
}

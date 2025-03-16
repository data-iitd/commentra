
import java.text.DecimalFormat;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.NoSuchElementException;
import java.util.Scanner;
import java.util.Set;

public final class Main {
    // Declare a private map to store conversions between different units
    private final Map<Pair<String, String>, AffineConverter> conversions;

    // Declare a private set to store unique units
    private final Set<String> units;

    // Constructor initializes the map of conversions and set of unique units
    public Main(final Map<Pair<String, String>, AffineConverter> basicConversions) {
        conversions = computeAllConversions(basicConversions); // Initialize conversions using all conversions from basicConversions
        units = extractUnits(conversions); // Initialize unique units from conversions
    }

    // Method to convert a value from one unit to another
    public double convert(final String inputUnit, final String outputUnit, final double value) {
        if (inputUnit.equals(outputUnit)) {
            throw new IllegalArgumentException("Input and output units must be different.");
        }

        // Look up the conversion from inputUnit to outputUnit in the conversions map
        final var conversionKey = Pair.of(inputUnit, outputUnit);
        AffineConverter converter = conversions.get(conversionKey);

        if (converter == null) {
            throw new NoSuchElementException("No converter for: " + conversionKey);
        }

        double result = converter.convert(value);
        DecimalFormat df = new DecimalFormat("#.##");
        return Double.parseDouble(df.format(result));
    }

    // Method to return the set of available units
    public Set<String> availableUnits() {
        return units;
    }

    // Helper method to put conversions into the conversions map if they don't already exist
    private static void putIfNeeded(Map<Pair<String, String>, AffineConverter> conversions, String inputUnit, String outputUnit, AffineConverter converter) {
        if (!inputUnit.equals(outputUnit)) {
            conversions.putIfAbsent(Pair.of(inputUnit, outputUnit), converter);
        }
    }

    // Helper method to add inversions of conversions to the conversions map
    private static Map<Pair<String, String>, AffineConverter> addInversions(Map<Pair<String, String>, AffineConverter> knownConversions) {
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

    // Helper method to add compositions of conversions to the conversions map
    private static Map<Pair<String, String>, AffineConverter> addCompositions(Map<Pair<String, String>, AffineConverter> knownConversions) {
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

    // Helper method to compute all conversions from the given basic conversions
    private static Map<Pair<String, String>, AffineConverter> computeAllConversions(Map<Pair<String, String>, AffineConverter> basicConversions) {
        var tmp = basicConversions;
        Map<Pair<String, String>, AffineConverter> res = addAll(tmp);
        while (res.size() != tmp.size()) {
            tmp = res;
            res = addAll(tmp);
        }
        return res;
    }

    // Helper method to add all conversions, inversions, and compositions to the conversions map
    private static Map<Pair<String, String>, AffineConverter> addAll(Map<Pair<String, String>, AffineConverter> knownConversions) {
        Map<Pair<String, String>, AffineConverter> res = addInversions(knownConversions);
        return addCompositions(res);
    }

    // Helper method to extract unique units from the conversions map
    private static Set<String> extractUnits(Map<Pair<String, String>, AffineConverter> conversions) {
        Set<String> res = new HashSet<>();
        for (var entry : conversions.entrySet()) {
            res.add(entry.getKey().getKey());
            res.add(entry.getKey().getValue());
        }
        return res;
    }

    // Main method to read user input and perform unit conversions
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Initialize a map of basic conversions
        Map<Pair<String, String>, AffineConverter> basicConversions = new HashMap<>();
        basicConversions.put(Pair.of("Celsius", "Fahrenheit"), new AffineConverter(9.0 / 5.0, 32.0));
        basicConversions.put(Pair.of("Kelvin", "Celsius"), new AffineConverter(1.0, -273.15));

        // Create an instance of Main with the basic conversions
        Main converter = new Main(basicConversions);

        // Read user input for inputUnit, outputUnit, and value
        String inputUnit = scanner.nextLine();
        String outputUnit = scanner.nextLine();
        double value = scanner.nextDouble();

        try {
            // Perform the unit conversion and print the result
            double result = converter.convert(inputUnit, outputUnit, value);
            System.out.println("Converted value: " + result);
        } catch (Exception e) {
            // Print an error message if an exception occurs
            System.out.println("Error: " + e.getMessage());
        }

        // Close the scanner
        scanner.close();
    }
}


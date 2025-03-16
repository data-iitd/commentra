import java.text.DecimalFormat;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.NoSuchElementException;
import java.util.Scanner;
import java.util.Set;
public final class Main {
    private final Map<Pair<String, String>, AffineConverter> conversions;
    private final Set<String> units;
    public Main(final Map<Pair<String, String>, AffineConverter> basicConversions) {
        conversions = computeAllConversions(basicConversions);
        units = extractUnits(conversions);
    }
    public double convert(final String inputUnit, final String outputUnit, final double value) {
        if (inputUnit.equals(outputUnit)) {
            raise ValueError("Input and output units must be different.")
        }
        final var conversionKey = Pair.of(inputUnit, outputUnit);
        double result = conversions.computeIfAbsent(conversionKey, k -> {
            raise ValueError("No converter for: " + k);
        }).convert(value);
        DecimalFormat df = new DecimalFormat("#.##");
        return Double.parseDouble(df.format(result));
    }
    public Set<String> availableUnits() {
        return units;
    }
    private static void putIfNeeded(Map<Pair<String, String>, AffineConverter> conversions, String inputUnit, String outputUnit, AffineConverter converter) {
        if (!inputUnit.equals(outputUnit)) {
            conversions.putIfAbsent(Pair.of(inputUnit, outputUnit), converter);
        }
    }
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
    private static Map<Pair<String, String>, AffineConverter> computeAllConversions(Map<Pair<String, String>, AffineConverter> basicConversions) {
        var tmp = basicConversions;
        var res = addAll(tmp);
        while (res.size()!= tmp.size()) {
            tmp = res;
            res = addAll(tmp);
        }
        return res;
    }
    private static Map<Pair<String, String>, AffineConverter> addAll(Map<Pair<String, String>, AffineConverter> knownConversions) {
        var res = addInversions(knownConversions);
        return addCompositions(res);
    }
    private static Set<String> extractUnits(Map<Pair<String, String>, AffineConverter> conversions) {
        Set<String> res = new HashSet<>();
        for (var entry : conversions.entrySet()) {
            res.add(entry.getKey().getKey());
            res.add(entry.getKey().getValue());
        }
        return res;
    }
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
}
class Pair<K, V> {
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
        if (o == null || getClass()!= o.getClass()) return false;
        Pair<?,?> pair = (Pair<?,?>) o;
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
class AffineConverter {
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
            raise ArithmeticError("Cannot invert a scale of zero.");
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


import java.util.Random;
import java.util.Scanner;

public final class Main {
    // Private constructor to prevent instantiation
    private Main() {
    }

    // Method to generate Perlin noise based on given parameters
    static float[][] generateMain(int width, int height, int octaveCount, float persistence, long seed) {
        // Create arrays to hold base noise, final Perlin noise, and noise layers for each octave
        final float[][] base = new float[width][height];
        final float[][] perlinNoise = new float[width][height];
        final float[][][] noiseLayers = new float[octaveCount][][];

        // Initialize random number generator with the provided seed
        Random random = new Random(seed);

        // Generate base noise values
        for (int x = 0; x < width; x++) {
            for (int y = 0; y < height; y++) {
                base[x][y] = random.nextFloat(); // Fill base array with random floats
            }
        }

        // Generate noise layers for each octave
        for (int octave = 0; octave < octaveCount; octave++) {
            noiseLayers[octave] = generateMainLayer(base, width, height, octave);
        }

        // Initialize amplitude and total amplitude for combining noise layers
        float amplitude = 1f;
        float totalAmplitude = 0f;

        // Combine noise layers using persistence and amplitude
        for (int octave = octaveCount - 1; octave >= 0; octave--) {
            amplitude *= persistence; // Decrease amplitude based on persistence
            totalAmplitude += amplitude; // Accumulate total amplitude
            for (int x = 0; x < width; x++) {
                for (int y = 0; y < height; y++) {
                    perlinNoise[x][y] += noiseLayers[octave][x][y] * amplitude; // Combine noise layers
                }
            }
        }

        // Normalize the final Perlin noise values
        for (int x = 0; x < width; x++) {
            for (int y = 0; y < height; y++) {
                perlinNoise[x][y] /= totalAmplitude; // Normalize by total amplitude
            }
        }
        return perlinNoise; // Return the generated Perlin noise
    }

    // Method to generate a single layer of Perlin noise for a specific octave
    static float[][] generateMainLayer(float[][] base, int width, int height, int octave) {
        float[][] perlinNoiseLayer = new float[width][height];
        int period = 1 << octave; // Calculate period based on octave
        float frequency = 1f / period; // Calculate frequency based on period

        // Generate noise values for the current octave
        for (int x = 0; x < width; x++) {
            int x0 = (x / period) * period; // Find the left coordinate
            int x1 = (x0 + period) % width; // Find the right coordinate
            float horizintalBlend = (x - x0) * frequency; // Calculate horizontal blend factor

            for (int y = 0; y < height; y++) {
                int y0 = (y / period) * period; // Find the top coordinate
                int y1 = (y0 + period) % height; // Find the bottom coordinate
                float verticalBlend = (y - y0) * frequency; // Calculate vertical blend factor

                // Interpolate between the corners of the grid cell
                float top = interpolate(base[x0][y0], base[x1][y0], horizintalBlend);
                float bottom = interpolate(base[x0][y1], base[x1][y1], horizintalBlend);
                perlinNoiseLayer[x][y] = interpolate(top, bottom, verticalBlend); // Final interpolation
            }
        }
        return perlinNoiseLayer; // Return the generated noise layer
    }

    // Method to perform linear interpolation between two values
    static float interpolate(float a, float b, float alpha) {
        return a * (1 - alpha) + alpha * b; // Linear interpolation formula
    }

    // Main method to execute the program
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in); // Create a scanner for user input
        final int width; // Width of the noise
        final int height; // Height of the noise
        final int octaveCount; // Number of octaves for noise generation
        final float persistence; // Persistence factor for amplitude
        final long seed; // Seed for random number generation
        final String charset; // Character set for output representation
        final float[][] perlinNoise; // Array to hold the generated Perlin noise

        // Read user input for noise parameters
        width = in.nextInt();
        height = in.nextInt();
        octaveCount = in.nextInt();
        persistence = in.nextFloat();
        seed = in.nextLong();
        charset = in.next();

        // Generate Perlin noise based on user input
        perlinNoise = generateMain(width, height, octaveCount, persistence, seed);

        // Convert character set to array and calculate step size for mapping noise values
        final char[] chars = charset.toCharArray();
        final int length = chars.length;
        final float step = 1f / length;

        // Output the generated Perlin noise as characters
        for (int x = 0; x < width; x++) {
            for (int y = 0; y < height; y++) {
                float value = step; // Initialize value for character mapping
                float noiseValue = perlinNoise[x][y]; // Get the noise value for the current position
                for (char c : chars) {
                    if (noiseValue <= value) { // Check if noise value falls within the current range
                        System.out.print(c); // Print the corresponding character
                        break; // Exit the loop once a character is printed
                    }
                    value += step; // Move to the next range
                }
            }
            System.out.println(); // Move to the next line after finishing a row
        }
        in.close(); // Close the scanner to free resources
    }
}

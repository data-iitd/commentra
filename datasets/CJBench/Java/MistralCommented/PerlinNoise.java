
import java.util.Random;
import java.util.Scanner;

public final class Main {
    private Main() {
        // Private constructor to prevent instantiation of the class from outside
    }

    static float[][] generateMain(int width, int height, int octaveCount, float persistence, long seed) {
        // Generate Perlin noise of given dimensions, octave count, persistence, and seed
        final float[][] base = new float[width][height]; // Initialize base array for random values
        final float[][] perlinNoise = new float[width][height]; // Initialize output array for Perlin noise values
        final float[][][] noiseLayers = new float[octaveCount][][]; // Initialize array for noise layers

        Random random = new Random(seed); // Initialize random number generator with given seed

        // Initialize base array with random values
        for (int x = 0; x < width; x++) {
            for (int y = 0; y < height; y++) {
                base[x][y] = random.nextFloat();
            }
        }

        // Generate each noise layer recursively
        for (int octave = 0; octave < octaveCount; octave++) {
            noiseLayers[octave] = generateMainLayer(base, width, height, octave);
        }

        // Calculate final Perlin noise values by summing up all noise layers with decreasing amplitudes
        float amplitude = 1f;
        float totalAmplitude = 0f;
        for (int octave = octaveCount - 1; octave >= 0; octave--) {
            amplitude *= persistence;
            totalAmplitude += amplitude;
            for (int x = 0; x < width; x++) {
                for (int y = 0; y < height; y++) {
                    perlinNoise[x][y] += noiseLayers[octave][x][y] * amplitude;
                }
            }
        }

        // Normalize Perlin noise values to the range [0, 1]
        for (int x = 0; x < width; x++) {
            for (int y = 0; y < height; y++) {
                perlinNoise[x][y] /= totalAmplitude;
            }
        }

        return perlinNoise;
    }

    static float[][] generateMainLayer(float[][] base, int width, int height, int octave) {
        // Generate a single noise layer using given base array, dimensions, and octave number
        float[][] perlinNoiseLayer = new float[width][height]; // Initialize output array for noise layer
        int period = 1 << octave; // Calculate period for given octave number
        float frequency = 1f / period; // Calculate frequency for given period

        // Generate noise layer by interpolating between neighboring base values using given period and frequency
        for (int x = 0; x < width; x++) {
            int x0 = (x / period) * period; // Calculate index of starting point for given x position
            int x1 = (x0 + period) % width; // Calculate index of ending point for given x position
            float horizintalBlend = (x - x0) * frequency; // Calculate horizontal blending factor for given x position

            for (int y = 0; y < height; y++) {
                int y0 = (y / period) * period; // Calculate index of starting point for given y position
                int y1 = (y0 + period) % height; // Calculate index of ending point for given y position
                float verticalBlend = (y - y0) * frequency; // Calculate vertical blending factor for given y position

                float top = interpolate(base[x0][y0], base[x1][y0], horizintalBlend); // Interpolate between base values horizontally
                float bottom = interpolate(base[x0][y1], base[x1][y1], horizintalBlend); // Interpolate between base values horizontally
                perlinNoiseLayer[x][y] = interpolate(top, bottom, verticalBlend); // Interpolate between interpolated values vertically
            }
        }

        return perlinNoiseLayer;
    }

    static float interpolate(float a, float b, float alpha) {
        // Interpolate between two given values using given interpolation factor
        return a * (1 - alpha) + alpha * b;
    }

    public static void main(String[] args) {
        // Read input parameters from standard input
        Scanner in = new Scanner(System.in);
        final int width;
        final int height;
        final int octaveCount;
        final float persistence;
        final long seed;
        final String charset;
        width = in.nextInt();
        height = in.nextInt();
        octaveCount = in.nextInt();
        persistence = in.nextFloat();
        seed = in.nextLong();
        charset = in.next();

        // Generate Perlin noise using given input parameters
        float[][] perlinNoise = generateMain(width, height, octaveCount, persistence, seed);

        // Generate output based on Perlin noise values and given character set
        char[] chars = charset.toCharArray();
        final int length = chars.length;
        final float step = 1f / length;
        for (int x = 0; x < width; x++) {
            for (int y = 0; y < height; y++) {
                float value = step;
                float noiseValue = perlinNoise[x][y];
                for (char c : chars) {
                    if (noiseValue <= value) {
                        System.out.print(c);
                        break;
                    }
                    value += step;
                }
            }
            System.out.println();
        }

        // Close standard input stream
        in.close();
    }
}
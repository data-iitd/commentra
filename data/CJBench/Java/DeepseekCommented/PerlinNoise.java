
import java.util.Random;
import java.util.Scanner;
public final class Main {
    private Main() {
    }

    // Generates the main Perlin noise map
    static float[][] generateMain(int width, int height, int octaveCount, float persistence, long seed) {
        final float[][] base = new float[width][height];
        final float[][] perlinNoise = new float[width][height];
        final float[][][] noiseLayers = new float[octaveCount][][];
        Random random = new Random(seed);
        // Populate the base noise map with random values
        for (int x = 0; x < width; x++) {
            for (int y = 0; y < height; y++) {
                base[x][y] = random.nextFloat();
            }
        }
        // Generate each noise layer
        for (int octave = 0; octave < octaveCount; octave++) {
            noiseLayers[octave] = generateMainLayer(base, width, height, octave);
        }
        float amplitude = 1f;
        float totalAmplitude = 0f;
        // Combine the noise layers with persistence
        for (int octave = octaveCount - 1; octave >= 0; octave--) {
            amplitude *= persistence;
            totalAmplitude += amplitude;
            for (int x = 0; x < width; x++) {
                for (int y = 0; y < height; y++) {
                    perlinNoise[x][y] += noiseLayers[octave][x][y] * amplitude;
                }
            }
        }
        // Normalize the Perlin noise
        for (int x = 0; x < width; x++) {
            for (int y = 0; y < height; y++) {
                perlinNoise[x][y] /= totalAmplitude;
            }
        }
        return perlinNoise;
    }

    // Generates a single layer of Perlin noise
    static float[][] generateMainLayer(float[][] base, int width, int height, int octave) {
        float[][] perlinNoiseLayer = new float[width][height];
        int period = 1 << octave; 
        float frequency = 1f / period; 
        // Interpolate between base values to generate the layer
        for (int x = 0; x < width; x++) {
            int x0 = (x / period) * period;
            int x1 = (x0 + period) % width;
            float horizintalBlend = (x - x0) * frequency;
            for (int y = 0; y < height; y++) {
                int y0 = (y / period) * period;
                int y1 = (y0 + period) % height;
                float verticalBlend = (y - y0) * frequency;
                float top = interpolate(base[x0][y0], base[x1][y0], horizintalBlend);
                float bottom = interpolate(base[x0][y1], base[x1][y1], horizintalBlend);
                perlinNoiseLayer[x][y] = interpolate(top, bottom, verticalBlend);
            }
        }
        return perlinNoiseLayer;
    }

    // Interpolates between two values using a smooth step
    static float interpolate(float a, float b, float alpha) {
        return a * (1 - alpha) + alpha * b;
    }

    // Main method to take user input and generate/print Perlin noise
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        final int width;
        final int height;
        final int octaveCount;
        final float persistence;
        final long seed;
        final String charset;
        final float[][] perlinNoise;
        width = in.nextInt();
        height = in.nextInt();
        octaveCount = in.nextInt();
        persistence = in.nextFloat();
        seed = in.nextLong();
        charset = in.next();
        perlinNoise = generateMain(width, height, octaveCount, persistence, seed);
        final char[] chars = charset.toCharArray();
        final int length = chars.length;
        final float step = 1f / length;
        // Map the Perlin noise values to characters
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
        in.close();
    }
}
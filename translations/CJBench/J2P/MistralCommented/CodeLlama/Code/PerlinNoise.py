
import random
import sys

def generate_main(width, height, octave_count, persistence, seed):
    # Generate Perlin noise of given dimensions, octave count, persistence, and seed
    base = [[random.random() for _ in range(height)] for _ in range(width)] # Initialize base array for random values
    perlin_noise = [[0 for _ in range(height)] for _ in range(width)] # Initialize output array for Perlin noise values
    noise_layers = [generate_main_layer(base, width, height, octave) for octave in range(octave_count)] # Initialize array for noise layers

    random.seed(seed) # Initialize random number generator with given seed

    # Initialize base array with random values
    for x in range(width):
        for y in range(height):
            base[x][y] = random.random()

    # Generate each noise layer recursively
    for octave in range(octave_count):
        noise_layers[octave] = generate_main_layer(base, width, height, octave)

    # Calculate final Perlin noise values by summing up all noise layers with decreasing amplitudes
    amplitude = 1
    total_amplitude = 0
    for octave in range(octave_count - 1, -1, -1):
        amplitude *= persistence
        total_amplitude += amplitude
        for x in range(width):
            for y in range(height):
                perlin_noise[x][y] += noise_layers[octave][x][y] * amplitude

    # Normalize Perlin noise values to the range [0, 1]
    for x in range(width):
        for y in range(height):
            perlin_noise[x][y] /= total_amplitude

    return perlin_noise

def generate_main_layer(base, width, height, octave):
    # Generate a single noise layer using given base array, dimensions, and octave number
    perlin_noise_layer = [[0 for _ in range(height)] for _ in range(width)] # Initialize output array for noise layer
    period = 1 << octave # Calculate period for given octave number
    frequency = 1 / period # Calculate frequency for given period

    # Generate noise layer by interpolating between neighboring base values using given period and frequency
    for x in range(width):
        x0 = (x // period) * period # Calculate index of starting point for given x position
        x1 = (x0 + period) % width # Calculate index of ending point for given x position
        horizontal_blend = (x - x0) * frequency # Calculate horizontal blending factor for given x position

        for y in range(height):
            y0 = (y // period) * period # Calculate index of starting point for given y position
            y1 = (y0 + period) % height # Calculate index of ending point for given y position
            vertical_blend = (y - y0) * frequency # Calculate vertical blending factor for given y position

            top = interpolate(base[x0][y0], base[x1][y0], horizontal_blend) # Interpolate between base values horizontally
            bottom = interpolate(base[x0][y1], base[x1][y1], horizontal_blend) # Interpolate between base values horizontally
            perlin_noise_layer[x][y] = interpolate(top, bottom, vertical_blend) # Interpolate between interpolated values vertically

    return perlin_noise_layer

def interpolate(a, b, alpha):
    # Interpolate between two given values using given interpolation factor
    return a * (1 - alpha) + alpha * b

if __name__ == "__main__":
    # Read input parameters from standard input
    width, height, octave_count, persistence, seed = map(int, sys.stdin.readline().split())
    charset = sys.stdin.readline().strip()

    # Generate Perlin noise using given input parameters
    perlin_noise = generate_main(width, height, octave_count, persistence, seed)

    # Generate output based on Perlin noise values and given character set
    chars = list(charset)
    length = len(chars)
    step = 1 / length
    for x in range(width):
        for y in range(height):
            value = step
            noise_value = perlin_noise[x][y]
            for c in chars:
                if noise_value <= value:
                    print(c, end="")
                    break
                value += step
            print(" ", end="")
        print()

    # End of code
    print("
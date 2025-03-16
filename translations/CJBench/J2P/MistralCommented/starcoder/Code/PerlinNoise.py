
import random
import sys

def generate_main(width, height, octave_count, persistence, seed):
    # Generate Perlin noise of given dimensions, octave count, persistence, and seed
    base = [[random.random() for y in range(height)] for x in range(width)] # Initialize base array for random values
    perlin_noise = [[0.0 for y in range(height)] for x in range(width)] # Initialize output array for Perlin noise values
    noise_layers = [[[0.0 for y in range(height)] for x in range(width)] for octave in range(octave_count)] # Initialize array for noise layers

    random.seed(seed) # Initialize random number generator with given seed

    # Generate each noise layer recursively
    for octave in range(octave_count):
        noise_layers[octave] = generate_main_layer(base, width, height, octave)

    # Calculate final Perlin noise values by summing up all noise layers with decreasing amplitudes
    amplitude = 1.0
    total_amplitude = 0.0
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
    perlin_noise_layer = [[0.0 for y in range(height)] for x in range(width)] # Initialize output array for noise layer
    period = 1 << octave # Calculate period for given octave number
    frequency = 1.0 / period # Calculate frequency for given period

    # Generate noise layer by interpolating between neighboring base values using given period and frequency
    for x in range(width):
        x0 = (x / period) * period # Calculate index of starting point for given x position
        x1 = (x0 + period) % width # Calculate index of ending point for given x position
        horizintal_blend = (x - x0) * frequency # Calculate horizontal blending factor for given x position

        for y in range(height):
            y0 = (y / period) * period # Calculate index of starting point for given y position
            y1 = (y0 + period) % height # Calculate index of ending point for given y position
            vertical_blend = (y - y0) * frequency # Calculate vertical blending factor for given y position

            top = interpolate(base[x0][y0], base[x1][y0], horizintal_blend) # Interpolate between base values horizontally
            bottom = interpolate(base[x0][y1], base[x1][y1], horizintal_blend) # Interpolate between base values horizontally
            perlin_noise_layer[x][y] = interpolate(top, bottom, vertical_blend) # Interpolate between interpolated values vertically

    return perlin_noise_layer

def interpolate(a, b, alpha):
    # Interpolate between two given values using given interpolation factor
    return a * (1 - alpha) + alpha * b

if __name__ == '__main__':
    # Read input parameters from standard input
    width = int(input())
    height = int(input())
    octave_count = int(input())
    persistence = float(input())
    seed = int(input())
    charset = input()

    # Generate Perlin noise using given input parameters
    perlin_noise = generate_main(width, height, octave_count, persistence, seed)

    # Generate output based on Perlin noise values and given character set
    chars = list(charset)
    length = len(chars)
    step = 1.0 / length
    for x in range(width):
        for y in range(height):
            value = step
            noise_value = perlin_noise[x][y]
            for c in chars:
                if noise_value <= value:
                    sys.stdout.write(c)
                    break
                value += step
        sys.stdout.write('\n')


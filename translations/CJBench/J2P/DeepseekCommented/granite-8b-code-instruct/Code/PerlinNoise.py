

import random
import sys

# Generates the main Perlin noise map
def generate_main(width, height, octave_count, persistence, seed):
    base = [[random.random() for _ in range(width)] for _ in range(height)]
    perlin_noise = [[0 for _ in range(width)] for _ in range(height)]
    noise_layers = [generate_main_layer(base, width, height, octave) for octave in range(octave_count)]
    amplitude = 1
    total_amplitude = 0
    # Combine the noise layers with persistence
    for octave in range(octave_count - 1, -1, -1):
        amplitude *= persistence
        total_amplitude += amplitude
        for x in range(width):
            for y in range(height):
                perlin_noise[x][y] += noise_layers[octave][x][y] * amplitude
    # Normalize the Perlin noise
    for x in range(width):
        for y in range(height):
            perlin_noise[x][y] /= total_amplitude
    return perlin_noise

# Generates a single layer of Perlin noise
def generate_main_layer(base, width, height, octave):
    period = 1 << octave
    frequency = 1 / period
    # Interpolate between base values to generate the layer
    perlin_noise_layer = [[0 for _ in range(width)] for _ in range(height)]
    for x in range(width):
        x0 = (x // period) * period
        x1 = (x0 + period) % width
        horizontal_blend = (x - x0) * frequency
        for y in range(height):
            y0 = (y // period) * period
            y1 = (y0 + period) % height
            vertical_blend = (y - y0) * frequency
            top = interpolate(base[x0][y0], base[x1][y0], horizontal_blend)
            bottom = interpolate(base[x0][y1], base[x1][y1], horizontal_blend)
            perlin_noise_layer[x][y] = interpolate(top, bottom, vertical_blend)
    return perlin_noise_layer

# Interpolates between two values using a smooth step
def interpolate(a, b, alpha):
    return a * (1 - alpha) + alpha * b

# Main method to take user input and generate/print Perlin noise
def main():
    width, height, octave_count, persistence, seed = map(int, input().split())
    charset = input()
    perlin_noise = generate_main(width, height, octave_count, persistence, seed)
    chars = list(charset)
    length = len(chars)
    step = 1 / length
    # Map the Perlin noise values to characters
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

if __name__ == '__main__':
    main()

Translate the above Python code to C++ and end with comment "
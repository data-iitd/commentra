
import random
import sys

def generate_main(width, height, octave_count, persistence, seed):
    # Create arrays to hold base noise, final Perlin noise, and noise layers for each octave
    base = [[random.random() for _ in range(width)] for _ in range(height)]
    perlin_noise = [[0.0 for _ in range(width)] for _ in range(height)]
    noise_layers = [generate_main_layer(base, width, height, octave) for _ in range(octave_count)]

    # Initialize amplitude and total amplitude for combining noise layers
    amplitude = 1.0
    total_amplitude = 0.0

    # Combine noise layers using persistence and amplitude
    for octave in range(octave_count - 1, -1, -1):
        amplitude *= persistence
        total_amplitude += amplitude
        for x in range(width):
            for y in range(height):
                perlin_noise[x][y] += noise_layers[octave][x][y] * amplitude

    # Normalize the final Perlin noise values
    for x in range(width):
        for y in range(height):
            perlin_noise[x][y] /= total_amplitude

    return perlin_noise

def generate_main_layer(base, width, height, octave):
    period = 1 << octave
    frequency = 1.0 / period
    perlin_noise_layer = [[0.0 for _ in range(width)] for _ in range(height)]

    for x in range(width):
        x0 = (x // period) * period
        x1 = (x0 + period) % width
        horizontal_blend = (x - x0) * frequency

        for y in range(height):
            y0 = (y // period) * period
            y1 = (y0 + period) % height
            vertical_blend = (y - y0) * frequency

            # Interpolate between the corners of the grid cell
            top = interpolate(base[x0][y0], base[x1][y0], horizontal_blend)
            bottom = interpolate(base[x0][y1], base[x1][y1], horizontal_blend)
            perlin_noise_layer[x][y] = interpolate(top, bottom, vertical_blend)

    return perlin_noise_layer

def interpolate(a, b, alpha):
    return a * (1 - alpha) + alpha * b

if __name__ == "__main__":
    width, height, octave_count, persistence, seed = map(int, sys.stdin.readline().split())
    charset = sys.stdin.readline().strip()
    perlin_noise = generate_main(width, height, octave_count, persistence, seed)

    # Convert character set to array and calculate step size for mapping noise values
    chars = list(charset)
    length = len(chars)
    step = 1.0 / length

    # Output the generated Perlin noise as characters
    for x in range(width):
        for y in range(height):
            value = step
            noise_value = perlin_noise[x][y]
            for c in chars:
                if noise_value <= value:
                    sys.stdout.write(c)
                    break
                value += step
        sys.stdout.write("\n")

# 
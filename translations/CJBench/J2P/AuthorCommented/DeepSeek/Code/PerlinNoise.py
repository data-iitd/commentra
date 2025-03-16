import random
import sys

def generate_main(width, height, octave_count, persistence, seed):
    base = [[0.0 for _ in range(height)] for _ in range(width)]
    perlin_noise = [[0.0 for _ in range(height)] for _ in range(width)]
    noise_layers = [None] * octave_count

    random.seed(seed)
    # fill base array with random values as base for noise
    for x in range(width):
        for y in range(height):
            base[x][y] = random.random()

    # calculate octaves with different roughness
    for octave in range(octave_count):
        noise_layers[octave] = generate_main_layer(base, width, height, octave)

    amplitude = 1.0
    total_amplitude = 0.0

    # calculate perlin noise by blending each layer together with specific persistence
    for octave in range(octave_count - 1, -1, -1):
        amplitude *= persistence
        total_amplitude += amplitude

        for x in range(width):
            for y in range(height):
                # adding each value of the noise layer to the noise
                # by increasing amplitude the rougher noises will have more impact
                perlin_noise[x][y] += noise_layers[octave][x][y] * amplitude

    # normalize values so that they stay between 0..1
    for x in range(width):
        for y in range(height):
            perlin_noise[x][y] /= total_amplitude

    return perlin_noise

def generate_main_layer(base, width, height, octave):
    perlin_noise_layer = [[0.0 for _ in range(height)] for _ in range(width)]

    # calculate period (wavelength) for different shapes
    period = 1 << octave  # 2^k
    frequency = 1.0 / period  # 1/2^k

    for x in range(width):
        # calculates the horizontal sampling indices
        x0 = (x // period) * period
        x1 = (x0 + period) % width
        horizontal_blend = (x - x0) * frequency

        for y in range(height):
            # calculates the vertical sampling indices
            y0 = (y // period) * period
            y1 = (y0 + period) % height
            vertical_blend = (y - y0) * frequency

            # blend top corners
            top = interpolate(base[x0][y0], base[x1][y0], horizontal_blend)

            # blend bottom corners
            bottom = interpolate(base[x0][y1], base[x1][y1], horizontal_blend)

            # blend top and bottom interpolation to get the final blend value for this cell
            perlin_noise_layer[x][y] = interpolate(top, bottom, vertical_blend)

    return perlin_noise_layer

def interpolate(a, b, alpha):
    return a * (1 - alpha) + alpha * b

def main():
    width = int(sys.stdin.readline().strip())
    height = int(sys.stdin.readline().strip())
    octave_count = int(sys.stdin.readline().strip())
    persistence = float(sys.stdin.readline().strip())
    seed = int(sys.stdin.readline().strip())
    charset = sys.stdin.readline().strip()

    perlin_noise = generate_main(width, height, octave_count, persistence, seed)
    chars = list(charset)
    length = len(chars)
    step = 1.0 / length
    # output based on charset
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

if __name__ == "__main__":
    main()

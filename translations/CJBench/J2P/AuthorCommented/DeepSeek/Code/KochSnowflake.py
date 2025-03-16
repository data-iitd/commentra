import java.awt.BasicStroke
import java.awt.Color
import java.awt.Graphics2D
import java.awt.image.BufferedImage
import java.io.File
import java.io.IOException
import java.util.ArrayList
import java.util.List
import java.util.Scanner
import javax.imageio.ImageIO

class Vector2:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __str__(self):
        return f"[{self.x}, {self.y}]"

    def add(self, vector):
        return Vector2(self.x + vector.x, self.y + vector.y)

    def subtract(self, vector):
        return Vector2(self.x - vector.x, self.y - vector.y)

    def multiply(self, scalar):
        return Vector2(self.x * scalar, self.y * scalar)

    def rotate(self, angle_in_degrees):
        radians = angle_in_degrees * math.pi / 180
        ca = math.cos(radians)
        sa = math.sin(radians)
        x = ca * self.x - sa * self.y
        y = sa * self.x + ca * self.y
        return Vector2(x, y)

def iterate(initial_vectors, steps):
    vectors = initial_vectors
    for _ in range(steps):
        vectors = iteration_step(vectors)
    return vectors

def iteration_step(vectors):
    new_vectors = []
    for i in range(len(vectors) - 1):
        start_vector = vectors[i]
        end_vector = vectors[i + 1]
        new_vectors.append(start_vector)
        difference_vector = end_vector.subtract(start_vector).multiply(1.0 / 3)
        new_vectors.append(start_vector.add(difference_vector))
        new_vectors.append(start_vector.add(difference_vector).add(difference_vector.rotate(60)))
        new_vectors.append(start_vector.add(difference_vector.multiply(2)))
    new_vectors.append(vectors[-1])
    return new_vectors

def get_main(image_width, steps):
    if image_width <= 0:
        raise ValueError("imageWidth should be greater than zero")

    offset_x = image_width / 10.0
    offset_y = image_width / 3.7
    vector1 = Vector2(offset_x, offset_y)
    vector2 = Vector2(image_width / 2.0, math.sin(math.pi / 3.0) * image_width * 0.8 + offset_y)
    vector3 = Vector2(image_width - offset_x, offset_y)
    initial_vectors = [vector1, vector2, vector3, vector1]
    vectors = iterate(initial_vectors, steps)
    return get_image(vectors, image_width, image_width)

def get_image(vectors, image_width, image_height):
    image = BufferedImage(image_width, image_height, BufferedImage.TYPE_INT_RGB)
    g2d = image.createGraphics()

    g2d.setColor(Color.WHITE)
    g2d.fillRect(0, 0, image_width, image_height)

    g2d.setColor(Color.BLACK)
    bs = BasicStroke(1)
    g2d.setStroke(bs)
    for i in range(len(vectors) - 1):
        x1 = int(vectors[i].x)
        y1 = int(vectors[i].y)
        x2 = int(vectors[i + 1].x)
        y2 = int(vectors[i + 1].y)
        g2d.drawLine(x1, y1, x2, y2)

    return image

def main():
    scanner = Scanner(System.in)

    image_width = scanner.nextInt()
    steps = scanner.nextInt()

    image = get_main(image_width, steps)

    file_path = scanner.next()

    try:
        ImageIO.write(image, "png", File(file_path))
        print(f"Koch snowflake saved to {file_path}")
    except IOException as e:
        print(f"Failed to save the image: {e}")

    scanner.close()

if __name__ == "__main__":
    main()


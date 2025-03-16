
import sys

class Main:
    def __init__(self):
        pass

    def convertBase(self, sourceNumber, sourceBase, destBase):
        if sourceBase < 2 or sourceBase > 10 or destBase < 2 or destBase > 10:
            raise Exception("Bases must be between 2 and 10.")

        decimalValue = self.toDecimal(sourceNumber, sourceBase)
        return self.fromDecimal(decimalValue, destBase)

    def toDecimal(self, number, base):
        decimalValue = 0
        multiplier = 1

        while number!= 0:
            decimalValue += (number % 10) * multiplier
            multiplier *= base
            number /= 10

        return decimalValue

    def fromDecimal(self, decimal, base):
        result = 0
        multiplier = 1

        while decimal!= 0:
            result += (decimal % base) * multiplier
            multiplier *= 10
            decimal /= base

        return result

    def main(self):
        sourceNumber = int(raw_input().strip())
        sourceBase = int(raw_input().strip())
        destBase = int(raw_input().strip())

        try:
            result = self.convertBase(sourceNumber, sourceBase, destBase)
            print "Converted number: " + str(result)
        except Exception as e:
            print "Error: " + e.message

if __name__ == "__main__":
    Main().main()


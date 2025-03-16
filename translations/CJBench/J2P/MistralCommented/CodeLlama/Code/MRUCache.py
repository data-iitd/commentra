
class Entry:
    def __init__(self, pre_entry, next_entry, key, value):
        self.pre_entry = pre_entry
        self.next_entry = next_entry
        self.key = key
        self.value = value

    def get_pre_entry(self):
        return self.pre_entry

    def set_pre_entry(self, pre_entry):
        self.pre_entry = pre_entry

    def get_next_entry(self):
        return self.next_entry

    def set_next_entry(self, next_entry):
        self.next_entry = next_entry

    def get_key(self):
        return self.key

    def get_value(self):
        return self.value

    def set_value(self, value):
        self.value = value


class Main:
    def __init__(self, capacity):
        if capacity <= 0:
            raise ValueError("Capacity must be greater than 0!")
        self.capacity = capacity
        self.data = {}
        self.head = None
        self.tail = None

    def get(self, key):
        if key not in self.data:
            return None
        entry = self.data[key]
        self.move_entry_to_last(entry)
        return entry.get_value()

    def put(self, key, value):
        if key in self.data:
            entry = self.data[key]
            entry.set_value(value)
            self.move_entry_to_last(entry)
            return
        if len(self.data) == self.capacity:
            self.data.pop(self.tail.get_key())
            self.remove(self.tail)
        entry = Entry(None, None, key, value)
        self.add_new_entry(entry)
        self.data[key] = entry

    def move_entry_to_last(self, entry):
        if self.tail == entry:
            return
        self.remove(entry)
        self.add_new_entry(entry)

    def remove(self, entry):
        if entry.get_pre_entry() is not None:
            entry.get_pre_entry().set_next_entry(entry.get_next_entry())
        else:
            self.head = entry.get_next_entry()
        if entry.get_next_entry() is not None:
            entry.get_next_entry().set_pre_entry(entry.get_pre_entry())
        else:
            self.tail = entry.get_pre_entry()

    def add_new_entry(self, entry):
        if self.tail is not None:
            self.tail.set_next_entry(entry)
            entry.set_pre_entry(self.tail)
        else:
            self.head = self.tail = entry

    def main(self):
        capacity = int(input())
        operations = int(input())
        mru_cache = Main(capacity)
        for i in range(operations):
            operation = input()
            if operation == "PUT":
                key = int(input())
                value = input()
                mru_cache.put(key, value)
                print("Added: (" + str(key) + ", " + value + ")")
            else:
                key = int(input())
                result = mru_cache.get(key)
                print("Retrieved: " + (str(result) if result is not None else "null"))


if __name__ == "__main__":
    mru_cache = Main(3)
    mru_cache.put(1, "one")
    mru_cache.put(2, "two")
    mru_cache.put(3, "three")
    mru_cache.put(4, "four")
    mru_cache.put(5, "five")
    mru_cache.put(6, "six")
    mru_cache.put(7, "seven")
    mru_cache.put(8, "eight")
    mru_cache.put(9, "nine")
    mru_cache.put(10, "ten")
    mru_cache.put(11, "eleven")
    mru_cache.put(12, "twelve")
    mru_cache.put(13, "thirteen")
    mru_cache.put(14, "fourteen")
    mru_cache.put(15, "fifteen")
    mru_cache.put(16, "sixteen")
    mru_cache.put(17, "seventeen")
    mru_cache.put(18, "eighteen")
    mru_cache.put(19, "nineteen")
    mru_cache.put(20, "twenty")
    mru_cache.put(21, "twenty-one")
    mru_cache.put(22, "twenty-two")
    mru_cache.put(23, "twenty-three")
    mru_cache.put(24, "twenty-four")
    mru_cache.put(25, "twenty-five")
    mru_cache.put(26, "twenty-six")
    mru_cache.put(27, "twenty-seven")
    mru_cache.put(28, "twenty-eight")
    mru_cache.put(29, "twenty-nine")
    mru_cache.put(30, "thirty")
    mru_cache.put(31, "thirty-one")
    mru_cache.put(32, "thirty-two")
    mru_cache.put(33, "thirty-three")
    mru_cache.put(34, "thirty-four")
    mru_cache.put(35, "thirty-five")
    mru_cache.put(36, "thirty-six")
    mru_cache.put(37, "thirty-seven")
    mru_cache.put(38, "thirty-eight")
    mru_cache.put(39, "thirty-nine")
    mru_cache.put(40, "forty")
    mru_cache.put(41, "forty-one")
    mru_cache.put(42, "forty-two")
    mru_cache.put(43, "forty-three")
    mru_cache.put(44, "forty-four")
    mru_cache.put(45, "forty-five")
    mru_cache.put(46, "forty-six")
    mru_cache.put(47, "forty-seven")
    mru_cache.put(48, "forty-eight")
    mru_cache.put(49, "forty-nine")
    mru_cache.put(50, "fifty")
    mru_cache.put(51, "fifty-one")
    mru_cache.put(52, "fifty-two")
    mru_cache.put(53, "fifty-three")
    mru_cache.put(54, "fifty-four")
    mru_cache.put(55, "fifty-five")
    mru_cache.put(56, "fifty-six")
    mru_cache.put(57, "fifty-seven")
    mru_cache.put(58, "fifty-eight")
    mru_cache.put(59, "fifty-nine")
    mru_cache.put(60, "sixty")
    mru_cache.put(61, "sixty-one")
    mru_cache.put(62, "sixty-two")
    mru_cache.put(63, "sixty-three")
    mru_cache.put(64, "sixty-four")
    mru_cache.put(65, "sixty-five")
    mru_cache.put(66, "sixty-six")
    mru_cache.put(67, "sixty-seven")
    mru_cache.put(68, "sixty-eight")
    mru_cache.put(69, "sixty-nine")
    mru_cache.put(70, "seventy")
    mru_cache.put(71, "seventy-one")
    mru_cache.put(72, "seventy-two")
    mru_cache.put(73, "seventy-three")
    mru_cache.put(74, "seventy-four")
    mru_cache.put(75, "seventy-five")
    mru_cache.put(76, "seventy-six")
    mru_cache.put(77, "seventy-seven")
    mru_cache.put(78, "seventy-eight")
    mru_cache.put(79, "seventy-nine")
    mru_cache.put(80, "eighty")
    mru_cache.put(81, "eighty-one")
    mru_cache.put(82, "eighty-two")
    mru_cache.put(83, "eighty-three")
    mru_cache.put(84, "eighty-four")
    mru_cache.put(85, "eighty-five")
    mru_cache.put(86, "eighty-six")
    mru_cache.put(87, "eighty-seven")
    mru_cache.put(88, "eighty-eight")
    mru_cache.put(89, "eighty-nine")
    mru_cache.put(90, "ninety")
    mru_cache.put(91, "ninety-one")
    mru_cache.put(92, "ninety-two")
    mru_cache.put(93, "ninety-three")
    mru_cache.put(94, "ninety-four")
    mru_cache.put(95, "ninety-five")
    mru_cache.put(96, "ninety-six")
    mru_cache.put(97, "ninety-seven")
    mru_cache.put(98, "ninety-eight")
    mru_cache.put(99, "ninety-nine")
    mru_cache.put(100, "one hundred")
    mru_cache.put(101, "one hundred and one")
    mru_cache.put(102, "one hundred and two")
    mru_cache.put(103, "one hundred and three")
    mru_cache.put(104, "one hundred and four")
    mru_cache.put(105, "one hundred and five")
    mru_cache.put(106, "one hundred and six")
    mru_cache.put(107, "one hundred and seven")
    mru_cache.put(108, "one hundred and eight")
    mru_cache.put(109, "one hundred and nine")
    mru_cache.put(110, "one hundred and ten")
    mru_cache.put(111, "one hundred and eleven")
    mru_cache.put(112, "one hundred and twelve")
    mru_cache.put(113, "one hundred and thirteen")
    mru_cache.put(114, "one hundred and fourteen")
    mru_cache.put(115, "one hundred and fifteen")
    mru_cache.put(116, "one hundred and sixteen")
    mru_cache.put(117, "one hundred and seventeen")
    mru_cache.put(118, "one hundred and eighteen")
    mru_cache.put(119, "one hundred and nineteen")
    mru_cache.put(120, "one hundred and twenty")
    mru_cache.put(121, "one hundred and twenty-one")
    mru_cache.put(122, "one hundred and twenty-two")
    mru_cache.put(123, "one hundred and twenty-three")
    mru_cache.put(124, "one hundred and twenty-four")
    mru_cache.put(125, "one hundred and twenty-five")
    mru_cache.put(126, "one hundred and twenty-six")
    mru_cache.put(127, "one hundred and twenty-seven")
    mru_cache.put(128, "one hundred and twenty-eight")
    mru_cache.put(129, "one hundred and twenty-nine")
    mru_cache.put(130, "one hundred and thirty")
    mru_cache.put(131, "one hundred and thirty-one")
    mru_cache.put(132, "one hundred and thirty-two")
    mru_cache.put(133, "one hundred and thirty-three")
    mru_cache.put(134, "one hundred and thirty-four")
    mru_cache.put(135, "one hundred and thirty-five")
    mru_cache.put(136, "one hundred and thirty-six")
    mru_cache.put(137, "one hundred and thirty-seven")
    mru_cache.put(138, "one hundred and thirty-eight")
    mru_cache.put(139, "one hundred and thirty-nine")
    mru_cache.put(140, "one hundred and forty")
    mru_cache.put(141, "one hundred and forty-one")
    mru_cache.put(142, "one hundred and forty-two")
    mru_cache.put(143, "one hundred and forty-three")
    mru_cache.put(144, "one hundred and forty-four")
    mru_cache.put(145, "one hundred and forty-five")
    mru_cache.put(146, "one hundred and forty-six")
    mru_cache.put(147, "one hundred and forty-seven")
    mru_cache.put(148, "one hundred and forty-eight")
    mru_cache.put(149, "one hundred and forty-nine")
    mru_cache.put(150, "one hundred and fifty")
    mru_cache.put(151, "one hundred and fifty-one")
    mru_cache.put(152, "one hundred and fifty-two")
    mru_cache.put(153, "one hundred and fifty-three")
    mru_cache.put(154, "one hundred and fifty-four")
    mru_cache.put(155, "one hundred and fifty-five")
    mru_cache.put(156, "one hundred and fifty-six")
    mru_cache.put(157, "one hundred and fifty-seven")
    mru_cache.put(158, "one hundred and fifty-eight")
    mru_cache.put(159, "one hundred and fifty-nine")
    mru_cache.put(160, "one hundred and sixty")
    mru_cache.put(161, "one hundred and sixty-one")
    mru_cache.put(162, "one hundred and sixty-two")
    mru_cache.put(163, "one hundred and sixty-three")
    mru_cache.put(164, "one hundred and sixty-four")
    mru_cache.put(165, "one hundred and sixty-five")
    mru_cache.put(166, "one hundred and sixty-six")
    mru_cache.put(167, "one hundred and sixty-seven")
    mru_cache.put(168, "one hundred and sixty-eight")
    mru_cache.put(169, "one hundred and sixty-nine")
    mru_cache.put
import sys


def load_dict(filename):
    with open(filename, "r") as f:
        lines = [line.strip() for line in f if line.strip()]
    numbers = {}
    for line in lines:
        if ":" not in line:
            continue
        key, value = line.split(":", 1)
        key = key.strip()
        value = value.strip()
        try:
            numbers[int(key)] = value
        except:
            continue
    return numbers


def convert_nb_less_100(nb, result, numbers):
    if nb <= 20:
        result.append(numbers[nb])
    else:
        tens = nb // 10 * 10
        units = nb % 10
        word = numbers[tens]
        if units != 0:
            word += "-" + numbers[units]
        result.append(word)


def convert_nb_less_1000(nb, result, numbers):
    if nb == 0:
        return

    if nb >= 100:
        hundreds = nb // 100
        word = numbers[hundreds] + " hundred"
        nb = nb % 100
        if nb > 0:
            word += " and"
            result.append(word)
            convert_nb_less_100(nb, result, numbers)
        else:
            result.append(word)
    else:
        convert_nb_less_100(nb, result, numbers)


def convert_number(nb, numbers):
    if nb == 0:
        return numbers[0]

    result = []
    chunks = []

    while nb > 0:
        chunks.append(nb % 1000)
        nb //= 1000

    for i in range(len(chunks) - 1, -1, -1):
        chunk = chunks[i]
        if chunk != 0:
            sub_result = []
            convert_nb_less_1000(chunk, sub_result, numbers)
            if i > 0:
                sub_result.append(numbers[1000**i])
                if i > 0:
                    sub_result.append(",")
            result.extend(sub_result)

    return " ".join(result).replace(" ,", ",")


def is_valid_number(s):
    return s.isdigit()


def main():
    args = sys.argv
    ac = len(args)

    if ac == 2:
        dict_file = "numbers.dict"
        number_str = args[1]
    elif ac == 3:
        dict_file = args[1]
        number_str = args[2]
    else:
        print("Error")
        return

    if not is_valid_number(number_str):
        print("Error")
        return

    try:
        numbers = load_dict(dict_file)
    except:
        print("Dict Error")
        return

    try:
        nb = int(number_str)
        print(convert_number(nb, numbers))
    except:
        print("Dict Error")


if __name__ == "__main__":
    main()

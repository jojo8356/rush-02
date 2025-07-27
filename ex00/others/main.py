text = open("numbers.dict", "r").read().split("\n")
text = [x for x in text if x]

# format
numbers = {}
for line in text:
	elements = line.split(":")
	elements = [x.replace(" ", "") for x in elements]
	numbers[eval(elements[0])] = elements[1]

def convert_nb_less_100(nb, result, numbers):
	if (nb > 0):
		if (nb <= 20):
			result += [numbers.get(nb)]
		else:
			result += [numbers.get(nb / 10 * 10) + ("-" + numbers.get(nb % 10) if (nb % 10 != 0) else "")]

def convert_nb_less_1000(nb, result, numbers):
	if (nb == 0):
		return
	if (nb >= 100):
		tmp = numbers.get(nb / 100)
		tmp += " hundred"
		nb = nb % 100
		if (nb > 0):
			tmp += " and"
		convert_nb_less_100(nb, result, numbers)
		result += [tmp]
	else:
		convert_nb_less_100(nb, result, numbers)

def convert_number(nb, numbers):
	if (not nb):
		return numbers.get(0)
	result = []
	power = 0
	current_group = 0
	while (nb > 0):
		current_group = nb % 1000
		if (current_group > 0):
			if (power > 0):
				result += [numbers.get(1000**power)]
				result += [","]
			convert_nb_less_1000(current_group, result, numbers)
		nb /= 1000
		power += 1
	return result

print(convert_number(42, numbers))
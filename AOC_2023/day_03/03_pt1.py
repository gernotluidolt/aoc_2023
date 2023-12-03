filepath = "/Users/gernot/repos/AOC_2023/day_03/03.txt"

sum = 0


def check_for_symbol(c):
    if not c.isdigit() and c != "." and c != "\n":
        return True
    return False


def check_string(s):
    for c in s:
        if check_for_symbol(c):
            return True
    return False


def find_full_num(s, index):
    n = s[index]
    try:
        while s[index+1].isdigit():
            n += s[index+1]
            index += 1
    except: # sketchy but ok with my input
        return "0"
    return n


with open(filepath, 'r') as file:
    lines = []
    for i, line in enumerate(file):
        lines.append(line)

    for i, line in enumerate(lines):
        for j, char in enumerate(line):
            if char.isdigit():
                if j != 0 and line[j-1].isdigit():
                    continue
                num = find_full_num(line, j)
                start = j - 1 if j != 0 else j
                end = j + len(num)-1 if j == len(line)-1 else j + len(num)

                if check_for_symbol(line[start]) or check_for_symbol(line[end]):
                    sum += int(num)
                    continue

                if i != 0 and check_string(lines[i-1][start:end+1]):
                    sum += int(num)
                    continue

                if i != len(lines) - 1 and check_string(lines[i+1][start:end+1]):
                    sum += int(num)
print(sum)

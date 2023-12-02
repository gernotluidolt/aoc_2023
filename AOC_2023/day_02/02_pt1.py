filepath = "/Users/gernot/repos/AOC_2023/day_02/02.txt"

sum = 0

with open(filepath, 'r') as file:
    for i, line in enumerate(file):
        valid_game = True
        throws = line.split(": ")[1].split("; ")
        for throw in throws:
            count = 0
            for j, char in enumerate(throw):
                if j != len(throw)-4 and char.isdigit() and throw[j+1].isdigit():
                    num = int(char + throw[j+1])
                    if throw[j+3] == "r":
                        max = 12
                    elif throw[j+3] == "g":
                        max = 13
                    elif throw[j+3] == "b":
                        max = 14
                    if num > max:
                        valid_game = False
        if valid_game:
            sum += i + 1
    print(sum)
filepath = "/Users/gernot/repos/AOC_2023/day_02/02.txt"

sum = 0

with open(filepath, 'r') as file:
    for i, line in enumerate(file):
        games = line.split(": ")[1]
        throws = games.split("; ")

        min_red = 1
        min_green = 1
        min_blue = 1

        for throw in throws:
            for j, char in enumerate(throw):

                if j != len(throw)-1 and char.isdigit():
                    if throw[j+1].isdigit():
                        num = int(char + throw[j+1])
                    else:
                        num = int(char)
                    if (throw[j+2] == "r" or throw[j+5] == "d") and num > min_red:
                        min_red = num
                    elif (throw[j+2] == "g" or throw[j+3] == "g") and num > min_green:
                        min_green = num
                    elif (throw[j+2] == "b" or throw[j+3] == "b") and num > min_blue:
                        min_blue = num
        sum += min_red * min_green * min_blue

    print(sum)
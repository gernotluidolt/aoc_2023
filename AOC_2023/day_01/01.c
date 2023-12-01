# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <ctype.h>

int get_calibration_value(char* line) {
    int first = -1;
    int last;

    for (int i = 0; line[i] != 0; i++){
        char current = line[i];
        if (isdigit(current)) {
            int num = current - 48;
            if (first == -1) {
                first = num;
            }
            last = num;
        }
    }
    return first * 10 + last;
}

int main() {
    // specifies working directory (where the .txt is)
    chdir("/Users/gernot/repos/AOC_2023/day_01");

    // opens the .txt
    FILE *input = fopen("01.txt", "r");

    // reads the .txt
    char buffer[1000]; // can store lines up to 1000 chars each

    // sum of calibration numbers
    int sum = 0;

    // loop goes into new iteration if buffer is full, or if a newline is read
    while (fgets(buffer, 1000, input) != NULL) {
        sum += get_calibration_value(buffer);
    }
    fclose(input);

    // output sum to cl
    printf("%d", sum);
}
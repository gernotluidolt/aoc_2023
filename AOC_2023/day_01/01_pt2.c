# include <stdio.h>
# include <ctype.h>
# include <string.h>

int get_first_digit_index(char* line) {
    int first = -1;
    for (int i = 0; line[i] != 0; i++){
        char current = line[i];
        if (isdigit(current)) {
            if (first == -1) {
                first = i;
            }
        }
    }
    return first;
}

int get_last_digit_index(char* line) {
    int last = -1;
    for (int i = 0; line[i] != 0; i++){
        char current = line[i];
        if (isdigit(current)) {
            last = i;
        }
    }
    return last;
}

int get_first_digit_value(char* line) {
    int first = 0;
    for (int i = 0; line[i] != 0; i++){
        char current = line[i];
        if (isdigit(current)) {
            return current - 48;
        }
    }
    return first;
}

int get_last_digit_value(char* line) {
    int last = 0;
    for (int i = 0; line[i] != 0; i++){
        char current = line[i];
        if (isdigit(current)) {
            last = current - 48;
        }
    }
    return last;
}

int get_first_string_index(char *num_string, char *line){
    if (strstr(line, num_string) != NULL) {
        return strstr(line, num_string) - line;
    } else {
        return -1;
    }
}

int get_last_string_index(char *num_string, char *line){
    char *temp = line;
    char *pos;
    int index = -1;

    while ((pos = strstr(temp, num_string)) != NULL) {
        index = pos - line;
        temp = pos + (strlen(num_string));
    }
    return index;
}

int get_calibration_value(char* line) {
    char nums[9][6] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    int value_first = get_first_digit_value(line); // default to first digit value
    int value_last = get_last_digit_value(line);   // default to last digit value

    int first_digit_index = get_first_digit_index(line);
    int last_digit_index = get_last_digit_index(line);

    for (int i = 0; i < 9; i++) {
        int first_occurrence = get_first_string_index(nums[i], line);
        int last_occurrence = get_last_string_index(nums[i], line);

        // check if a numeric word is before the first digit
        if (first_occurrence != -1 && (first_occurrence < first_digit_index || first_digit_index == -1)) {
            value_first = i + 1;
            first_digit_index = first_occurrence; // update first_digit_index to numeric word index
        }

        // check if a numeric word is after the last digit
        if (last_occurrence != -1 && (last_occurrence > last_digit_index || last_digit_index == -1)) {
            value_last = i + 1;
            last_digit_index = last_occurrence; // update last_digit_index to numeric word index
        }
    }

    return value_first * 10 + value_last;
}

int main() {
    // opens the .txt
    FILE *input = fopen("/Users/gernot/repos/AOC_2023/day_01/01.txt", "r");

    // reads the .txt
    char buffer[1000]; // can store lines up to 1000 chars each

    // sum of calibration numbers
    int sum = 0;

    // loop goes into new iteration if buffer is full, or if a newline is read
    while (fgets(buffer, 1000, input) != NULL) {
        sum += get_calibration_value(buffer);
    }

    // close .txt
    fclose(input);

    // output sum to cl
    printf("%d", sum);

    return 0;
}
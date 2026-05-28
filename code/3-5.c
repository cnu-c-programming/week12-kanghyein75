#include <stdio.h>

int main(int argc, const char* argv[]) {
    const char* filename = "numbers.txt";

    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        return 0;
    }

    int sum = 0;
    int num;
    int c;
    
    while (c = (fscanf(fp, "%d", &num)) != EOF) {
        if (c == 1) {
            sum += num;
        } else {
            char fail[100];
            fscanf(fp, "%s", fail);
            fprintf(stderr, "invalid input %s\n", fail);
        }
    }

    printf("sum: %d\n", sum);
    fclose(fp);
    return 0;
}

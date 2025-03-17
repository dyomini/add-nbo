#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("syntax : sum-nbo <file1> [<file2>...]\n");
        printf("sample : sum-nbo a.bin b.bin\n");
        printf("please select at least two files.\n");
        return 1;
    }

    uint32_t x, sum = 0, res;
    FILE *fp;

    for (int i = 1; i < argc; i++) {
        fp = fopen(argv[i], "rb");

        if (fp == NULL) {
            printf("File %s cannot be opened.\n", argv[i]);
            return 1;
        }

        res = fread(&x, sizeof(uint32_t), 1, fp);

        if (res != 1) {
            printf("File %s is too small to read 4 bytes.\n", argv[i]);
            fclose(fp);
            return 1;
        }

        x = ntohl(x);
        printf("%d(0x%x)", x, x);

        sum += x;

        fclose(fp);

        if (i < argc - 1) {
            printf(" + ");
        }
    }

    printf(" = %d(0x%x)\n", sum, sum);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        fprintf(stderr, "mv: two arguments should be informed.");
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "mv: file %s does not exist.");
        return EXIT_FAILURE;
    }
    fclose(file);

    rename(argv[1], argv[2]);

    return EXIT_SUCCESS;
}
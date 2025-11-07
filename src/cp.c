#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        fprintf(stderr, "cp: two arguments should be informed.");
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "cp: file %s does not exist.", argv[1]);
        return EXIT_FAILURE;
    }

    char *char_buffer = malloc(1024);
    FILE *new_file = fopen(argv[2], "w");
    if (!new_file)
    {
        fprintf(stderr, "cp: error while oppening file %s.", argv[2]);
        return EXIT_FAILURE;
    }

    while (fgets(char_buffer, 1024, file))
    {
        fputs(char_buffer, new_file);
    }

    fclose(new_file);
    fclose(file);

    return EXIT_SUCCESS;
}
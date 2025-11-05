#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        fprintf(stderr, "cat: at least one file should be informed.");
        return EXIT_FAILURE;
    }

    for (int i = 1; i < argc; i++)
    {
        FILE *file;
        if (!(file = fopen(argv[i], "r")))
        {
            fprintf(stderr, "cat: file %s does not exist.", argv[i]);
            return EXIT_FAILURE;
        }

        fseek(file, 0, SEEK_END);
        long file_size = ftell(file);
        rewind(file);
        char *file_content = malloc(file_size + 1);

        fread(file_content, file_size, 1, file);
        file_content[file_size] = '\0';

        puts(file_content);
        fclose(file);
    }

    return EXIT_SUCCESS;
}
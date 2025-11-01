#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        fprintf(stderr, "rm: at least one file should be informed.");
        return EXIT_FAILURE;
    }

    for (int i = 1; i < argc; i++)
    {
        FILE *file = fopen(argv[i], "r");

        if (file == NULL)
        {
            fprintf(stderr, "rm: file %s does not exist.");
            continue;
        }

        fclose(file);

        if (unlink(argv[i]) == -1)
        {
            fprintf(stderr, "rm: error while deleting file %s: %s.", argv[i], strerror(errno));
        }
    }

    return EXIT_SUCCESS;
}
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

typedef struct dirent dirent;

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        fprintf(stderr, "ls: at least one file should be informed.");
        return EXIT_FAILURE;
    }

    for (int i = 1; i < argc; i++)
    {
        DIR *dir;
        dirent *dir_struct;
        dir = opendir(argv[i]);

        if (!dir)
        {
            fprintf(stderr, "ls: %s is not a valid directory.", argv[i]);
            return EXIT_FAILURE;
        }

        while ((dir_struct = readdir(dir)) != NULL)
        {
            fprintf(stdout, "%s\n", dir_struct->d_name);
        }

        closedir(dir);
    }

    return EXIT_SUCCESS;
}

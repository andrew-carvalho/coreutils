#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char **argv)
{
    bool rm_empty_dirs = false;

    if (argc < 2)
    {
        fprintf(stderr, "rmdir: at least one directory should be informed.");
        return EXIT_FAILURE;
    }

    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-f") == 0)
        {
            rm_empty_dirs = true;
            exit;
        }
    }

    for (int i = 1; i < argc; i++)
    {
        DIR *dir = opendir(argv[i]);
        struct dirent *dir_struct;

        if (strcmp(argv[i], "-f") == 0)
        {
            continue;
        }

        if (!dir)
        {
            fprintf(stderr, "rmdir: %s is not a valid directory.\n", argv[i]);
            continue;
        }

        closedir(dir);

        if (rmdir(argv[i]) == -1)
        {
            if (errno != ENOTEMPTY)
            {
                fprintf(stderr, "rmdir: error while deleting directory %s: %s\n", argv[i], strerror(errno));
                continue;
            }

            if (rm_empty_dirs == false)
            {
                fprintf(stderr, "rmdir: directory %s is not empty, use flag -f to force deletion\n", argv[i]);
            }
            else
            {
                // TODO(andrew): remove directories inside directories
                dir = opendir(argv[i]);
                while ((dir_struct = readdir(dir)) != NULL)
                {
                    const char *file_name = dir_struct->d_name;
                    if (strcmp(file_name, ".") == 0 || strcmp(file_name, "..") == 0)
                    {
                        continue;
                    }

                    char *full_filename = malloc(sizeof(argv[i]) + 1 + sizeof(file_name));
                    strcpy(full_filename, argv[i]);
                    strcat(strcat(full_filename, "/"), file_name);
                    if (unlink(full_filename) == -1)
                    {
                        fprintf(stderr, "rmdir: error while deleting file %s: %s\n", file_name, strerror(errno));
                    }
                    free(full_filename);
                }
                closedir(dir);

                if (rmdir(argv[i]) == -1)
                {
                    fprintf(stderr, "rmdir: error while deleting directory %s: %s\n", argv[i], strerror(errno));
                }
            }
        }
    }

    return EXIT_SUCCESS;
}
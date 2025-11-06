#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <utime.h>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        fprintf(stderr, "touch: at least one file should be informed.");
        return EXIT_FAILURE;
    }

    for (int i = 1; i < argc; i++)
    {
        FILE *file = fopen(argv[i], "r");

        if (file != NULL)
        {
            time_t current_time;
            struct utimbuf test;

            time(&current_time);
            test.modtime = current_time;
            test.actime = current_time;
            utime(argv[i], &test);
        }
        else
        {
            file = fopen(argv[i], "w");
        }

        fclose(file);
    }

    return EXIT_SUCCESS;
}
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    size_t path_max_size = PATH_MAX;
    char *pwd = malloc(path_max_size);
    getcwd(pwd, path_max_size);
    puts(pwd);
    return EXIT_SUCCESS;
}
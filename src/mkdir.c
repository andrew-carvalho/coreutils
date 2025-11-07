#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char **argv)
{
  if (argc < 2)
  {
    fprintf(stderr, "mkdir: at least one directory should be informed.");
    return EXIT_FAILURE;
  }

  for (int i = 1; i < argc; i++)
  {
    struct stat st = {0};

    if (stat(argv[i], &st) != -1)
    {
      fprintf(stdout, "mkdir: directory %s already exists", argv[i]);
      continue;
    }

    mkdir(argv[i]);
  }

  return EXIT_SUCCESS;
}

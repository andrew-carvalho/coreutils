#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#endif

int main(int argc, char **argv)
{
    char *username = malloc(256);

#ifdef _WIN32
    DWORD username_length = sizeof(username);
    GetUserNameA(username, &username_length);
#else
    username = getlogin();
#endif

    if (!username)
    {
        fprintf(stderr, "whoami: could not determine username.");
        return EXIT_FAILURE;
    }

    puts(username);
    return EXIT_SUCCESS;
}
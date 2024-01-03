#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

int main(void)
{
    char buffer[5];
    read(STDIN_FILENO, buffer, 5);

    printf("read: %s", buffer);

    return 0;
}

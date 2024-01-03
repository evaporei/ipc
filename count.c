#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    // 0: STDIN  (read)
    // 1: STDOUT (write)
    int pfds[2];

    pipe(pfds);

    if (!fork()) {
        // child
        close(1);       /* close regular STDOUT */
        dup(pfds[1]);   /* make STDOUT same as pfds[1] */
        close(pfds[0]); /* we don't need STDIN */
        execlp("ls", "ls", NULL);
    } else {
        // parent
        close(0);       /* close regular STDIN */
        dup(pfds[0]);   /* make STDIN same as pfds[0] */
        close(pfds[1]); /* we don't need STDOUT (anymore?) */
        execlp("wc", "wc", "-l", NULL);
    }

    return 0;
}

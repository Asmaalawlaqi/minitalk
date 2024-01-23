#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void the_server(int sig)
{
    static int i ;
    static char c ;

    c = c + ((sig & 1) << i);
    i++;

    if (i == 8)
    {
        write(1, &c, 1);
        c = 0;
        i = 0;
    }
}

int main()
{
    ft_printf("Server PID: %d\n", getpid());

    signal(SIGUSR1, the_server);
    signal(SIGUSR2, the_server);

    while (1)
        pause();
    return 0;
}

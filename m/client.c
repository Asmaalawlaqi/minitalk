#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void send_m(char *m, int pid) {
    int i;
    int x;
    int shift;

    i = 0;
    while (m[i] != '\0') 
    {
        x = m[i];
        shift = 0;
        while (shift < 8)
         {
            if ((x >> shift) & 1) 
                kill(pid, SIGUSR2);
             else 
                kill(pid, SIGUSR1); 
            usleep(350);
            shift++;
        }
        i++;
    }
}

int main(int ac, char **av)
 {
    if (ac != 3) {
        ft_printf("%s pid message\n", av[0]);
        return(1);
    }

    int pid = atoi(av[1]);
    if (pid <= 0) {
        ft_printf("invalid pid\n");
        exit(1);
    }

    char *m = av[2];
    send_m(m, pid);
    exit(0);
}

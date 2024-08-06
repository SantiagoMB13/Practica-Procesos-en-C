#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid1, pid2, pid3, pid4, pid5, pid6, pid7;

    // Proceso padre
    pid1 = getpid();
    printf("Proceso Padre: PID = %d\n", getpid());

    // Proceso hijo 1 (3464)
    pid2 = fork();
    if (pid2 == 0) {
        printf("Proceso Hijo: PID = %d, PID del Padre = %d\n", getpid(), getppid());

        // Proceso nieto (hijo de 3464, 3468)
        pid3 = fork();
        if (pid3 == 0) {
            printf("Proceso Hijo: PID = %d, PID del Padre = %d\n", getpid(), getppid());

            // Proceso bisnieto (hijo de 3468, 3469)
            pid5 = fork();
            if (pid5 == 0) {
                printf("Proceso Hijo: PID = %d, PID del Padre = %d\n", getpid(), getppid());
                while (1);  // Bucle infinito para mantener el proceso bisnieto en ejecución
            }
            while (1);  // Bucle infinito para mantener el proceso nieto en ejecución
        }
        while (1);  // Bucle infinito para mantener el proceso hijo 1 en ejecución
    } else {  // Proceso padre (3463)
        pid7 = fork();
        if (pid7 == 0) {
            printf("Proceso Hijo: PID = %d, PID del Padre = %d\n", getpid(), getppid());
            while (1);  // Bucle infinito para mantener el proceso hijo 2 en ejecución
        }

        // Proceso hijo 3 (34646)
        pid4 = fork();
        if (pid4 == 0) {
            printf("Proceso Hijo: PID = %d, PID del Padre = %d\n", getpid(), getppid());
            while (1);  // Bucle infinito para mantener el proceso hijo 3 en ejecución
        }

        // Proceso hijo 4 (34647)
        pid6 = fork();
        if (pid6 == 0) {
            printf("Proceso Hijo: PID = %d, PID del Padre = %d\n", getpid(), getppid());
            while (1);  // Bucle infinito para mantener el proceso hijo 4 en ejecución
        }
    }

    // Espera a que todos los procesos hijos terminen
    if (getpid() == pid1) {
        for (int i = 0; i < 7; i++) {
            wait(NULL);
        }
    }
    while (1);
    return 0;
}



#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid1, pid2, pid3, pid4, pid5, pid6, pid7, pid8;

    // Proceso padre (3463)
    pid1 = getpid();
    printf("Proceso Padre: PID = %d\n", getpid());

    // Proceso hijo 1 (3464)
    pid2 = fork();
    if (pid2 == 0) {
        printf("Proceso Hijo: PID = %d, PID del Padre = %d\n", getpid(), getppid());

        // Proceso hijo 1 de hijo 1 (hijo de 3464, 3467)
        pid3 = fork();
        if (pid3 == 0) {
            printf("Proceso Hijo: PID = %d, PID del Padre = %d\n", getpid(), getppid());
            while (1);
        }
        
        // Proceso hijo 2 de hijo 1 (hijo de 3464, 3468)
        pid5 = fork();
        if (pid5 == 0) {
            printf("Proceso Hijo: PID = %d, PID del Padre = %d\n", getpid(), getppid());
            while (1);
        }
        
        while (1);  // Bucle infinito para mantener el proceso hijo 1 en ejecución
    } else {  
        // Proceso hijo 2 (3465)
        pid7 = fork();
        if (pid7 == 0) {
            printf("Proceso Hijo: PID = %d, PID del Padre = %d\n", getpid(), getppid());

            // Proceso hijo 1 de hijo 2 (3469)
            pid6 = fork();
            if (pid6 == 0) {
                printf("Proceso Hijo: PID = %d, PID del Padre = %d\n", getpid(), getppid());
                while (1);
            }

            // Proceso hijo 2 de hijo 2 (3470)
            pid8 = fork();
            if (pid8 == 0) {
                printf("Proceso Hijo: PID = %d, PID del Padre = %d\n", getpid(), getppid());
                while (1);
            }
            
            while (1);  // Bucle infinito para mantener el proceso hijo 2 en ejecución
        }

        // Proceso hijo 3 (3466)
        pid4 = fork();
        if (pid4 == 0) {
            printf("Proceso Hijo: PID = %d, PID del Padre = %d\n", getpid(), getppid());
            while (1);
        }
    }

    // Espera a que todos los procesos hijos terminen
    if (getpid() == pid1) {
        for (int i = 0; i < 8; i++) {
            wait(NULL);
        }
    }
    while (1);
    return 0;
}


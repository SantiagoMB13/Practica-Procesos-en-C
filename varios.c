#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Uso: %s <n>\n", argv[0]);
        exit(1);
    }

    int n = atoi(argv[1]);

    if (n <= 0) {
        fprintf(stderr, "El valor de n debe ser un número entero positivo.\n");
        exit(1);
    }

    // Almacena el PID del proceso principal (padre original)
    pid_t proceso_padre = getpid();

    for (int i = 0; i < n; i++) {
        fork(); // Llama a fork n veces
    }

    // Esta parte se ejecutará después de crear todos los procesos
    if (getpid() == proceso_padre) {
        printf("Proceso padre: PID = %d\n", getpid());
    } else {
        printf("Proceso Hijo: PID = %d, PPID = %d\n", getpid(), getppid());
    }

    while(1);
    return 0;
}

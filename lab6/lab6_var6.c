#include <spawn.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

extern char **environ;

int main() {
    pid_t pid;
    int status;

    FILE *file = fopen("KI-241_Liver.txt", "w");
    if (file == NULL) {
        perror("Помилка відкриття файлу");
        return 1;
    }

    fprintf(file, "Процес: батьківський | PID: %d\n", getpid());

    char *argv[] = {"curl", "cs.stu.cn.ua", NULL};

    if (posix_spawn(&pid, "/usr/bin/curl",
                    NULL, NULL, argv, environ) != 0) {
        fprintf(file, "Помилка створення дочірнього процесу\n");
        fclose(file);
        return 1;
    }

    fprintf(file, "Процес: дочірній | PID: %d\n", pid);

    waitpid(pid, &status, 0);

    if (WIFEXITED(status)) {
        fprintf(file,
                "Дочірній процес завершився з кодом: %d\n",
                WEXITSTATUS(status));
    }

    fclose(file);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int value = 0;
void *runner(void *param) {
     value = 5;
     return NULL;
}

int main(int argc, char **argv) {
    pid_t pid;
    pthread_t tid;

    pid = fork();
    if (pid == 0) {
        printf("CHILD: before %d\n", value);  
        pthread_create(&tid, NULL, runner, NULL);
        pthread_join(tid, NULL);
        printf("CHILD: after %d\n", value);  
    } else {
        printf("PARENT: before %d\n", value);
        wait(NULL);
        printf("PARENT: after %d\n", value);
    }
    exit(0);
}

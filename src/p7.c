/* Program that executes a sum n time specified by the user */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
 
int hijos_wait = 0;
int numIter = 0;
int numProcs = 0;

void MathOperation(){
    for(int i=0; i < numIter; i++){
        hijos_wait++;
        // printf("PID %d increment is at: %d\n", getpid(), hijos_wait);
        // fflush(stdout);
        char buf[255];
        sprintf(buf, "PID %d increment is at: %d\n", getpid(), hijos_wait);
        write(1, buf, strlen(buf));
    }
}

int main(int argc, char *argv[]) {
    if(argc <= 1){
        printf("USAGE: %s numIterarions numProcesses\n", argv[0]);
    }else{
        numIter = atoi(argv[1]);
        numProcs = atoi(argv[2]);
    }
    /* Process status info after exitting */
    int status = 0;
    char buffer[255];

    for (int i = 0; i < numProcs; i++) {
        switch (fork())
        {
        case -1:
            printf("error creating process ocurred\n");
            break;
        case 0:
        {
            /* Child execution */
            MathOperation();
            sleep(i);
            /* first tool of synchronization */
            exit(0);
            break;
        }
        default:
        {
            sprintf(buffer, "I'm the parent: %d\n", getpid());
            write(1, buffer, strlen(buffer));
            /* Parent execution */
            break;
        }
        }
    }
    
    while(numProcs > 0){
        wait(&status);
        printf("End wait status: %d\n", WEXITSTATUS(status));
        numProcs --;
    }
    
    return(0);
}

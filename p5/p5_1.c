#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main() {
    int x = 10;
    int rc = fork();
    if (rc < 0) {
        printf("fork failed [%d]\n", getpid());
    }
    else if (rc == 0) {
        x = 11;
        printf("child process: x=%d [%d]\n",x,getpid());
    }
    else {
        x = 12;
        printf("parent process: x=%d [%d]\n",x,getpid());
    }
    return 0;
}
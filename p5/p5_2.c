#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main() {
    int f = open("./file_p5_2.output", O_CREAT|O_WRONLY|O_TRUNC, S_IWUSR);
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr,"fork failed [%d]\n", getpid());
    }
    else if (rc == 0) {
        const char buf[20] = "child process";
        write(f,buf,20);
    }
    else {
        const char buf[20] = "parent process";
        write(f,buf,20);
    }
    return 0;
}
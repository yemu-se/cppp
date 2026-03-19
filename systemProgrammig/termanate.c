#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <errno.h>

int main(){
    pid_t target_pid =1234;
    if(kill(target_pid,SIGTERM)==0){
        printf("Termination signal sent successfully to %d\n",target_pid);
    }
        else
        {
            perror("error sending signal");
        }
        return 0;
    
}
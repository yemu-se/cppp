#include <stdio.h>
#include <stdlib.h> // Required for system()

int main() {
    printf("This is a C System Program.\n");
    
    // This sends a command directly to the OS terminal
    printf("Current Date and Time from OS:\n");
    system("date /t");
    system("time /t");

    return 0;
}
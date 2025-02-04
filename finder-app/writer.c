#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>


int main(int argc, char** argv){

    openlog("assignment2",LOG_PID | LOG_CONS, LOG_USER);

    if(argc != 3){
        syslog(LOG_ERR, "Invalid input parameters.");
        return 1;
    } 
    ssize_t ret;
    char* path = argv[1];
    char* text = argv[2];
    int len = strlen(text);

    int fd = open(path,O_WRONLY | O_CREAT | O_TRUNC,0644);
    if(fd < 0) {
        syslog(LOG_ERR, "Error opening %s", path);
        return 1;
    }

    ret = write(fd, text, len);
    if(ret == -1){
        syslog(LOG_ERR, "Error writing %s to %s", text, path);
    } else {
        syslog(LOG_DEBUG, "Writing %s to %s", text, path);
    }

    close(fd);
    closelog();

    return 0;
}
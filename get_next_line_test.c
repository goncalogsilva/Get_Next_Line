#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
# include <fcntl.h>

char *readLine(int fd, size_t bufferSize) {
    // Declare buffer as static to preserve its value between function calls
    static char buffer[1024];
    static int bufferUsed = 0;
    int charsRead = 0;
    while (1) {
        // Read characters into buffer
        int bytesRead = read(fd, buffer + bufferUsed + charsRead, bufferSize);

        // Check for end of file
        if (bytesRead <= 0) {
            break;
        }

        // Update the number of characters read
        charsRead += bytesRead;

        // Check if newline character is found
        int endLine = 0;
        for (int i = bufferUsed + charsRead - bytesRead; i < bufferUsed + charsRead; i++) {
            if (buffer[i] == '\n') {
                endLine = 1;
                break;
            }
        }
        if (endLine) {
            break;
        }
        // Reallocate buffer if necessary
        if (bufferUsed + charsRead + bufferSize > sizeof(buffer)) {
            printf("Error: buffer overflow\n");
            break;
        }
    }

    bufferUsed += charsRead;
    buffer[bufferUsed] = '\0';

    // If no characters were read, return NULL
    if (charsRead == 0) {
        return NULL;
    }
    char *result = buffer;
    bufferUsed = 0;
    return result;
}

int main(){
    int fd = open("testfile", O_RDONLY);
    char *line = NULL;
    while((line = readLine(fd, 8)) != NULL) {
        printf("Line read: %s",line);
    }
    close(fd);
    return 0;
}
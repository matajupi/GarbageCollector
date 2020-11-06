#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *freadline(FILE *in) {
    char *buffer, *tmp;
    int c;
    
    buffer = malloc(1);
    if (buffer == NULL) goto END;
    buffer[0] = '\0';

    while ((c = fgetc(in)) != EOF) {
        // strlen�ł�EOS���������������A���Ă���̂�+2�ƂȂ�
        tmp = realloc(buffer, strlen(buffer) + 2);
        if (tmp == NULL) break;
        buffer = tmp;
        tmp += strlen(buffer);
        *tmp++ = c;
        *tmp = '\0';
        if (c == '\n') break;
    }
END:
    return buffer;
}

int main(int argc, char *argv) {
    char *line = freadline(stdin);
    printf("%s", line);
    free(line);
    return 0;
}

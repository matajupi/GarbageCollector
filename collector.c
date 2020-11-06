#include <stdio.h>
#include <stdlib.h>

int *references;
char *marks;
size_t size = 1;

void addroot(void *ref) {
    
}

void addgc(void *array) {
    references = realloc(references, sizeof(references) + 4);
    size = size + 1;
    marks = realloc(marks, sizeof(marks) + 1);
    references[sizeof(references) - 4] = *array;
}

void rungc() {
    
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFERSIZE 255

void main(int argc, char *argv[]) {
    FILE *fp, *fq
    int i, n;
    char buffer[BUFFERSIZE];

    /* Open file in read-only */
    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("%s does not exist\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    /* Create destination file */
    fq = fopen(argv[2], "w");
    if (fq == NULL) {
        perror("An error occurred in creating the file\n");
        exit(EXIT_FAILURE);
    }

    /* Shift ASCII value of each char */
    while (!feof(fp)) {
        fgets(buffer, BUFFSIZE, fp);
        n = strlen(buffer);

        for (i=0; i<n; i++) {
            buffer[i] = buffer[i]-45;
        }
        fputs(buffer, fq);
    }
    fclose(fp);
    fclose(fq);
}
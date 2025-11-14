#include <stdio.h>

int main(void) {
    FILE *fp = fopen("level3_2_large.in", "r");
    FILE *output = fopen("level3.out", "w");

    int n;
    fscanf(fp, "%d\n", &n);

    for (int i=0; i<n; i++) {
        int width;
        int height;
        int max;
        int stationPosition;
        fscanf(fp, "%d ", &width);
        fscanf(fp, "%d ", &height);
        fscanf(fp, "%d\n", &max);

        for(int j=0; j<width+2; j++) {
            char BUFFER;
            fscanf(fp, "%c ", &BUFFER);
            if(BUFFER == 'S') {
                stationPosition = j-1;
            }
        } 

        for (int j=0; j<height+1; j++) {
            char line[1024];
            fgets(line, sizeof(line), fp);
        }

        if (width == 3) {
            for(int j=0; j<width+2; j++) {
                if (j==stationPosition+1) {
                    fprintf(output, "S");
                }
                else {
                    fprintf(output, "#");
                }
            }
            fprintf(output, "\n");

            for(int j=0; j<height; j++) {
                fprintf(output, "#");
                for(int k=0; k<width; k++) {
                    if (k==1) {
                        fprintf(output, "X");
                    }
                    else if(k==stationPosition && j==0) {
                        fprintf(output, "X");
                    }
                    else {
                        fprintf(output, ":");
                    }
                }
                fprintf(output, "#\n");
            }

            for(int j=0; j<width+2; j++) {
                fprintf(output, "#");
            }
            fprintf(output, "\n\n");
        }
        else {
            for(int j=0; j<width+2; j++) {
                if (j==stationPosition+1) {
                    fprintf(output, "S");
                }
                else {
                    fprintf(output, "#");
                }
            }
            fprintf(output, "\n");

            for(int j=0; j<height; j++) {
                fprintf(output, "#");
                for(int k=0; k<width; k++) {
                    if (j==1) {
                        fprintf(output, "X");
                    }
                    else if(k==stationPosition && j==0) {
                        fprintf(output, "X");
                    }
                    else {
                        fprintf(output, ":");
                    }
                }
                fprintf(output, "#\n");
            }

            for(int j=0; j<width+2; j++) {
                fprintf(output, "#");
            }
            fprintf(output, "\n\n");
        }

    }
}
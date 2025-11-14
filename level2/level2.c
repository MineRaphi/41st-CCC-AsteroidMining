#include <stdio.h>

int main(void) {
    FILE *fp = fopen("level2_2_large.in", "r");
    FILE *output = fopen("level2.out", "w");

    int n;
    fscanf(fp, "%d\n", &n);

    for (int i=0; i<n; i++) {
        int width;
        int height;
        fscanf(fp, "%d ", &width);
        fscanf(fp, "%d\n", &height);

        for (int j=0; j<height+2; j++) {
            char line[1024];
            fgets(line, sizeof(line), fp);
        }

        for(int j=0; j<width+2; j++) {
            if (j==2) {
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
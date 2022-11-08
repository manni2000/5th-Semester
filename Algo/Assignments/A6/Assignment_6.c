#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int visited[1000];
int A[1000][1000];

void DFS (int i, int max) {
    printf("%d ", i);
    visited[i] = 1;
    for (int j = 0; j < max; j++) {
        if (A[i][j] == 1 && !visited[j])
            DFS(j, max);
    }
}

int main() {
    int max;
    printf("Enter the number of Nodes: ");
    scanf("%d", &max);

    printf("The Nodes are: \n");
    for (int i = 0; i < max; i++) {
        printf("%d ", i);
    }

    for (int i = 0; i < max; i++)
        visited[i] = 0;

    int points[max][2];
    int upper = max, lower = 2;

    srand(time(0));
    for (int i = 0; i < max; i++) {
        int x = (rand() % (upper - lower + 1)) + lower;
        int y = (rand() % (upper - lower + 1)) + lower;
        points[i][0] = x;
        points[i][1] = y;
        for (int j = 0; j < i; j++) {
            if (points[j][0] == x && points[j][1] == y){
                i--;
                break;
            }
        }
    }

    int nC2 = (max * (max - 1)) / 4, nCount = 0;

    FILE *filePointer, *fileCommands;
    filePointer = fopen ("Points.txt", "w");        // open points file
    fileCommands = fopen ("Commands.txt", "w");     // open command file

    fputs ("set xrange [", fileCommands);           // to command file
    fprintf(fileCommands, "%d", 0);             // to command file
    fputs(":", fileCommands);                       // to command file
    fprintf(fileCommands, "%d", (max + 2));     // to command file
    fputs("]\n", fileCommands);                     // to command file

    fputs ("set yrange [", fileCommands);           // to command file
    fprintf(fileCommands, "%d", 0);             // to command file
    fputs(":", fileCommands);                       // to command file
    fprintf(fileCommands, "%d", (max + 2));     // to command file
    fputs("]\n", fileCommands);                     // to command file

    srand(time(0));
    for (int i = 0; i < max; i++) {
        fprintf(filePointer, "%d %d\n", points[i][0], points[i][1]);    // to points file
        for (int j = 0; j < max; j++) {
            if ((i == j) || A[j][i] == 1 || nC2 == nCount) {
                A[i][j] = 0;
            } else {
                int num = rand() % 2;
                A[i][j] = num;

                if (num == 1){
                    fputs("set arrow from ", fileCommands);                             // to command file
                    fprintf(fileCommands, "%d,%d", points[i][0], points[i][1]);     // to command file
                    fputs(" to ", fileCommands);                                        // to command file
                    fprintf(fileCommands, "%d,%d\n", points[j][0], points[j][1]);   // to command file
                    nCount++;
                }
            }
        }
    }
    fputs("plot 'Points.txt' with circles", fileCommands); // to command file
    fclose(filePointer);    // close points file
    fclose(fileCommands);   // close command file

    int start;
    printf("\nEnter the start: ");
    scanf("%d", &start);

    printf("\nDFS Transversal: \n");

    DFS(start, max);
    return 0;
}
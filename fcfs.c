#include <stdio.h>
struct process {
  int btime;
  int wtime;
  int ttime;
} p[10];
void main() {
  int i, j, k, n, ttur, twat;
  float awat, atur;
  printf("Enter no. of process : ");
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    printf("Burst time for process P%d (in ms) : ", (i + 1));
    scanf("%d", &p[i].btime);
  }
  p[0].wtime = 0;
  for (i = 0; i < n; i++) {
    p[i + 1].wtime = p[i].wtime + p[i].btime;
    p[i].ttime = p[i].wtime + p[i].btime;
  }
  ttur = twat = 0;
  for (i = 0; i < n; i++) {
    ttur += p[i].ttime;
    twat += p[i].wtime;
  }
  awat = (float)twat / n;
  atur = (float)ttur / n;
  printf("\n\nAverage waiting time : %5.2fms", awat);
  printf("\nAverage turn around time : %5.2fms\n", atur);
}
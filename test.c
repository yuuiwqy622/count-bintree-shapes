#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VAL 10
#define ITERS 200

void fill(char name[7]) {
  FILE *in = fopen(name, "w");
  int trees = rand() % 50 + 1, cnt = rand() % 5 + 1;
  fprintf(in, "%d %d\n", trees, cnt);

  while (trees--) {
    for (int i = 1; i < cnt; ++i)
      fprintf(in, "%d ", rand() % MAX_VAL + 1);
    fprintf(in, "%d\n", rand() % MAX_VAL + 1);
  }

  fclose(in);
}

int main(void) {
  srand(time(NULL));
  char name[7];

  for (int i = 3; i < ITERS; ++i) {
    sprintf(name, "%d.in", i);
    fill(name);
  }

  return 0;
}
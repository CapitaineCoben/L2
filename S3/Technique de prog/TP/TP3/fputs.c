#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  FILE *file = NULL;
  int nitems = -1;
  int ret = EOF;
  if (argc != 3) {
    fprintf(stderr, "invalid number of arguments\n");
    return 1;
  }
  file = fopen(argv[1],"w");
  if (file == NULL) {
    fprintf(stderr, "unable to open the file\n");
    return 1;
  }
  nitems = fputs(argv[2], file);
  if (ferror(file)) {
    return 1;
  }
  printf("written: \"%s\" (%lu byte(s))\n", argv[2], strlen(argv[2]));
  ret = fclose(file);
  if (ret == EOF) {
    return 1;
  }
  return 0;
}

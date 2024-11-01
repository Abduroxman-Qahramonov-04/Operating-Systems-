#include "my.h"

void
inputVet (
          int *vet,
          int *dim
          )
{
  int i ;

  fprintf (stdout, "Read Dimension (<100): ");
  scanf ("%d", dim);

  fprintf (stdout, "Read Vector:\n");
  for (i=0; i<(*dim); i++) {
    fprintf (stdout, "vet (%d) = ", i);
    scanf ("%d", &vet[i]);
  }

  return;
}




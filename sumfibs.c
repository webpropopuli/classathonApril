#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int sumFibs(max)
{
int fibs[512] = {0};

fibs[0] = fibs[1] = 1;


int x=1;
  do {
    x++;
     fibs[x] = fibs[x-1] + fibs[x-2];   //add prev 2
  } while (fibs[x] <= max);

int tot=0;
  for(int y=x-1; y>=0; y--)
    tot += (fibs[y] & 1) ? fibs[y] : 0;
  return tot;
}

int main(int argc, char *argv[])
{
    if(argc != 2)
        {
            printf("Need 2 args\n");
            return 0;
        }

    int numMax = atoi(argv[1]);
    int tot = sumFibs(numMax);
    printf("%i\n", tot);
    return tot;
}

/* JS code:

function sumFibs(numMax) {
  var fibs = [1,1];

  var x=1;
  do {
    x++;
     fibs.push(fibs[x-1] + fibs[x-2]);
  } while (fibs[x] <= numMax);

  var tot=0;
  for(y=x-1; y>=0; y--)
    tot += (fibs[y] & 1) ? fibs[y] : 0;
  return tot;
}

sumFibs(4);
*/
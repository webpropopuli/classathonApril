#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

long long factorialize(int i)
{
    long long tot = 1;
    for(int x = 1; x<= i; x++)
        tot *= x;
    return tot;
}
int main(int argc, char *argv[])
{
    if(argc != 2)
        {
            printf("Need 2 args\n");
            return 0;
        }

    long long tot;
    int num = atoi(argv[1]);

    tot = factorialize(num);


    printf("%lld\n", tot);
    return tot;
}

/* JS code:

function factorialize(num) {
  var tot = 1;
  for (x=1; x<=num; x++)
    tot *= x;
  return tot;
}

factorialize(5);

*/
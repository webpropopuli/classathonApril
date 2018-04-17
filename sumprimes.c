#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* isPrime */
int isPrime(int n)
{
  for(int y=2; y<=n/2; y++)
    if ((n % y) == 0)
      return 0;
  return 1;
}


int sumPrimes(max)
{
int tot = 0;

if(max < 4)
  return 0;

for(int x=2; x<=max; x++)
  {
  if(isPrime(x)){
    tot += x;
    }
  }



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
    int tot = sumPrimes(numMax);
    printf("%i\n", tot);
    return tot;
}

/* JS code:

function isPrime(n)
{
  for(y=2; y<=n/2; y++)
    if ((n % y) == 0)
      return false;
  return true;
}

function sumPrimes(numMax) {
var primes = [];

if(numMax <4)
  return 0;

for(x=2; x<=numMax; x++)
  {
  if(isPrime(x) == true){
    primes.push(x);
    //console.log(x);
    }
  }

  //console.log(primes);
return primes.reduce(function (acc, cur) { return (acc + cur);});
}
*/
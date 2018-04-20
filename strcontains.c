#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//debugging stuff
#define DJM
#define TXT_INDEX (int)((pT-&strText[0]))
#define NDX printf("->%d ", TXT_INDEX);

// prolly shouldn't use string.h functions here
int Get_strlen (char *s)
{
    int x=0;
    while (*(s++) != '\0')
    {
        x++;
    }

    return x;
}

int strContains(char *strText, char *strSrch)
{
    char *pT = strText;
    char *pS = strSrch;
    int Matches = 0;

    int lenText = Get_strlen(strText);
    int lenSrch = Get_strlen(strSrch);

    // Errors: Handle 0 len strings and srch string larger than text string.
    if(lenText == 0 || lenSrch == 0 || lenSrch > lenText)
    {
DJM     printf("strContains(): Empty string or srch is larger than text\n");
        return 0;
    }

    char *pT_end = pT + (lenText - lenSrch);    // avoid starting srch on too little remaing text
    while (pT <= pT_end)
    {
        if(Matches > 1) break;  // remove to find ALL matches. Problem only cares about max 2

        static int x;   // counter for search string
        pS = strSrch;   // reset Srch ptr to beginning of strSrch

        while (*pT != *pS)   // find first matching char.
            pT++;

        if(pT > pT_end)     // make sure we didn't go past pT_end
            break;

        for(x = 1; x < lenSrch; x++)    // set to 1 as already matched 1st char
            if(*(++pS) != *(++pT) )     // No match, stop srch
                break;

        // If we didn't break then all chars match. Yay!
        if(x==lenSrch)
            Matches++;

        pT++;   // keep moving through text
    }

    return Matches;
}


int main(int argc, char *argv[])
{
// results text
const char *err_txt[] = {
   "The string does not exist",         // 0
   "The string exists",                 // 1
   "This string is full of the word"    // 2
};

if (argc != 3)
    {
        printf("Wrong number of args\n");
        return 0;
    }

int ret = strContains(argv[1], argv[2]);

printf("%s\n", err_txt[ret]);
return ret;
}

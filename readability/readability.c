#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int main(void)
{
   string text = get_string("Text: ");
   int let = count_letters(text);
   int words = count_words(text);
   int s = count_sentences(text);
   double L = (double)let / words * 100;
   double S = (double) s / words * 100;
   double ans = round(0.0588 * L - 0.296 * S - 15.8);
//    printf("%d %lf %lf\n",let , S, ans);
   if (ans < 1)
       printf("Before Grade 1\n");
   else if(ans >= 16) printf("Grade 16+\n");
   else printf("Grade %i\n",(int)ans);
}

int count_letters(string text)
{
    int res=0;
    for(int i = 0 ; i < strlen(text) ; i++)
    {
        if(isalpha(text[i])) res++;
    }
    return res;
}

int count_words(string text)
{
    int res=0;
    for(int i=0 ; i < strlen(text) ; i++)
    {
        if(text[i] == ' ')
        {
            res++;
        }
    }
    return res+1;
}

int count_sentences(string text){
    int res=0;
    for(int i = 0 ; i < strlen(text) ; i++)
    {
        if(text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            res++;
        }
    }
    return res;
}
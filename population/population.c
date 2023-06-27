#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int n;
    do
    {
        n = get_int("Start size: ");
    }
    while (n < 9);
    // TODO: Prompt for end size
    int endsize;
    do
    {
        endsize = get_int("End size: ");
    }
    while (endsize < n);
    // TODO: Calculate number of years until we reach threshold
    int years = 0;
    while (n < endsize)
    {
        years++;
        int reduce = n / 4;
        int add = n / 3;
        n = n + add - reduce;
    }
    // TODO: Print number of years
    printf("Years: %i\n", years);
}

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef uint8_t BYTE;
const int BLOCK_SIZE = 512;
int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }
    //filename
    char *infile = argv[1];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if(inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 1;
    }

    // read infile into buffer
    BYTE buffer[BLOCK_SIZE];
    // the number of picture
    int cnt=0;
    char name[8];
    FILE *outptr = NULL;
    while (fread(buffer, 1, BLOCK_SIZE, inptr) == BLOCK_SIZE)
    {
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff)
        {
            // 在这里卡了以下我竟然被位运算卡住了
            if((buffer[3] & 0xf0) == 0xe0)
            {
                if(cnt)
                {
                    fclose(outptr);
                }
                // sprintf()函数规范字符串，但是字符串大小一定要可以包括最后的结束符，将规范后的字符串重写如name中
                sprintf(name, "%03i.jpg", cnt++);
                outptr = fopen(name, "w");
            }
        }
        // if条件保证写入时文件一定被打开
        if(cnt) fwrite(buffer, 1, BLOCK_SIZE, outptr);
    }

    fclose(inptr);
    fclose(outptr);
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int copyfile(char *filename1, char *filename2){
    printf("filename1 %s \n", filename1);
    FILE *fp1;
    fp1 = fopen(filename1, "r");
    FILE *fp2;
    fp2 = fopen(filename2, "w");

    char ch;

    if (fp1 == NULL)
    {
        printf("File is not available \n");
        return -1;
    }
    else
    {
        //4
        while ((ch = fgetc(fp1)) != EOF)
        {
            printf("%c\n", ch);
            if (ch >= 'A' && ch <= 'Z')
            {
                char out = (unsigned char)(ch+32);
                printf("out %c\n", out);
                fputc (out, fp2);

            }
            else
            {
                char out = (unsigned char)(ch-32);
                fputc (out, fp2);
            }
        }
    }
    fclose(fp1);
    fclose(fp2);
}

int main(){
    char filename1[] = "file1.txt";
    char filename2[] = "file2.txt";
    copyfile(filename1, filename2);  
    return 0;
}

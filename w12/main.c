#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void areaTot (FILE *fp){

  int matrix[100][100];
  for(int i=0; i<100; i++){
      for(int j=0; j<100; j++){
          matrix[i][j] = 0;
      }
  }

  char buffer1[200]; char buffer2[200]; char buffer3[200]; char buffer4[200];
  int i1;int i2;int i3;int i4;
  fscanf (fp, "%s %s %s %s", buffer1,buffer2, buffer3, buffer4); 
  while (!feof (fp))
    {  
      i1 = atoi (buffer1);i2 = atoi (buffer2);i3 = atoi (buffer3);i4 = atoi (buffer4);
      for(int i=i1; i<i3; i++){
          for(int j=i2; j<i4; j++){
              matrix[i][j] = 1;
          }
      }
      fscanf (fp, "%s %s %s %s", buffer1,buffer2, buffer3, buffer4);      
    }
  fclose (fp);
  i1 = atoi (buffer1);i2 = atoi (buffer2);i3 = atoi (buffer3);i4 = atoi (buffer4);
  for(int i=i1; i<i3; i++){
    for(int j=i2; j<i4; j++){
        matrix[i][j] = 1;
    }
  }

  int sum_value = 0;
  for(int i=0; i<100; i++){
      for(int j=0; j<100; j++){
          sum_value += matrix[i][j];
      }
  }
  
  printf("sum value is %d \n", sum_value);

}


int main(){
//     char buff[200];
//     FILE *fp;
//    fp = fopen("file1.txt", "r");
//    fscanf(fp, "%s", buff);
//    printf("%d\n", atoi(buff) );
//     fscanf(fp, "%s", buff);
//    printf("1 : %s\n", buff );

//    fclose(fp);

    FILE* fp = fopen ("file1.txt", "r");


    areaTot (fp);
    return 0;
}



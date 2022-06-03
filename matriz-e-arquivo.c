#include <stdio.h>
#include <stdlib.h>
main(){
FILE *pArquivo;
pArquivo=fopen("lista.txt","r");
int ag,ge,im,age,weight,matrix[2][4][4];float height,imc;char name[100],gender;
for(int i=0;i<2;i++)for(int j=0;j<4;j++)for(int k=0;k<4;k++)matrix[i][j][k]=0;
while(fscanf(pArquivo,"%s %i %c %f %i",&name,&age,&gender,&height,&weight)!= EOF){
    imc=weight/(height*height);
    // printf("\n %s %i %c %.2f %i  imc= %.2f",name,age,gender,height,weight,imc);
    if(age<18)ag=0;
    else if(age==18)ag=1;
    else if(age==19)ag=2;
    else ag=3;
    if(gender=='F')ge=0;
    else ge=1;
    if(imc<18.5)im=0;
    else if(imc>=18.5&&imc<24)im=1;
    else if(imc>=24&&imc<29)im=2;
    else if(imc>=29)im=3;
    matrix[ge][ag][im]++;}
printf("\n\n\n Minha matriz\n\n");
for(int i=0;i<2;i++)for(int j=0;j<4;j++)for(int k=0;k<4;k++)printf("\n (%i,%i,%i)= %i\n",i,j,k,matrix[i][j][k]);
fclose(pArquivo);}

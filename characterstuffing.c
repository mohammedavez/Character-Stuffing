#include<stdio.h>
#include<conio.h>
#include<string.h>
int main(){
char data[100],result[100],begflag[6]="DLESTX",endflag[6]="DLEETX",unstuff[100];
int resultlength=0,unstufflength=0;
char esc[3]={'E','S','C'},c[100];
int i,length,j,m,n,l=0,k=0,pos;
clrscr();
printf("Enter the length of the data\n");
scanf("%d",&length);
printf("Enter the data:");
scanf("%s",&data);
i=0;
while (data[i])
  {
    c[i]=data[i];
   c[i]=toupper(c[i]);
    i++;
  }
  for(i=0;i<length;i++){
   data[i]=c[i];
  }
resultlength=0;
for(i=0;i<length;i++){
  j=i;
 if(data[i]=='E'){
   if((data[i+1]=='S') && (data[i+2]=='C')){

   result[resultlength]='E';
   result[resultlength+1]='S';
   result[resultlength+2]='C';
   result[resultlength+3]='E';
	 resultlength=resultlength+4;
   }
    else{
   result[resultlength]=data[i];
   resultlength++;
   }
 }
 else if(data[i]=='D'){
       if((data[i+1]=='L' && data[i+2]=='E' && data[i+3]=='S' && data[i+4]=='T' && data[i+5]=='X') || (data[i+1]=='L' && data[i+2]=='E' && data[i+3]=='E' && data[i+4]=='T' && data[i+5]=='X'))
       {
	result[resultlength]='D';
	result[resultlength+1]='L';
	result[resultlength+2]='E';
	if(data[i+3]=='S'){
	result[resultlength+3]='S';
	}else{
	  result[resultlength+3]='E';
	}
	result[resultlength+4]='T';
	result[resultlength+5]='X';
	result[resultlength+6]='D';
	resultlength= resultlength+7;
       }else{
       result[resultlength]=data[i];
       resultlength++;
       }

 }

 else{
 result[resultlength]=data[i];
 resultlength++;
 }
 }
 printf("Data after character stuffing:");
 for(i=0;i<resultlength;i++){
    printf("%c ",result[i]);
    }
     for(m=0;m<6;m++){

     for(n=resultlength-1;n>=m;n--){
       result[n+1]=result[n];
     }
     result[m]= begflag[m];
      resultlength++;
     }
result[resultlength]='D';
result[resultlength+1]='L';
result[resultlength+2]='E';
result[resultlength+3]='E';
result[resultlength+4]='T';
result[resultlength+5]='X';
     resultlength=resultlength+6;
 printf("\nTransmitted Data:");
 for(i=0;i<resultlength;i++){
    printf("%c ",result[i]);
    }
    printf("\nAfter Character Unstuffing:\n");
    printf("Data Recieved:");
 for(i=0;i<resultlength;i++){
    printf("%c ",result[i]);
	}

	for(i=6;i<resultlength-6;i++){
	if(result[i]=='E'){
	if(result[i+1]=='S' && result[i+2]=='C'){
	 unstuff[unstufflength]='E';
	 unstuff[unstufflength+1]='S';
	 unstuff[unstufflength+2]='C';
	 unstufflength=unstufflength+3;
	i=i+5;
	}
	else{
	unstuff[unstufflength]=result[i];
	unstufflength++;
	}
	}
	 else if(result[i]=='D'){
       if((result[i+1]=='L' && result[i+2]=='E' && result[i+3]=='S' && result[i+4]=='T' && result[i+5]=='X') || (result[i+1]=='L' && result[i+2]=='E' && result[i+3]=='E' && result[i+4]=='T' && result[i+5]=='X'))
	{

	unstuff[unstufflength]='D';
	unstuff[unstufflength+1]='L';
	unstuff[unstufflength+2]='E';
	if(result[i+3]=='S'){
	unstuff[unstufflength+3]='S';
	}else{
	  unstuff[unstufflength+3]='E';
	}
	unstuff[unstufflength+4]='T';
	unstuff[unstufflength+5]='X';
	unstufflength= unstufflength+6;
	i=i+11;
       }else{
       unstuff[unstufflength]=result[i];
       unstufflength++;
       }

 }

	else{
	unstuff[unstufflength]=result[i];
	unstufflength++;
	}


	}
	printf("\nData After unstuffing:");
	for(i=0;i<unstufflength;i++){
    printf("%c ",unstuff[i]);
	}
getch();
   return 0;

}

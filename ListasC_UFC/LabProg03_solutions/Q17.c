#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


void troca(char *str){
for(short i = 0 ; i < strlen(str) ; i++){
if(toupper(str[i]) == str[i]) str[i] = tolower(str[i]);
else if(tolower(str[i]) == str[i]) str[i] = toupper(str[i]);
}
}

int ocorrencia(char *str, char ch){
short count = 0;
for(short i =0 ; i < strlen(str) ; i++){
if(str[i] == ch) count++;
}        
return count;                      
}


void titulo(char *str){

str[0] = toupper(str[0]);

for(short i = 1 ; i < strlen(str)-1 ; i++){
if(str[i] == ' ') str[i+1] = toupper(str[i+1]);
}
}

void inverte(char *str1)  
{  
    
    int i, len, temp;  
    len = strlen(str1); 
      
    
    for (i = 0; i < len/2; i++)  
    {  
         
        temp = str1[i];  
        str1[i] = str1[len - i - 1];  
        str1[len - i - 1] = temp;  
    }  
}  


void remove1(char * str, char charToRemmove){
    int i, j;
    int len = strlen(str);
    for(i=0; i<len; i++)
    {
        if(str[i] == charToRemmove)
        {
            for(j=i; j<len; j++)
            {
                str[j] = str[j+1];
            }
            len--;
            i--;
        }
    }
    
}


int main(){

char str[100];
printf("Fill the string!\n");
//scanf("%s" , &str);
fgets(str,100,stdin);
// printf("%s",str);

troca(str);
printf("\n%s\n",&str);

char ch;
printf("\nEscolha um caractere!\n");
scanf("%c" ,&ch);
printf("\nO caractere %c eh repetido %d vezes em %s\n", ch ,ocorrencia(str,ch), str);

titulo(str);
printf("%s",str);

remove1(str, ch);


inverte(str);
printf("%s",str);


return 0;   
}
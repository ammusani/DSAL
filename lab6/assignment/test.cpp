#include<stdio.h> 
#include<string.h>
#include<locale>
/*int main() 
{ 
    const char *str = "12345"; 
    int x; 
    sscanf(str, "%d", &x); 
    printf("\nThe value of x : %d", x); 
    return 0; 
}*/

int main() 
{ 
    char str[] = "123 231 45"; 
  
    // Returns first token  
    char *token = strtok(str, " "); 
    
    // Keep printing tokens while one of the 
    // delimiters present in str[]. 
    while (token != NULL) 
    { 
        //printf("%s\n", token);
        int x;
        sscanf (token, "%d", &x);
        printf("%d\n", x); 
        token = strtok(NULL, " "); 
    } 
  
    return 0; 
} 

/*int main() {
    char s[] = "Ali is great";
    printf("%d", isdigit(s[0]));
    return 0;
}*/
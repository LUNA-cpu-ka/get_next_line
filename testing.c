
#include "get_next_line.h"

// fopen for C language

// int main(){
//     FILE *file = fopen("line.txt", "r");
//     if(file == NULL)
//     {
//         printf("Error on that file");
//         return 1;
//     }
//     char content[BUFFER_SIZE];
//     //fgets is a function (an area it does smt and it return back we it was before :) 
//     //so the function take 3 paramerts the first one (content) is the buffer array whene it stored the line  
//     while (fgets(content, sizeof(content), file)!= NULL)
//     {
//         printf("%s", content);
//     }
//     fclose(file);
// }
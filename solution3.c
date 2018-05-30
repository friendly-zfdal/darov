#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <regex.h>
#define N 100
#define M 10

struct Str_Arr {
char**arr;
int size;
int sizememory;
};

struct Str_Arr* init() {
struct Str_Arr* My_arr = (struct Str_Arr*)malloc(sizeof(struct Str_Arr));
My_arr->arr = (char**)malloc(20 * sizeof(char*));
int i;
for (i = 0; i<20; i++)
My_arr->arr[i] = (char*)malloc(100 * sizeof(char));
My_arr->size = 0;
My_arr->sizememory = 20;
return My_arr;
}

int comporator(const void*str1, const void*str2)
{
if (atoi(*(char**)str1) < atoi(*(char**)str2)) return -1;
if (atoi(*(char**)str1) == atoi(*(char**)str2)) return 0;
if (atoi(*(char**)str1) > atoi(*(char**)str2)) return 1;
}
int ValidFile(char *filename) {
char *regexp = "\\.txt$";
regex_t regexComp;

if (regcomp(&regexComp, regexp, REG_EXTENDED)) {
return 0;
}

return regexec(&regexComp, filename, 0, NULL, 0) == 0;
}

int ValidStr(char*str) {
char*regexp = "^-?[[:digit:]]+ ";
regex_t regexcomp;
if (regcomp(&regexcomp, regexp, REG_EXTENDED))
{
return 0;
}
return regexec(&regexcomp, str, 0, NULL, 0) == 0;

}

void add(char*name, struct Str_Arr *de) {
if (de->size == de->sizememory)
{
de->sizememory = (de->sizememory) + 20;
de->arr = (char**)realloc(de->arr, sizeof(char*)*(de->sizememory));
int i;
for (i = de->size; i< de->sizememory; i++)
{
de->arr[i] = (char*)malloc(sizeof(char)*100);
}
}

strcpy(de->arr[de->size], name);
(de->size)++;

}

void FileTool(char*filename, struct Str_Arr *de) {
char s[100];
FILE*f = fopen(filename, "r");
if (!f)
{
return;
}
fgets(s, 100, f);
if (ValidStr(s))
add(s, de);
fclose(f);

}
void listDir(char *startDir, struct Str_Arr* My_arr) {
char nextDir[200] = {0};
strcpy(nextDir, startDir);
DIR *dir = opendir(startDir);
if (!dir)
return;
struct dirent *de = readdir(dir);
while (de) {
if (de->d_type == DT_DIR && strcmp(de->d_name, ".") != 0 && strcmp(de->d_name, "..") != 0) { 
int length = strlen(nextDir);
strcat(nextDir, "/");
strcat(nextDir, de->d_name);
listDir(nextDir, My_arr);
nextDir[length] = '\0';

}

if (de->d_type == DT_REG && ValidFile(de->d_name)) {
int length = strlen(nextDir);
strcat(nextDir, "/");
strcat(nextDir, de->d_name);
FileTool(nextDir, My_arr);
nextDir[length] = '\0';

}
de = readdir(dir);

}
closedir(dir);
}





int main(int argc, char **argv) {
struct Str_Arr *direct = init();
listDir(".", direct);
qsort(direct->arr, direct->size, sizeof(char**), comporator);
FILE*f = fopen("result.txt", "w");
int i;
for (i = 0; i< direct->size; i++)
fprintf(f, "%s\n", direct->arr[i]);
fclose(f);

for (i = 0; i< direct->sizememory; i++)
free(direct->arr[i]);
free(direct->arr);
free(direct);

return 0;

}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void nodigit(char** str) {
	char* strin = *str;
	char* strout = malloc(20 * sizeof(char));
	int i = 0;
	int j = 0;
	while (strin[i] != '\0')
	{
		if (strin[i] >= '0' && strin[i] <= '9')
			i++;
		else
		{
			strout[j] = strin[i];
			i++;
			j++;
		}
	}

	strout[j] = '\0';
	*str = strout;
}

void strUp(char*str) {
	int i = 0;
	while (*(str + i)) {
		*(str + i) = toupper(*(str + i));
		i++;
	}


}

void StrRev(char *S)
{
	int i, j, l;
	char t;
	l = strlen(S);
	i = 0;
	j = l - 1;
	while (i<j)
	{
		t = S[i];
		S[i] = S[j];
		S[j] = t;
		i++; j--;
	}
}



int main() {
	char* str = malloc(100 * sizeof(char));
	fgets(str,100,stdin);
	
	char** words = malloc(30 * sizeof(char*));
	for (int i = 0; i<30; i++)
		words[i] = malloc(20 * sizeof(char));
	char* istr = malloc(20 * sizeof(char));
	istr = strtok(str, " \n");
	int j = 0;
	while ((istr != NULL) && (istr[0] != '\n')) {			/*–азделение предложени€ на слова и запись в массив*/
		words[j] = malloc(20 * sizeof(char));
		strncpy(words[j], istr, 20);
		j++;
		istr = strtok(NULL, " \n");
	}
	for (int i = 0; i < j; i++) {
		nodigit(&words[i]);
		StrRev(words[i]);
		strUp(words[i]);
		printf("%s ", words[i]);
	}



	return 0;
}
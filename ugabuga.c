#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define ADD 10
struct Dictionary {
	char* key;
	char* value;

};

void make_lower(char **array, int num_words)
{
	int i = 0, j;
	for(i;i<num_words;i++){
		j = 0;
		while (array[i][j] != '\0') {
			array[i][j] = tolower(array[i][j]);
			j++;
		}
	}
}

int main() {
	int size = ADD;
	struct Dictionary* list = malloc(size * sizeof(struct Dictionary));
	char* word1;
	char* word2;
	int i = 0;
	while (1) {
		word1 = malloc(10 * sizeof(char));					/*Запись слов в словрь*/
		scanf("%s", word1);
		if (strcmp(word1,"ugabuga")==0)
			break;
		word2 = malloc(10 * sizeof(char));
		scanf("%s", word2);
		(list+i)->key = word1;
		(list + i)->value = word2;
		i++;
		

	}
	int num_key = i;
	char* sentence = malloc(250 * sizeof(char));
	char*tab = malloc(2 * sizeof(char));				/*Запись предложения*/
	fgets(tab, 2, stdin);
	fgets(sentence, 249, stdin);
	
	char** words = malloc(30 * sizeof(char*));
	for(int i=0;i<30;i++)
	words[i] = malloc(20 * sizeof(char));
	char* istr = malloc(20 * sizeof(char));
	istr = strtok(sentence, " ");
	 int j = 0;
	while ((istr != NULL) && (istr[0] != '\n')) {			/*Разделение предложения на слова и запись в массив*/
		words[j] = malloc(20 * sizeof(char));
		strncpy(words[j], istr, 20);
		j++;
		istr = strtok(NULL, " \n");
	}
	int num_words = j;
	make_lower(words, num_words);





	int flag = 0;
	for (j = 0; j < num_words; j++) {
			for (i = 0; i < num_key; i++) {
			if (strcmp(words[j], (list + i)->key) == 0) {
				printf("%s ", (list + i)->value);
				flag = 1;
			
			}
			
		}
			if (flag == 0)
				printf("<unknown> ");
		flag = 0;

	}


	return 0;
}
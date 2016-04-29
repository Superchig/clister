#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stringarray.h"

int main()
{
	printf("Welcome to superchig's string lister!\n");
	printf("Yes, all this does is take strings and list them.\n");
	printf("Functionality to delete and reorder them is coming soon.\n");
	
	StrArr *list = new_strarr();
	while (1) {
		char* input = malloc(MAX_STRING_LENGTH);
		printf("Input a string> ");
		fgets(input, MAX_STRING_LENGTH, stdin);
		input[strcspn(input, "\n")] = '\0';

		printf("You inputted: %s\n", input);

		int quit = strncmp(input, "quit", MAX_STRING_LENGTH);
		if (quit == 0) {
			break;
		}
		
		add_strarr(list, input);

		printf("---------------------\n");
		printf("List:\n");
		for (int i = 0; i < list->size; ++i) {
			printf("%s\n", get_at_n_strarr(list, i));
		}
	}

	delete_strarr(list);
}

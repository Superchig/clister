#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stringarray.h"
// Currently up to 8 lists. Arbitrary, really.
#define MAX_AMOUNT_LISTS 8

void get_to_str(char *str);

int main()
{
	printf("Welcome to superchig's string lister!\n");
	printf("Yes, all this does is take strings and list them.\n");
	printf("Functionality to delete and reorder them is coming soon.\n");
	printf("Type 'help' for commands.\n");
	
	int amount_lists = 0;
	StrArr *lists[MAX_AMOUNT_LISTS] = {0};
	char *input = malloc(MAX_STRING_LENGTH);
	while (1) {
		printf("Menu> ");
		get_to_str(input);

		if (strncmp(input, "help", MAX_STRING_LENGTH) == 0) {
			printf("add     -- add a string to a list.\n");
			printf("delstr  -- delete a string in a list.\n");
			printf("dellist -- delete a list.\n");
			printf("new     -- create a new list.\n");
			printf("show    -- show all strings in a list.\n");
		} else if (strncmp(input, "add", MAX_STRING_LENGTH) == 0) {
			printf("List> ");
			char *list_name = malloc(MAX_STRING_LENGTH);
			get_to_str(list_name);
			printf("list_name: %s", list_name);
			printf("\n");

			StrArr *list = NULL;
			for (int i = 0; i < amount_lists; ++i) {
				if (strncmp(lists[i]->name, list_name, MAX_STRING_LENGTH) == 0) {
					list = lists[i];
					break;
				}
			}
			free(list_name);

			if (!list) {
				printf("Error: No list was found by that name.\n");
				goto END_OF_LOOP;
			}

			printf("String> ");
			char *string_name = malloc(MAX_STRING_LENGTH);
			get_to_str(string_name);
			printf("\n");
			
			printf("Adding string to list...");
			add_strarr(list, string_name);
			printf("Done.\n");
		} else if (strncmp(input, "new", MAX_STRING_LENGTH) == 0) {
			if (amount_lists + 1 > MAX_AMOUNT_LISTS) {
				printf("Error: There are already %d lists. That is the maximum amount.", MAX_AMOUNT_LISTS);
				goto END_OF_LOOP;
			}

			printf("New list name> ");
			char *list_name = malloc(MAX_STRING_LENGTH);
			get_to_str(list_name);

			printf("Adding new list...");
			StrArr *list = new_strarr();
			list->name = list_name;
			lists[amount_lists++] = list;
			printf("Done.");
		} else if (strncmp(input, "quit", MAX_STRING_LENGTH) == 0) {
			printf("Exiting...\n");
			break;
		} else {
			printf("That is not a valid command.\n");
		}

	  END_OF_LOOP:
		printf("---------------------\n");
		printf("\n\n");
	}

	free(input);
	for (int i = 0; i < amount_lists; ++i) {
		delete_strarr(lists[i]);
		printf("String arrays deleted: %d\n", i);
	}
}

void get_to_str(char *str)
{
	fgets(str, MAX_STRING_LENGTH, stdin);
	str[strcspn(str, "\n")] = '\0';
}

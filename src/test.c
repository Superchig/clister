#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stringarray.h"

int main()
{
	StrArr *list = new_strarr();

	char *string = malloc(MAX_STRING_LENGTH);
	strncpy(string, "Test 1!", MAX_STRING_LENGTH);

	add_strarr(list, string);
	printf("Size of list: %d\n", list->size);
	printf("First item of list: %s\n", get_at_n_strarr(list, 0));

	char *string2 = malloc(MAX_STRING_LENGTH);
	add_strarr(list, string2);

	strncpy(get_at_n_strarr(list, 1), "Test 2!", MAX_STRING_LENGTH);

	printf("Second item of list: %s\n", get_at_n_strarr(list, 1));

	char *string3 = malloc(MAX_STRING_LENGTH);
	strncpy(string3, "Hm... Hopefully, the list size is 3 now.", MAX_STRING_LENGTH);
	add_strarr(list, string3);

	printf("Maximum size of list: %d\n", list->max_size);

	delete_strarr(list);
	
	return 0;
}

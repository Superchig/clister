#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include "stringarray.h"

void die(const char *message)
{
    if(errno) {
        perror(message);
    } else {
        printf("ERROR: %s\n", message);
    }

    exit(1);
}

StrArr *new_strarr()
{
	StrArr* strarr = malloc(sizeof(StrArr));
	if (!strarr) {
		die("Could not allocate memory.");
	}

	strarr->name = NULL;
	strarr->size = 0;
	strarr->max_size = STRARR_DEFAULT_SIZE;

	char **strings = malloc(STRARR_DEFAULT_SIZE * sizeof(char*));
	if (!strings) {
		die("Could not allocate memory.");
	}
	strarr->strings = strings;

	return strarr;
}

void add_strarr(StrArr *self, char *string)
{
	if (self->size + 1 > self->max_size) {
		printf("Doubling maximum list size.\n");
		self->strings = realloc(self->strings, 2 * self->max_size * sizeof(char*));
		self->max_size *= 2;
	}
	
	self->strings[self->size] = string;
	++self->size;
}

char *pop_strarr(StrArr *self)
{
	char *last_item = self->strings[--self->size];
	if (!last_item) {
		die("Last item in string array is not a valid string.");
	}

	return last_item;
}

char *get_at_n_strarr(StrArr *self, int n)
{
	return n > self->max_size - 1 ? NULL : self->strings[n];
}

void delete_at_n_strarr(StrArr *self, int n)
{
	for (; n < self->size - 1; n++) {
		printf("String copied!");
		self->strings[n] = self->strings[n + 1];
	}

	self->strings[--self->size] = NULL;
}

void delete_strarr(StrArr *self)
{
	for (int i = 0; i < self->size; ++i) {
		free(self->strings[i]);
		printf("Strings free'd: %d\n", i + 1);
	}

	free(self->strings);
	if (self->name) {
		free(self->name);
	}
	free(self);
}

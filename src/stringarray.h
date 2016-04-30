#ifndef _strarr_h
#define _strarr_h

#include <stdbool.h>

#define MAX_STRING_LENGTH 256
#define STRARR_DEFAULT_SIZE 2

typedef struct StrArr StrArr;
struct StrArr {
	char **strings;
	char *name;
	int max_size;
	int size;
};

StrArr *new_strarr();
void add_strarr(StrArr *self, char *string);
char *pop_strarr(StrArr *self);
char *get_at_n_strarr(StrArr *self, int n);
void delete_at_n_strarr(StrArr *self, int n);
void delete_strarr(StrArr *self);

#endif

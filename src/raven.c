#include "raven.h"
#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
static void skip_white_space(const char** p)
{
	while (isspace(**p)) (*p)++;
};

// Parse the raw string from json and make a new string that do all escaping, number encoding,...
static char* extract_string(const char* str)
{
	const char* current = str;
	skip_white_space(&current);
	assert(*current == '"');

	current++;
	int length = 0;
	int capacity = 8;
	char* rs = malloc(capacity);
	while (*current != '\0' && *current != '"')
	{
		if (length + 1 > capacity)
		{
			capacity *= 2;
			rs = realloc(rs, capacity);
		};

		if (*current == '\\')
		{
			current++;

			switch (*current)
			{
				case '"': rs[length++] = '"'; break;
				case '\\': rs[length++] = '\\'; break;
				case '/': rs[length++] = '/'; break;
				case 'b': rs[length++] = '\b'; break;
				case 'f': rs[length++] = '\f'; break;
				case 'n': rs[length++] = '\n'; break;
				case 'r': rs[length++] = '\r'; break;
				case 't': rs[length++] = '\t'; break;
				case 'u':
					//TODO : Do unicode parsing
					break;
				default: fprintf(stderr, "invalid escape sequence \\%c\n", *current); break;
			};
		}
		else {rs[length++] = *current;};
		printf("%c,", *current);
		current++;
	};

	if (*current != '"')
	{
		fprintf(stderr, "Unterminated string %s\n", str);
		free(rs);
		return nullptr;
	};

	rs[length] = '\0';
	return rs;
};

//static bool is_string_quoted(const char* str, uint32_t length)
//{
//	int string_length = strlen(str);
//	assert(length <= string_length);
//	if (length > 0) then
//	{
//		return str[0] == '"' && str[string_length] == '"'
//	}
//	else return str[0] == '"' && str[length] == '"';
//};

static void parse_object(const char* obj)
{
	assert(obj[0] == '{');
	const char* current = &obj[1];
	skip_white_space(&current);

	assert(current == '"');
	int count = 0;
	// Key

	// Value
};
static void parse_number();
static void parse_string();
static void parse_array();

static void parse_value(RAVEN_VALUE_TYPE type)
{
};

static void recursive_parse(const char* content, RavenNode* node)
{

};
void raven_parse_json(const char* content, RavenNode* node)
{
	assert(content[0] == '{' || content[0] == '[');
};

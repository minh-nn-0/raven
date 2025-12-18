#include "raven.h"
#include <assert.h>
#include <ctypes.h>
static void skip_white_space(char** p)
{
	while (isspace(**p)) (*p)++;
};

static void parse_object();
static void parse_number();
static void parse_string();
static void parse_array();

static void parse_value(RAVEN_VALUE_TYPE type)
{
};

static void recursive_parse(const char* content, RavenNode* node)
{

};
void raven_parse(const char* content, RavenNode* node)
{
	assert(content[0] == '{' || content[0] == '[');
};

#pragma once

typedef enum
{
	RV_STRING, RV_NUMBER, RV_BOOL, RV_OBJECT, RV_ARRAY
} RAVEN_VALUE_TYPE;

typedef struct
{
	RAVEN_VALUE_TYPE _type;
	union
	{
		bool _bool;
		double _number;
		char* _string;

		struct
		{
			size_t _count;
			struct
			{
				char* _key;
				RavenNode* _value; 
			}* _pairs;
		} _object;

		struct {size_t _size; RavenNode* _data} _array;

		char * _name;
	} _data;
} RavenNode;

void raven_parse_json(const char* content, RavenNode* node);
void raven_free(RavenNode* node);

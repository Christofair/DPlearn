#include "Context.hpp"

#ifndef PARSER_HPP
#define PARSER_HPP

struct Parser
{
	Parser() = default;
	int parse(Context*);
};
struct Operation
{
	virtual int exec(int,int) = 0;
};
struct Add : Operation
{
	int exec(int,int);
};
struct Min : Operation
{
	int exec(int,int);
};


#endif //PARSER_HPP



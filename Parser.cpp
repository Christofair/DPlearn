#include "Parser.hpp"
#include "Context.hpp"
#include <algorithm>

int Parser::parse(Context *context)
{
	int total = 0;
	Operation *op;
	int sum = 0;

#define rc(t) Rchars::t
	auto unit = [](Rchars r){ return (r == rc(I) || r == rc(V)) ? true : false; };
	auto dozen = [](Rchars r) { return (r == rc(X) || r == rc(L)) ? true : false; };
	auto hunner = [](Rchars r) { return (r == rc(C) || r == rc(D)) ? true : false; };

	Rchars p = rc(UNDEF);

#define con context->content
#define sc(t) static_cast<int>(t)

	std::reverse(con.begin(), con.end());
	for(auto c : con)
	{
		if(p)
		{
			if(sc(p) <= sc(c)) op = new Add();
			else
			{
				//It's maybe be okay to all case
				if(total-sc(p) >= sc(c)) throw("error on record"); 
			       	op = new Min();
			}
		}
		else op = new Add();
		p=c;
		total = op->exec(total, sc(c));
		delete op;
	}

	return total;
}

Add::exec(int a, int b) { return a+b; };
Min::exec(int a, int b) { return a-b; };

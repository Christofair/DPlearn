#ifndef CONTEXT_HPP
#define CONTEXT_HPP

#include <string>
#include <vector>
#include "Rchars.h"
using namespace std;


struct Context
{
	vector<Rchars> content;
	Context(string);
	Context();
	public:
		bool ruleOne(string&);
		bool ruleTwo(string&);
		bool ruleThree(string&);
		bool ruleFour(string&);
		bool validate(string&);
		bool validSYN(string&);
		void loadContent(string&);
};

#endif //CONTEXT_HPP

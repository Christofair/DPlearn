#include <string>
#include "Context.hpp"

using namespace std;


/**
 * param string to validate and load
 * throws string
 * */
Context::Context(string s)
{
	content.clear();
	if(validate(s)) loadContent(s);
	else throw("That string not pass a validation, I'm so sorry :/");
}
Context::Context()
{
	content.clear();
}


bool Context::validSYN(string &s)
{
	for(char elem : s)
	{
		if(
			elem != 'X' &&
			elem != 'I' &&
			elem != 'V' &&
			elem != 'D' &&
			elem != 'C' &&
			elem != 'M' &&
			elem != 'L'
		  ) return false;
	}
	return true;
}

bool Context::ruleOne(string& s)
{
	int8_t I,X,C,M;
	I=X=C=M=0;
	char p='\0';
	for(char i : s)
	{
		if(i == 'I' && p == 'I') { I++; X=C=M=0; }
		else if(i == 'X' && p == 'X') { X++; I=C=M=0; }
		else if(i == 'C' && p == 'C') { C++; I=X=M=0; }
		else if(i == 'M' && p == 'M') { M++; I=X=C=0; }
		else { I=X=C=M=0; }
		if(X==3 || I == 3 || C == 3 || M == 3) return false;
		p=i;
	}
	return true;
}

bool Context::ruleTwo(string &s)
{
	char p='\0';
	for(char i : s)
	{
		if(p == i) if(i == 'V' || i=='L' || i=='D') return false;
		p=i;
	}
	return true;
}

#define len(t) t.length()
#define rchv(t) rcharValue(t)
bool Context::ruleThree(string &s)
{
	for(int i=0; i <= len(s) - 3; i++)
	{
		for(int j=i+2; j <= len(s) - 1; j++)
		{
			if(
				rchv(s[i]) < rchv(s[j]) &&
				rchv(s[i+1]) < rchv(s[j])
			) return false;
		}
	}
	return true;
}

bool Context::ruleFour(string &s)
{
	for(int i=0; i <= len(s) - 2; i++)
	{
		for(int j=i+1; j <= len(s) - 1; j++)
		{
			if(rchv(s[j]) > rchv(s[i]))
			{
				if(! (s[i]=='X' || s[i]=='I' || s[i]=='C'))
					return false;
			}
		}
	}
	return true;
}
#undef len
#undef rchv

bool Context::validate(string &s)
{
	if(! ruleOne(s)) return false;
	else if(! validSYN(s)) return false;
	else if(! ruleTwo(s)) return false;
	else if(! ruleThree(s)) return false;
	else if(! ruleFour(s)) return false;
	else return true;
}

void Context::loadContent(string &s)
{
    for(char c : s) content.push_back(rcharParser(c));
}

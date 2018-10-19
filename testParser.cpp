#include <iostream>
using namespace std;

#include "Parser.hpp"
#include "Context.hpp"


void test_case_parse()
{
	string test_case[] = {
		"XXIX", 
		"MMIM", 
		"MIM", 
		"CMIX", 
		"XMIX",
		"VIII", 
		"XVII",
		"XXIVI"	
	};
	int results[] = {29, 2999, 1999, 909, 999, 8, 17,0};
	Context *con;
	int suma =0;
	try{
	Parser *p = new Parser();
	for(int i =0; i<8;i++)
	{
		con = new Context(test_case[i]);
		suma = p->parse(con);
		if( (suma == results[i]) )
		{
			cout << "[ "<< test_case[i] << " ] PASS" << endl;
		}
		else cout << "[ " << test_case[i] << " ] FAIL" << endl;
			cout << suma << endl;
		delete con;
	}
	}
	catch(const char* str)
	{
		cout << str <<endl;
	}
}

int main()
{
	 test_case_parse();
	return 0;
}

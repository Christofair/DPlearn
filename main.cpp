#include <iostream>
#include "Parser.hpp"
#include "Context.hpp"


using namespace std;

int main()
{
	Context *context;
	Parser *parser = new Parser;
	string to_parse;
	cout << "podaj liczbe w rzymskim: ";
	cin >> to_parse;
	int result = 0;
	try
	{
		context = new Context(to_parse);
		result = parser->parse(context);
		cout << "The number in arabic notation is: " << result << endl;
	}
	catch(const char* s)
	{
		cout << s << endl;
		exit(0);
	}

	return 0;
}

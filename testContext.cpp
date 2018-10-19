#include <iostream>
#include "Context.hpp"
#include "Rchars.h"

using namespace std;

void test_case_validSYN()  
{

	Context con;
	string test_case[] = {
		"CMXL",
		"XXX",
		"AIXMC",
		"SUCK"
	};
	cout <<endl<< "test case validSYN START" << endl;

	for(string i : test_case)
	{
		if(con.validSYN(i)) cout << "[ "<<i<<" ] PASS" << endl;
		else cout << "[ " << i << " ] FAIL " << endl;
	}
	cout << "test case validSYN END" << endl;
}

void test_case_rule1()
{
	Context con;
	string test_case[] = {
		"IIICCDLLXX",
		"XXCLMCCC",
		"CXIVI",
		"XLIIII",
		"CCXCLLLIIIXXXX",
		"IIIICCDLLXX",
		"CCCM",
		"XXDDMMCCCCLDII",
		"XXXXXXXXXXXXXXXXVI",
		"MMXCCCXXMMMMI"
	};
	cout <<endl<< "test case ruleOne START" << endl;
	for(string i : test_case)
	{
		if(con.ruleOne(i)) cout << "[ "<<i<<" ] PASS" << endl;
		else cout << "[ " << i << " ] FAIL " << endl;
	}
	cout << "test case ruleOne END" << endl;
}

void test_case_rule2()
{
	Context con;
	string test_case[] = {
		"VVIXXD",
		"LDXVLLI",
		"XXXDDI",
		"CCCLLD",
		"IIII",
		"VL",
		"LV"
	};
	cout <<endl<< "test case ruleTWO START" << endl;
	for(string i : test_case)
	{
		if(con.ruleTwo(i)) cout << "[ "<<i<<" ] PASS" << endl;
		else cout << "[ " << i << " ] FAIL " << endl;
	}
	cout << "test case ruleTWO END" << endl;
}

void test_case_rule3()
{
	Context con;
	string test_case[] = {
		"IIM",
		"XXMXDC",
		"CDLLMVI",
		"CMXVI",
		"XXXXXXXXVI"
	};
	cout <<endl<< "test case ruleThree START" << endl;
	for(string i : test_case)
	{
		if(con.ruleThree(i)) cout << "[ "<<i<<" ] PASS" << endl;
		else cout << "[ " << i << " ] FAIL " << endl;
	}
	cout << "test case ruleThree END" << endl;
}

void test_case_rule4()
{
	Context con;
	string test_case[] = {
		"CDIL",
		"XXIVI",
		"DMVI",
		"CCCDXXMIIIL",
		"XIXVI",
		"IIXDCCM"
	};
	cout <<endl<< "test case ruleFour START" << endl;
	for(string i : test_case)
	{
		if(con.ruleFour(i)) cout << "[ "<<i<<" ] PASS" << endl;
		else cout << "[ " << i << " ] FAIL " << endl;
	}
	cout << "test case ruleFour END" << endl;
}
void test_case_validate()
{
	Context con;
	string test_case[] = {
		"CDIL",
		"XXIVI",
		"DMVI",
		"CCCDXXMIIIL",
		"XIXVI",
		"IIXDCCM",
		"IIM",
		"XXMXDC",
		"CDLLMVI",
		"CMXVI",
		"XXXXXXXXVI",
		"VVIXXD",
		"LDXVLLI",
		"XXXDDI",
		"CCCLLD",
		"IIII",
		"IIICCDLLXX",
		"XXCLMCCC",
		"CXIVI",
		"XLIIII",
		"CCXCLLLIIIXXXX",
		"IIIICCDLLXX",
		"CCCM",
		"XXDDMMCCCCLDII",
		"MIM",
		"MMMIM"
	};

	cout <<endl<< "test case validate START" << endl;
	for(string i : test_case)
	{
		if(con.validate(i)) cout << "[ "<<i<<" ] PASS" << endl;
		else cout << "[ " << i << " ] FAIL " << endl;
	}

	cout << "test case validate END" << endl;
}

#define rc(t) Rchars::t

bool checkContent(vector<Rchars> content, string &s)
{
	for(int i=0; i< content.size(); i++)
	{
		if(s[i] == 'M' && content.at(i) == rc(M));
		else if(s[i] =='D' && content.at(i) == rc(D));
		else if(s[i] =='C' && content.at(i) == rc(C));
		else if(s[i] =='L' && content.at(i) == rc(L));
		else if(s[i] =='X' && content.at(i) == rc(X));
		else if(s[i] =='V' && content.at(i) == rc(V));
		else if(s[i] =='I' && content.at(i) == rc(I));
		else return false;
	}
	system("pause");
	return true;
}

void test_case_loadContent()
{
	string test_case[] = {
		"CDIL",
		"XXIVI",
		"DMVI",
		"CCCDXXMIIIL",
		"XIXVI",
		"IIXDCCM",
		"IIM",
		"XXMXDC",
		"CDLLMVI",
		"CMXVI",
		"XXXXXXXXVI",
		"VVIXXD",
		"LDXVLLI",
		"XXXDDI",
		"CCCLLD",
		"IIII",
		"IIICCDLLXX",
		"XXCLMCCC",
		"CXIVI",
		"XLIIII",
		"CCXCLLLIIIXXXX",
		"IIIICCDLLXX",
		"CCCM",
		"XXDDMMCCCCLDII",
		"MIM",
		"MMMIM"
	};
	Context *con;

	cout <<endl<< "test case validate START" << endl;
	for(string i : test_case)
	{
		con = new Context();
		con->loadContent(i);
		if(checkContent(con->content, i))
			cout << "[ "<<i<<" ] PASS" << endl;
		else cout << "[ " << i << " ] FAIL " << endl;
		delete con;

	}

	cout << "test case validate END" << endl;

}

int main()
{
//   	test_case_validSYN(); check! :D
//  	test_case_rule1(); check! :D
//  	test_case_rule2(); check! :D
//   	test_case_rule3(); check! :D
//   	test_case_rule4(); check! :D
//   	test_case_validate(); check! :D
//	test_case_loadContent(); check! :D

	return 0;
}

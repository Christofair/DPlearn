#include "Rchars.h"

#define RC(t) Rchars::t
int rcharValue(char c)
{
	Rchars rchar;
	switch(c)
	{
		case 'I': rchar = RC(I); break;
		case 'V': rchar = RC(V); break;
		case 'X': rchar = RC(X); break;
		case 'L': rchar = RC(L); break;
		case 'C': rchar = RC(C); break;
		case 'D': rchar = RC(D); break;
		case 'M': rchar = RC(M); break;
	}
	return static_cast<int>(rchar);
}
Rchars rcharParser(char c)
{
    Rchars rchar;
    switch(c)
    {
        case 'I': rchar = RC(I); break;
	case 'V': rchar = RC(V); break;
	case 'X': rchar = RC(X); break;
	case 'L': rchar = RC(L); break;
	case 'C': rchar = RC(C); break;
	case 'D': rchar = RC(D); break;
	case 'M': rchar = RC(M); break;
    }
    return rchar;
}
#undef RC

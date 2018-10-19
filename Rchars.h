#ifndef RCHARS_H
#define RCHARS_H
enum Rchars
{
	I=1,
	V=5,
	X=10,
	L=50,
	C=100,
	D=500,
	M=1000,
	UNDEF=0
};
int rcharValue(char);
Rchars rcharParser(char);

#endif //RCHARS_H

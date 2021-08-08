#include<iostream>
#include<Math.h>
#include<string.h>
using namespace std;

char doichar (int n)
{
	return (char)(n+48);
}

string FloatToString(float s)
{
	int x;
	int nguyen = (int)s;
	cout<<"Nguyen: "<<nguyen<<endl;
	float du = (s - (int)s) * 10;
	string p;
	while(nguyen >= 10)
	{
		x = nguyen%10;
		p.insert(0,1,doichar(x));
		nguyen = nguyen/10;
	}
	p.insert(0,1,doichar(nguyen));
	p.insert(p.length(),1,'.');
	for(int i = 0; i < 2; i++){
		int duNguyen = (int)du;
		p.insert(p.length(),1,doichar(duNguyen));
		du = (du - duNguyen) * 10;
	}
	return p;
}

int main()
{
	
	float a = 9;
	cout<<FloatToString(a);
	return 0;
}

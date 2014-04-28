#include <iostream>
#include <algorithm>
#include <ginac/ginac.h>
using namespace std;
using namespace GiNaC;

int main()
{
	int rank[16];
	int points;
	ex pointdist[38];
	for(int c=0;c<38;c++)
		pointdist[c]=0;
	for(int c=0;c<16;)
	{
		for(int d=1;d<5;d++)
		{
			rank[c]=d;
			c++;
		}
	}
	bool selector[16];
	for(int c=0;c<13;c++)
		selector[c]=true;
	for(int c=13;c<16;c++)
		selector[c]=false;
	for(numeric deselected=0;deselected<14;deselected++)
	{
		sort(selector,selector+16);
		do
		{
			points=0;
			for(int c=0;c<16;c++)
			{
				if(selector[c])
					points+=rank[c];
			}
			pointdist[points]+=binomial(36,deselected);
		}
		while(next_permutation(selector,selector+16));
		for(int c=0;c<16;c++)
		{
			if(selector[c])
			{
				selector[c]=false;
				break;
			}
		}
	}
	for(int c=0;c<38;c++)
		cout << c << "\t" << pointdist[c] << endl;	
}

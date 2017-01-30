#include <cstdio>
#include <iostream>
#include "Card.h"
using namespace std;

int main()
{
	Card mySpade(7, 1);
	Card myHeart(6, 2);
	Card myDiamond(3, 3);
	Card myClub(10, 3);

	cout << mySpade.draw()[1] << endl;

    return 0;
}
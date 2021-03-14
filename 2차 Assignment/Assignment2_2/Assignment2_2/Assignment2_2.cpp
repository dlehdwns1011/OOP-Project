#include <iostream>

using namespace std;

void militaryTimeAdd(int* pHour, int* pMin, int* pSec, int addHour, int addMin, int addSec);
//declare function
int main()
{//start main
	int h[1], m[1],s[1];
	int h2, m2, s2; //declare values
	cout << "input  time" << endl;
	cout << "h: "; cin >> *h;
	if (*h < 0 || *h > 23)
	{//input format
		cout << "Input Error";
		return 0;
	}
	cout << "m: "; cin >> *m;
	if (*m < 0 || *m > 59)
	{//input format
		cout << "Input Error";
		return 0;
	}
	cout << "s: "; cin >> *s; //input time and store each value
	if (*s < 0 || *s > 59)
	{//input format
		cout << "Input Error";
		return 0;
	}
	cout << "add time" << endl;
	cout << "h: "; cin >> h2;
	if (h2 < 0 || h2 > 100000)
	{//input format
		cout << "Input Error";
		return 0;
	}
	cout << "m: "; cin >> m2;
	if (m2 < 0 || m2 > 100000)
	{//input format
		cout << "Input Error";
		return 0;
	}
	cout << "s: "; cin >> s2; //input add time and store each value
	if (s2 < 0 || s2 > 100000)
	{//input format
		cout << "Input Error";
		return 0;
	}

	militaryTimeAdd(h, m, s, h2, m2, s2); //go to function
	cout << "output time" << endl; //print output
	cout << "h: " << *h << " m: " << *m << " s: " << *s;

	return 0;
}

void militaryTimeAdd(int* pHour, int* pMin, int* pSec, int addHour, int addMin, int addSec)
{//function of addition times
	if(addSec >= 60)
	{//if need to change sec to min of add time
		addMin += addSec/60;
		addSec = addSec % 60;
	}
	if(addMin >= 60)
	{//if need to change min to hour of add time
		addHour += addMin/60;
		addMin = addMin % 60;
	}
	*pSec += addSec; //addition 2 secs
	if (*pSec >= 60)
	{//if need to change sec to min of sec of 2 times
		*pSec -= 60;
		pMin[0]++;
	}
	*pMin += addMin; //addition 2 mins
	if (*pMin >= 60)
	{//if need to change min to hour of min of 2 times
		*pMin -= 60;
		pHour[0]++;
	}
	*pHour += addHour; //addtion 2 hours
	if (*pHour >= 24)
		*pHour %= 24;
}
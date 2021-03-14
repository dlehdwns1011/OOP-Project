#include <iostream>
#include <fstream>

using namespace std;

void caesarEncryption(ifstream& inFile, ofstream& outFile, int nCaesar = 3);
//declare function
int main()
{//start main
	ifstream fin; //declare input file 
	ofstream fout;//declare output file
	fin.open("Diary_15yearsOld.txt");//open input file
	if (fin.fail())
	{
		cout << "Not exist read file";
		return 0;
	}
	fout.open("Diary_15yearsOld_encryption.txt");//open output file
	int n = 0;

	cout << "Input the shift number : ";
	cin >> n;//input nCaesar
	if (n < 0 || n > 26)//input Error : range of nCaesar
		cout << "input Error!";
	else
		caesarEncryption(fin, fout, n);//function of caesarEncryption

	fin.close();
	fout.close();//close file
	return 0; //end main
}

void caesarEncryption(ifstream& inFile, ofstream& outFile, int nCaesar)
{//function of caesarEncryption
	char line[255]; //declare char
	while (inFile.getline(line, 255))
	{//get 1 line from first line to end line
		for (int i = 0; line[i] != NULL; i++)
		{//shift alphavet by changing int value
			int c = (int)line[i]; //make int
			c += nCaesar; //shift
			line[i] = c; //application
		}
		outFile << line; //print changed line in output file 
		cout << line;
	}

}
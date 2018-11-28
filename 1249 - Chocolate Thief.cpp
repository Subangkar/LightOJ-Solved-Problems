#include <iostream>

using namespace std;


void strCopy(char *dest,const char *src)
{
    while(*dest++ = *src++);

    *dest = '\0'; /// Terminating The Copied String
}


int main()
{
	int testCase = 0;
    int testCaseCounter = 1;

	cin >> testCase;

    char *thiefName = NULL , *victimName = NULL , *thisName=NULL;
    int thiefVolm=0 , victimVolm = +99999999999 , thisVolm=0; /// thiefVolm=max   victimVolm=min
    int l=0,d=0,t=0;

    int totalStudent=0;
    int studentNo=1;

	while (testCaseCounter <= testCase)
	{
	    cin>>totalStudent;

	    studentNo=1;
	    thiefName = new char[21] ;
	    victimName = new char[21] ;

        while(studentNo<=totalStudent)
        {
            thisName = new char[21];

            cin>>thisName>>l>>d>>t;
            thisVolm = l*d*t;

            if(thisVolm>thiefVolm)
            {
                thiefVolm = thisVolm;

                strCopy(thiefName,thisName);
            }

            if(thisVolm<victimVolm)
            {
                victimVolm = thisVolm;

                strCopy(victimName,thisName);
            }

            delete[] thisName;

            studentNo++;
        }

        if(thiefVolm==victimVolm) cout<<"Case "<<testCaseCounter<<": "<<"no thief"<<endl;

        else cout<<"Case "<<testCaseCounter<<": "<<thiefName<<" took chocolate from "<<victimName<<endl;

        delete[] thiefName,victimName;
        thiefVolm=0 , victimVolm = +99999999999;

		testCaseCounter++;
	}

	return 0;
}
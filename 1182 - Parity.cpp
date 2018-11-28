#include <iostream>

using namespace std;

size_t patityBitCounter(int number)
{
    size_t parityBits = 0;

    while(number)
    {
        parityBits += (number & 1 );
        number >>= 1;
    }

    return parityBits;
}

int main()
{
    int testCase=0,counter=0;
    int number=0;

    cin>>testCase;

    while(counter++ < testCase)
    {
        cin>>number;

        cout<<"Case "<< counter <<": "<< ( (patityBitCounter(number) & 1) ? "odd" : "even" ) << endl;
    }

    return 0;
}
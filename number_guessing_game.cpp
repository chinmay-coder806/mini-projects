#include <iostream>
#include <cstdlib>  // for rand() and srand()
#include <ctime>    // for time()
using namespace std;

//selecting random number
int main()
{
    //gpt 
    
    srand(time(0)); // Seed random number generator

    int j = rand() % 100 + 1; // random number between 1 and 100
    // c
    int guess;
    int i;
    cout <<"A number between 1 to 100 is selected , try to guess it\n";
    int tries =0;
    
    while(1){
    
        cin >> i ;
    if (j>i && i>1)
    {
        cout<< "too low guess heigher\n";
        tries++;
    }else if (j<i && i<100)
    {
        cout<<"too high guess lower\n";
        tries++;
    }else if (i == j)
    {
        cout<<"Congratulations the number was :"<< j<<endl;
        cout<<"no of tries:"<<tries;
        return 0;
    }else{
        cout << "invlid guess between 1 to 100\n";
    }
    
}
    
}
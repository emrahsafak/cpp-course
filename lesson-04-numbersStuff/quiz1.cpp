#include <iostream>
using namespace std;

int main() 
{    
    int x = 11;
    int y = x--;
    int z = 2 * y--;
    cout << "z: " << z << endl;    
    
    return 0;
}

// Answer = 22 

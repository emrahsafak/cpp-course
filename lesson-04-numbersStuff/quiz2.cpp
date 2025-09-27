include <iostream>
using namespace std;

int main() 
{ 
    int x = 11;
    int y = x--;
    int z = 5 + --y;
    cout << "x: " << x << " y: " << y << " z: " << z << endl;
    
    return 0;
}

// x=10 , y=10 , z=15

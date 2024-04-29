#include <iostream>
using namespace std;
float area(float r) {
    const float PI = 3.14;
    return PI * r * r;
}
int main(){
    double r;
    cout << "Enter Radius: ";
    cin >> r;
    cout << "Area is: " << area(r) << endl;
    return 0;
}
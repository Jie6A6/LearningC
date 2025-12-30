#include <iostream>
using namespace std;

int main(){

    
    int arr[2][3] = 
    {
        {5, 2, 3},
        {7, 5, 6}
    };
    
    cout << "数组所占的内存空间：" << sizeof(arr) << endl;
    cout << "数组元素所占的内存空间：" << sizeof(arr[0][0]) << endl;
   
    
    system("pause");

    return 0;
}
#include <iostream>
using namespace std;

int main(){

    
    int arr[2][3] = 
    {
        {5, 2, 3},
        {7, 5, 6}
    };
    
    cout << "数组所占的内存空间：" << sizeof(arr) << endl;
    cout << "数组一行元素所占的内存空间：" << sizeof(arr[0]) << endl;
    cout << "数组元素所占的内存空间：" << sizeof(arr[0][0]) << endl;
    cout << "数组行数：" << sizeof(arr) / sizeof(arr[0]) << endl;
    
    cout << "数组的首地址：" << arr << endl;
    cout << "数组第一行的首地址：" << arr[0] << endl;
    cout << "数组第一元素的首地址：" << &arr[0][0] << endl;

    system("pause");

    return 0;
}
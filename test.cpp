#include <iostream>
using namespace std;
#include <string>


// 英雄结构体定义

struct hero
{
    string name;
    int age;
    string gender;
};


// 赋值函数
void bubbleSort(struct hero arr[], int len)
{

    
    // 给老师赋值
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - 1 - i; j++)
        {
            if (arr[j].age > arr[j + 1].age)
            {
                struct hero temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }

    }
}

void printInfo(struct hero arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << arr[i].name 
             << arr[i].age << endl;
    }
}

int main(){

    // 创建英雄数组
    struct hero arr[5] = 
    {
        {"刘备", 23, "男"},
        {"关羽", 22, "男"},
        {"张飞", 23, "男"},
        {"赵云", 21, "男"},
        {"貂蝉", 19, "女"}
    };

    int len = sizeof(arr) / sizeof(arr[0]);

    bubbleSort(arr, len);

    printInfo(arr, len);

    system("pause");

    return 0;

}
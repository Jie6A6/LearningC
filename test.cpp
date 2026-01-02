#include <iostream>
using namespace std;
#include <string>

// 学生结构体定义

struct Student
{
    string name;
    int age;
    int score;
};

// const 使用场景
void printStudent(const Student * stu) // 加 const 防止函数体中的误操作
{
    // stu->score = 50; // 操作失败，因为加了 const 操作
    cout << "子函数中 姓名：" << stu->name
         << " 年龄：" << stu->age
         << " 分数：" << stu->score << endl;
}


int main(){

    Student stu;
    stu.name = "张三";
    stu.age = 18;
    stu.score = 100;

    printStudent(&stu);

    system("pause");

    return 0;

}
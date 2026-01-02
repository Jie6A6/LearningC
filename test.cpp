#include <iostream>
using namespace std;
#include <string>
#include <ctime>

// 学生结构体定义

struct Student
{
    string sName;
    int score;
};

// 老师结构体定义

struct Teacher
{
    string tName;
    struct Student sArray[5];
};

// 赋值函数
void allocateSpace(struct Teacher tArray[], int len)
{

    string nameSeed = "ABCDE";
    // 给老师赋值
    for (int i = 0; i < len; i++)
    {
        tArray[i].tName = "Teacher_";
        tArray[i].tName += nameSeed[i];

        // 通过循环给每一名老师所带学生赋值
        for (int j = 0; j < 5; j++)
        {
            tArray[i].sArray[j].sName = "Student_";
            tArray[i].sArray[j].sName += nameSeed[j];

            int random = rand() % 61 +40; // 40 ~ 100
            tArray[i].sArray[j].score = random;
        }

    }
}

void printInfo(struct Teacher tArray[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << "老师姓名：" << tArray[i].tName << endl;

        for (int j = 0; j < 5; j++)
        {
            cout << "\t学生姓名：" << tArray[i].sArray[j].sName
                 << " 学生成绩：" << tArray[i].sArray[j].score << endl;
        }
    }
}

int main(){

    srand((unsigned int)time(NULL));

    // 创建 3 名老师的数组
    struct Teacher tArray[3];

    // 给老师和学生信息赋值
    int len = sizeof(tArray) / sizeof(tArray[0]);
    allocateSpace(tArray, len);

    // 打印信息
    printInfo(tArray, len);

    system("pause");

    return 0;

}
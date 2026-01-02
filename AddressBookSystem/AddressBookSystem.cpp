// 封装函数显示该界面，如 `void showMenu()`
// 在 main 函数中调用封装好的函数

#include <iostream>
using namespace std;
#include <string>
#define Max 1000 // 最大人数宏常量


// 联系人结构体
struct Person
{
    string m_Name; // 姓名
    int m_Gender; // 性别
    int m_Age; // 年龄
    string m_Phone; // 电话
    string m_Addr; // 住址
};


// 通讯录结构体
struct Addressbooks
{
    struct Person personArray[Max]; // 通讯录中保存的联系人数据
    int m_Size; // 通讯录中当前人员个数
};


// 1. 添加联系人
void addPerson(Addressbooks * abs)
{
    // 判断通讯录是否已满
    if (abs->m_Size == Max)
    {
        cout << "通讯录已满，无法添加！！！" << endl;
        return;
    }
    else
    {
        // 添加姓名
        string name;
        cout << "请输入姓名：" << endl;
        cin >> name;
        abs->personArray[abs->m_Size].m_Name = name;

        // 性别
        cout << "请输入性别：" << endl;
        cout << "1 --- 男" << endl;
        cout << "2 --- 女" << endl;
        int gen = 0;

        while (true) // 如果输入1/2退出循环，输入有误重新输入
        {
            cin >> gen;
            if (gen == 1 || gen == 2)
            {
                abs->personArray[abs->m_Size].m_Gender = gen;
                break;
            }
            else
            {
                cout << "输入有误，请重新输入！！！" << endl;
            }
        }

        // 年龄
        cout << "请输入年龄：" << endl;
        int age = 0;
        cin >> age;
        abs->personArray[abs->m_Size].m_Age = age;

        // 电话
        cout << "请输入联系电话：" << endl;
        string phone;
        cin >> phone;
        abs->personArray[abs->m_Size].m_Phone = phone;

        // 地址
        cout << "请输入家庭住址：" << endl;
        string address;
        cin >> address;
        abs->personArray[abs->m_Size].m_Addr = address;

        // 更新通讯录人数
        abs->m_Size++;
        cout << "添加成功！" << endl;

        // 添加成功清屏幕
        system("pause"); // 请按任意键继续
        system("cls"); // 清屏

    }
    
}

// 菜单界面
void showMenu()
{
    cout << "****************************" << endl;
    cout << "*****   1. 添加联系人   *****" << endl;
    cout << "*****   2. 显示联系人   *****" << endl;
    cout << "*****   3. 删除联系人   *****" << endl;
    cout << "*****   4. 查找联系人   *****" << endl;
    cout << "*****   5. 修改联系人   *****" << endl;
    cout << "*****   6. 清空联系人   *****" << endl;
    cout << "*****   0. 退出通讯录   *****" << endl;
    cout << "****************************" << endl;
}



int main()
{

    // 创建通讯录结构体变量
    Addressbooks abs;
    // 初始化通讯录中当前人员个数
    abs.m_Size = 0;

    int select = 0; //创建用户选择输入的变量

    while (true) // 做完除了退出操作都会回到初始界面
    {
        // 菜单的调用
        showMenu();

        cin >> select;

        switch (select)
        {
        case 1: // 1. 添加联系人
            addPerson(&abs); // 利用地址传递，可以修饰实参
            /* code */
            break;
        case 2: // 2. 显示联系人
            /* code */
            break;
        case 3: // 3. 删除联系人
            /* code */
            break;
        case 4: // 4. 查找联系人
            /* code */
            break;
        case 5: // 5. 修改联系人
            /* code */
            break;
        case 6: // 6. 清除联系人
            /* code */
            break;
        case 0: // 0. 退出通讯录
            cout << "欢迎下次使用" << endl;
            system("pause"); // 按任意键退出的效果
            return 0; // 退出效果
            break;
        
        default:
            break;
        }

    }
    

    system("pause");

    return 0;
}

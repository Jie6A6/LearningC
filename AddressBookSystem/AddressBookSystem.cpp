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


// 2. 显示所有联系人
void showPerson(Addressbooks * abs)
{
    // 判断通讯录中人数是否为 0 ，如果为 0 ，提示记录为空；如果不为 0 ，显示记录的联系人信息
    if (abs->m_Size == 0)
    {
        cout << "当前记录为空" << endl;
    }
    else
    {
        for (int i = 0; i < abs->m_Size; i++)
        {
            cout << "姓名：" << abs->personArray[i].m_Name << "\t"; // 制表符操作
            cout << "性别：" << (abs->personArray[i].m_Gender == 1 ? "男" : "女") << "\t";
            cout << "年龄：" << abs->personArray[i].m_Age<< "\t";
            cout << "电话：" << abs->personArray[i].m_Phone << "\t";
            cout << "住址：" << abs->personArray[i].m_Addr << endl;
        }
    }
    system("pause");
    system("cls");
}


// 3. 删除指定联系人

// 检测联系人是否存在
int isExist(Addressbooks * abs, string name) // 参数 1 通讯录，参数 2 输入的人名
{
    for (int i = 0; i < abs->m_Size; i++)
    {
        // 找到用户输入的姓名
        if (abs->personArray[i].m_Name == name)
        {
            return i; // 找到了，返回这个人在数组的下标编号
        }
    }
    return -1; // 遍历结束没有找到，返回 -1
}

// 删除指定联系人
void deletePerson(Addressbooks * abs)
{
    cout << "请输入您要删除的联系人：" << endl;

    string name;
    cin >> name;

    // ret == -1 未查到
    // ret != -1 查到
    int ret = isExist(abs, name);

    if (ret != -1)
    {
        // 查到了，进行具体删除操作，把后面的数据往需要删除的前移数据覆盖，并且让通讯录中记录人员数量 -1
        for (int i = ret; i < abs->m_Size; i++)
        {
            // 数据前移
            abs->personArray[i] = abs->personArray[i + 1];
        }
        abs->m_Size--; // 更新通讯录中的人员数
        cout << "删除成功！" << endl;
    }
    else
    {
        cout << "查无此人！" << endl;
    }

    system("pause");
    system("cls");
    
}


// 4. 查找指定联系人
void findPerson(Addressbooks * abs)
{
    cout << "请输入您要查找的联系人" << endl;
    string name;
    cin >> name;
    
    // 判断联系人是否存在
    int ret = isExist(abs, name);
    if (ret != -1) // 找到联系人
    {
        cout << "姓名：" << abs->personArray[ret].m_Name << "\t"; // 制表符操作
        cout << "性别：" << (abs->personArray[ret].m_Gender == 1 ? "男" : "女") << "\t";
        cout << "年龄：" << abs->personArray[ret].m_Age<< "\t";
        cout << "电话：" << abs->personArray[ret].m_Phone << "\t";
        cout << "住址：" << abs->personArray[ret].m_Addr << endl;
    }
    else
    {
        cout << "查无此人！" << endl; 
    }

    system("pause");
    system("cls");
}


// 5. 修改指定联系人
void modifyPerson(Addressbooks * abs)
{
    cout << "请输入您要修改的联系人" << endl;
    string name;
    cin >> name;
    
    // 判断联系人是否存在
    int ret = isExist(abs, name);
    if (ret != -1) // 修改联系人
    {
        // 姓名
        string name;
        cout << "请输入姓名：" << endl;
        cin >> name;
        abs->personArray[ret].m_Name = name;
        // 性别
        cout << "请输入性别：" << endl;
        cout << "1 --- 男" << endl;
        cout << "2 --- 女" << endl;
        int gender = 0;

        while (true)
        {
            cin >> gender;
            if (gender == 1 || gender == 2)
            {
                abs->personArray[ret].m_Gender = gender;
                break;
            }
            cout << "输入有误，请重新输入！" << endl;
        }
        // 年龄
        cout << "请输入年龄：" << endl;
        int age = 0;
        abs->personArray[ret].m_Age = age;
        // 电话
        cout << "请输入电话：" << endl;
        string phone;
        abs->personArray[ret].m_Phone = phone;
        // 地址
        cout << "请输入地址：" << endl;
        string adress;
        abs->personArray[ret].m_Addr = adress;

        cout << "修改成功！" << endl; 
    }
    else
    {
        cout << "查无此人！" << endl; 
    }

    system("pause");
    system("cls");
}


// 6. 清空联系人
void cleanPerson(Addressbooks * abs)
{

    abs->m_Size = 0; //将当前记录联系人数量置为 0 ，做逻辑清空操作
    cout << "通讯录清空" << endl;
    system("pause");
    system("cls");
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
            break;
        case 2: // 2. 显示联系人
            showPerson(&abs);
            break;
        case 3: // 3. 删除联系人 // case语句中大段代码要括号括起来
        /*{    cout << "请输入删除联系人的姓名：" << endl;
            string name;
            cin >> name;
            
            if (isExist(&abs, name) == -1)
            {
                cout << "查无此人！" << endl;
            }
            else
            {
                cout << "找到此人！" << endl;
            }
        }*/
            deletePerson(&abs);
            break;
        case 4: // 4. 查找联系人
            findPerson(&abs);
            break;
        case 5: // 5. 修改联系人
            modifyPerson(&abs);
            break;
        case 6: // 6. 清除联系人
            cleanPerson(&abs);
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

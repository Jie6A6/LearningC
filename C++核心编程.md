# C++ 核心编程

本阶段主要针对 C++ 面向对象编程技术做详细讲解，探讨 C++ 的核心和精髓。

## 1. 内存分区模型

C++ 程序在执行时，将内存大方向划分为 **4 个区域**

- 代码区：存放函数体的二进制代码，由操作系统进行管理的
- 全局区：存放全局变量和静态变量以及常量
- 栈区：由编译器自动分配释放，存放函数的参数值、局部变量等
- 堆区：由程序员分配和释放，若程序员不释放，程序结束时由操作系统回收

**内存四区意义**：

不同区间存放的数据，赋予不同的生命周期，给我们更大的灵活编程

### 1.1 程序运行前

在程序编译后，生成了 `exe` 可执行程序，**未执行该程序前**分为两个区域

**代码区**：

- 存放 CPU 执行的机器指令
- 代码区是**共享**的，共享的目的是对于频繁被执行的程序，只需要在共享中有一份代码即可
- 代码区是**只读**的，使其只读的原因是防止程序意外地修改了它的指令

**全局区**：

- 全局变量和静态变量存放在此
- 全局还包含了常量区，字符串常量和其他常量也存放在此
- **该区域的数据在程序结束后由操作系统释放**

示例：

```
#include<iostream>
using namespace std;

// 全局变量
int g_a = 10;
int g_b = 10;

// const 修饰的全局变量、全局常量
const int c_g_a = 10;
const int c_g_b = 10;


int main(){

    // 全局区
    // 全局变量、静态变量、常量


    // 创建普通局部变量
    int a = 10;
    int b = 10;

    cout << "局部变量 a 的地址为：" << (int)&a << endl;
    cout << "局部变量 b 的地址为：" << (int)&b << endl;

    cout << "全局变量 g_a 的地址为：" << (int)&g_a << endl;
    cout << "全局变量 g_b 的地址为：" << (int)&g_b << endl;

    // 创建静态变量 在普通变量前面加 static ，属于静态变量
    static int s_a = 10;
    static int s_b = 10;
    cout << "静态变量 s_a 的地址为：" << (int)&g_a << endl;
    cout << "静态变量 s_b 的地址为：" << (int)&g_b << endl;

    // 常量
    // 字符串常量
    cout << "字符串常量的地址为：" << (int)&"Hello World" << endl;

    // const 修饰的变量
    // const 修饰的全局变量，const 修饰的局部变量

    cout << "全局常量 c_g_a 的地址为" << (int)&c_g_a << endl;
    cout << "全局常量 c_g_b 的地址为" << (int)&c_g_b << endl;

    const int c_l_a = 10;
    const int c_l_b = 10;

    cout << "局部常量 c_l_a 的地址为" << (int)&c_l_a << endl;
    cout << "局部常量 c_l_b 的地址为" << (int)&c_l_b << endl;

    system("pause");

    return 0;

}
```



### 1.2 程序运行后

**栈区**：

由编译器自动分配释放，存放函数的参数值、局部变量等

注意事项：不要返回局部变量的地址，栈区开辟的数据由编译器自动释放

```
#include<iostream>
using namespace std;

// 栈区数据

int* func(int b) // 形参数据也会放在栈区
{
    b = 100;
    int a = 10; // 局部变量 存放在栈区，栈区的数据在函数执行完成后自动释放
    return &a;  // 返回局部变量的地址
}

int main(){

    int * p = func();

    cout << *p << endl; // 第一次能打印数字，因为编译器做了保留
    cout << *p << endl; // 第二次这个数据就不再保留了

    system("pause");

    return 0;

}
```

**堆区**：

由程序员分配释放，若程序员不释放，程序结束时由操作系统回收

由 C++ 中主要利用 new 在堆区开辟内存，使用 new 在堆区分配内存并返回地址是安全的，因为堆区内存不会随函数结束而释放，但要记得用 delete 释放，避免内存泄漏。

```
#include<iostream>
using namespace std;

// 栈区数据

int* func() // 形参数据也会放在栈区
{
    int *a = new int(10);
    return a;
}

int main(){

    int * p = func();

    cout << *p << endl;
    cout << *p << endl;

    delete p; // 释放堆区内存
    p = nullptr; // 将指针置为空，避免野指针

    system("pause");

    return 0;

}
```

### 1.3 new 操作符

C++ 中利用 `new` 操作符在堆区开辟数据

堆区开辟的数据，由程序员手动开辟，手动释放，释放利用操作符号 `delete` 

语法： `new 数据类型`

利用 `new` 创建的数据，会返回该数据对应的类型的指针

示例：基本语法

```
#include <iostream>
using namespace std;

int * func()
{
    int *a = new int(10);
    return a;
}


// 在堆区利用 new 开辟整型
void test01()
{
    // 程序员开辟
    int *p = func();
    cout << *p << endl;
    cout << *p << endl;
    cout << *p << endl;

    // 程序员释放 内存已被释放，再次访问就是非法操作，报错
    delete p;
    p = nullptr; 
    cout << *p << endl;

}

// 在堆区利用 new 开辟数组
void test02()
{
    // 创建 10 整型数据的数组，在堆区
    int * arr = new int[10]; // 10 代表数组由 10 个
    
    for (int i = 0; i < 10; i++)
    {
        arr[i] = i + 100;
    }

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << endl;
    }

    // 释放数组的时候 要加[]才可以
    delete[] arr;
    arr = nullptr;

}


int main(){

    test01();

    

    system("pause");

    return 0;
}
```

## 2. 引用

### 2.1 引用的基本使用

1. **作用**：给变量起别名，修改引用等价于修改原变量

2. **语法**：`数据类型 &别名 = 原名`

示例：

```
#include<iostream>
using namespace std;

int main(){

    int a = 10;
    // 创建引用
    int &b = a;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    b = 100;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    system("pause");

    return 0;

}
```

### 2.2 引用注意事项

- 引用必须初始化
- 引用在初始化后，不可以改变

示例：

```
#include<iostream>
using namespace std;

int main(){

    int a = 10;
    int b = 20;

    // int &c; // 错误的，必须初始化
    int &c = a; // 一旦初始化后，就不可以更改
    c = b; // 这是赋值操作，不是更改引用

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;


    system("pause");

    return 0;

}
```

### 2.3 引用做函数参数

1. **作用**：函数传参时，可以利用引用的技术让形参修饰实参

2. **优点**：可以简化指针修改实参

示例：

```
#include<iostream>
using namespace std;

// 1. 值传递
void mySwap01(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

// 2. 位置传递
void mySwap02(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 3. 引用传递
void mySwap03(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main(){

    int a = 10;
    int b = 20;

    mySwap01(a, b); // 值传递，形参不会修饰实参
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    a = 10;
    b = 20;

    mySwap02(&a, &b); // 位置传递，形参修饰实参
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    
    a = 10;
    b = 20;

    mySwap03(a, b); // 引用传递，形参修饰实参
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    system("pause");

    return 0;

}
```

### 2.4 引用做函数返回值

1. **作用**：引用是可以作为函数的返回值存在的

2. **注意**：**不要返回局部变量引用**

3. **用法**：函数调用作为左值，左值是一个可以被 "赋值" 的对象，因为它在内存中有确定的位置。

示例：

```
#include<iostream>
using namespace std;

// 1. 不要返回局部变量的引用，会被销毁
int& test01()
{
    int a = 10; // 局部变量存放在栈区
    return a;
}

// 2. 函数的调用可以作为左值
int& test02()
{
    static int a = 10; // 静态变量，存放全局区
    return a;
}

int main(){

    /*
    int &ref = test01();

    cout << "ref = " << ref << endl; // 第一次结果正确，编译器做了保留
    cout << "ref = " << ref << endl; // 第二次结果错误，因为 a 内存已经释放
    */

    int &ref2 = test02();

    cout << "ref2 = " << ref2 << endl; // 第一次结果正确，编译器做了保留
    cout << "ref2 = " << ref2 << endl; // 第二次结果正确，编译器做了保留

    test02() = 1000; // 可以赋值，是个左值！！

    cout << "ref2 = " << ref2 << endl;
    cout << "ref2 = " << ref2 << endl;

    int &ref3 = test02(); // 函数里面的值被改了

    cout << "ref3 = " << ref3 << endl; 
    cout << "ref3 = " << ref3 << endl;


    system("pause");

    return 0;

}
```

### 2.5 引用的本质

**本质**：**引用的本质在 C++ 内部实现了一个指针常量**

讲解示例：

```
#include<iostream>
using namespace std;

void func()


int main(){




    system("pause");

    return 0;

}
```
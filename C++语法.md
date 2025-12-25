# 1 C++ 初识

## 1.1 Hello World

```
#include <iostream>
using namespace std;

int main() {

    cout << "Hello World" << endl;
    
    system("pause");
    
    return 0;
    
}
```

## 1.2 注释

1. 单行注释

```
// 单行注释
```

2. 多行注释

```
/* 多行注释
多行注释 */
```

## 1.3 变量

1. 变量存在的意义：方便管理内存；

2. 创建方法：数据类型 变量名 = 变量初始值。

```
#include <iostream>
using namespace std;

int main() {

    // 变量创建的语法

    int a = 10;

    cout << "a = " << a << endl;
    
    system("pause");
    
    return 0;
    
}
```

## 1.4 常量

1. **作用**：用于记录程序中不可更改的数据；

2. 定义常量的两种方式：
    - #define宏常量：`#define 常量名 常量值`，通常在文件上定义，表示一个常量；
    - const修饰的变量：`const 数据类型 = 常量值`，通常在变量定义前加关键词const，修饰该变量为常量，不可修改。

示例：

```
#include <iostream>
using namespace std;

// 1. #define 宏常量
#define Day 7

int main() {

    // Day = 14; // 错误，Day是常量，一旦修改就会报错
    cout << "一周总共有：" << Day << " 天" << endl;

    // 2. const修饰的变量
    const int month = 12;
    // month = 24; // 错误，const修饰的变量也称为常量
    cout << "一年总共有：" << month << " 月" << endl;

    system("pause");
    
    return 0;
    
}
```

## 1.5 关键字

1. **作用**：关键字是 C++ 中预先保留的单词 (标识符)

2. **在定义变量或者常量时候，不要用关键词**

C++ 关键字如下：

| asm | do | if | return | typedef |
| --- | --- | --- | --- | --- |
| auto 自动推导变量类型 | double 双精度浮点数 | inline 建议编译器将函数内联以提高效率 | short 短整数 | typeid |
| bool 布尔型 | dynamic_cast 用于类继承体系中的安全转换 | int 整数 | signed 有符号 | typename |
| break | else | long 长整数 | sizeof | union 联合体 |
| case | enum | mutable 即使在 const 函数中也允许修改的变量 | static 静态变量 | unsigned 无符号 |
| catch | explicit | namespace | static_cast 最常用的基本转换 | using |
| char 字符型 | export | new 在堆上创建对象 | struct 结构体 | virtual 虚函数 |
| class 类 | extern 声明变量在其他文件中定义 | operator 运算符重载 | switch | void 无类型 |
| const 常量 | false | private 私有 | template | volatile 告诉编译器该变量可能被外部 (如硬件) 改变，不要过度优化。 |
| const_cast 去除变量的 const 属性 | float 单精度浮点数 | protected 受保护 | this 指向当前对象的指针 | wchar_t 宽字符型 |
| continue | for | public 公开 | throw | while |
| default | friend 友元 | register 建议将变量存入 CPU 寄存器 | true |  |
| delete 销毁对象 | goto | reinterpret_cast 底层的重新解释转换 | try |  |

注：在给变量或者常量起名称时候，不能使用 C++ 的关键字，否则会歧义报错。

## 1.6 标识符命名规则

1. **作用**：C++ 规定的标识符 (变量、常量) 命名时， 有一套自己的规则

   - 标识符不能是关键字；
   - 标识符只能由字母、数字、下划线组成；
   - 第一个字符必须为字母或下划线；
   - 标识符中字母区分大小写。

2. 建议：给标识符命名时，见名知意。

```
#include <iostream>
using namespace std;

int main() {

    // 1. 不能是关键字
    // int int = 10;

    // 2. 只能用字母、数字、下划线，开头只能是字母和下划线
    int abc = 10;
    int _abc = 20;
    int _123abc = 30;
    // int 123abc = 40;
    int Abc = 50;
    
    cout << abc << endl;
    cout << _abc << endl;
    cout << _123abc << endl;
    cout << Abc << endl;

    system("pause");
    
    return 0;
    
}
```

# 2 数据类型

C++ 规定在创建一个变量或者常量时，必须给出相应的数据类型，否则无法给变量分配内存。

## 2.1 整型

1. 作用：整型变量标识的是整数类型的数据

2. C++ 中能够表示整型的类型有以下几种方式，区别在于所占内存空间不同：

| 数据类型 | 占用空间 | 取值范围 |
| --- | --- | --- |
| short (短整型) | 2 字节 | (-2^15 ~ 2^15-11) |
| int (整型) | 4 字节 | (-2^31 ~ 2^31-1) |
| long (长整型) | Windows 为 4 字节，Linux为 4 字节 (32位) ，8字节 (64位) | (-2^31 ~ 2^31-1) |
| long long (长长整型) | 8 字节 | (-2^63 ~ 2^63-1) |

```
#include <iostream>
using namespace std;

int main() {

    // 1. 短整型 (-32768 ~ 32767)
    short num1 = 10;

    // 2. 整型
    int num2 = 10;
    
    // 3. 长整型
    long num3 = 10;
    
    // 4. 长长整型
    long long num4 = 10;
    
    cout << "num1 = " << num1 << endl;
    cout << "num2 = " << num2 << endl;
    cout << "num3 = " << num3 << endl;
    cout << "num4 = " << num4 << endl;

    system("pause");
    
    return 0;
    
}
```

## 2.2 sizeof 关键字

1. **作用**：利用 sizeof 关键字可以**统计数据类型所占的内存大小**；

2. **语法**：`sizeof( 数据类型 / 变量 )`

3. **整型大小比较**: short < int <= long <= long long

示例：

```
#include <iostream>
using namespace std;

int main() {

    // 整型：short (2) int (4) long (4) long long (8)
    

    // 1. 短整型
    short num1 = 10;
    cout << "short占用内存空间为：" << sizeof(short) << endl;
    cout << "num1占用内存空间为：" << sizeof(num1) << endl;

    // 2. 整型
    int num2 = 10;
    cout << "int占用内存空间为：" << sizeof(int) << endl;
    cout << "num2占用内存空间为：" << sizeof(num2) << endl;
    
    // 3. 长整型
    long num3 = 10;
    cout << "long占用内存空间为：" << sizeof(long) << endl;
    cout << "num3占用内存空间为：" << sizeof(num3) << endl;
    
    // 4. 长长整型
    long long num4 = 10;
    cout << "long long占用内存空间为：" << sizeof(long long) << endl;
    cout << "num4占用内存空间为：" << sizeof(num4) << endl;

    // 整型大小比较
    // short < int <= long <= long long


    system("pause");
    
    return 0;
    
}
```

## 2.3 实型 (浮点型)

1. **作用**：用于表示小数；

2. **分类**：

    - 单精度 float
    - 双精度 double

两者的**区别**在于表示的有效数字范围不同。

| 数据类型 | 占用空间 | 有效数字范围 |
| --- | --- | --- |
| float | 4 字节 | 7 位有效数字 |
| double | 8 字节 | 15 ~ 16 位有效数字 |

示例：

```
#include <iostream>
using namespace std;

int main() {

    
    float f1 = 3.1415927f;
    double d1 = 3.1415926;

    cout << "f1 = " << f1 << endl;
    cout << "d1 = " << f1 << endl; // 默认显示只会显示 6 位

    // 统计占用空间
    cout << "float占用空间 " << sizeof(float) << endl;
    cout << "double占用空间 " << sizeof(double) << endl;
    cout << "f1占用空间 " << sizeof(f1) << endl;
    cout << "d1占用空间 " << sizeof(d1) << endl;

    // 科学计数法
    float f2 = 3e2; // 3 * 10 ^ 2
    cout << "f2 =" << f2 << endl;

    float f3 = 3e-2; // 3 * 0.1 ^ 2
    cout << "f3 =" << f3 << endl;

    system("pause");
    
    return 0;
    
}
```

## 2.4 字符型

1. **作用**：字符型变量用于显示单个字符

2. **语法**：`char ch = 'a'`

> 注意1 ：在现实字符型的变量时，用单引号将字符括起来，不要用双引号

> 注意2 ： 单引号内只有一个字符，不可以是字符串

- C 和 C++ 中字符型变量只占用 1 个字节。
- 字符型变量并不是把字符本身放到内存中存储，而是将对应的ASCII编码放入到存储单元。

示例：

```
#include <iostream>
using namespace std;

int main() {

    
    char ch = 'a';
    
    cout << "ch = " << ch << endl;
    cout << "char占用空间 " << sizeof(char) << endl;
    cout << "ch占用空间 " << sizeof(ch) << endl;
    cout << "ch对应ASCII编码 " << int(ch) << endl;

    system("pause");
    
    return 0;
    
}
```

3. ASCII编码对应表：

| 十进制 | 十六进制 | 字符 | 说明 |
| :--- | :--- | :--- | :--- |
| 0 | 00 | NUL | 空字符 (Null) |
| 7 | 07 | \a | 响铃 (Bell) |
| 8 | 08 | \b | 退格 (Backspace) |
| 9 | 09 | \t | 水平制表符 (Tab) |
| 10 | 0A | \n | 换行 (Line Feed) |
| 13 | 0D | \r | 回车 (Carriage Return) |
| 32 | 20 | (space) | 空格 |
| 33 | 21 | ! | 感叹号 |
| 48-57 | 30-39 | 0-9 | **数字 0 到 9** |
| 65-90 | 41-5A | A-Z | **大写字母 A 到 Z** |
| 97-122 | 61-7A | a-z | **小写字母 a 到 z** |

ASCII编码大致由两部分组成：

- 0 - 31 分配给控制字符
- 32 - 126 分配给键盘上的字符

## 2.5 转义字符

1. **作用**：用于表示一些**不能显示出来的ASCII字符**

2. 常用的转义字符有：`\n \\ \t`

| 转义字符 | 含义 | ASCII码值 (十进制) |
| --- | --- | --- |
| \a | 警报 | 007 |
| \b | 退格 (BS) ，将当前位置移到前一列 | 008 |
| \f | 换页 (FF) ，将当前位置移到下页开头 | 012 |
| \n | **换行 (LF) ，将当前位置移到下一行开头** | 010 |
| \r | 回车 (CR) ，将当前位置移到本行开头 | 013 |
| \t | **水平制表 (HT) ，跳到下一个TAB位置** | 009 |
| \v | 垂直制表 (VT) | 011 |
| \\ | **代表一个反斜线字符 "\"** | 092 |
| \' | 代表一个单引号 (撇号) 字符 | 039 |
| \" | 代表一个双引号字符 | 034 |
| \? | 代表一个问号 | 063 |

示例：

```
#include <iostream>
using namespace std;

int main() {

    // 换行符号 \n

    cout << "Hello World\n";

    // 反斜杠 \\

    cout << "\\" << endl;

    // 水平制表符 \t   作用是可以整齐输出

    cout << "aaa\thelloworld" << endl;
    cout << "aa\thelloworld" << endl;
    cout << "aaaa\thelloworld" << endl;
    cout << "aaaaa\thelloworld" << endl;
    cout << "aaaaaa\thelloworld" << endl;
    cout << "a\thelloworld" << endl;
    cout << "aaaaaaa\thelloworld" << endl;

    system("pause");
    
    return 0;
    
}
```

## 2.6 字符串型

1. **作用**：用于表示一串字符

2. **两种风格**：

- C 风格字符串：`char 变量名[] = "字符串值"`

示例：

```
#include <iostream>
using namespace std;

int main() {

    char str1[] = "Hello World";

    cout << str1 << endl;

    system("pause");
    
    return 0;
    
}
```
> 注意：C 风格的字符串要用双引号括起来。

- C++ 风格字符串：`string 变量名 = "字符串值"`

示例：

```
#include <iostream>
using namespace std;
#include <string> // 用 C++ 风格字符串型时，要添加这个头文件

int main() {

    string str2 = "Hello World";

    cout << str2 << endl;

    system("pause");
    
    return 0;
    
}
```
> 注意：C++ 风格字符串型一定要添加 #include <string> 头文件。

## 2.7 布尔类型 bool

1. **作用**：布尔数据类型代表真或假的值

2. **类别**：

    - true --- 真 (本质是 1 ，除了 0 其他都是真)
    - false --- 假 (本质是 0 )

    bool类型占 1 个字节大小

示例：

```
#include <iostream>
using namespace std;

int main() {

    bool flag1 = true;
    bool flag2 = false;

    cout << flag1 << endl;
    cout << flag2 << endl;
    cout << "bool类型所占内存空间：" << sizeof(bool) << endl;
    cout << "flag1类型所占内存空间：" << sizeof(flag1) << endl;
    cout << "flag2类型所占内存空间：" << sizeof(flag2) << endl;
    
    system("pause");
    
    return 0;
    
}
```

## 2.8 数据的输入

1. **作用**：用于从键盘获取数据

2. **关键词**：`cin`

3. **语法**：`cin >> 变量`

示例：

```
#include <iostream>
using namespace std;
#include <string>

int main() {

    // 整型输入
    int a = 0;
    cout << "请输入整型变量：" << endl;
    cin >> a;
    cout << a << endl;

    // 浮点型输入
    float f = 3.14f;
    cout << "请输入浮点型变量：" << endl;
    cin >> f;
    cout << f << endl;

    // 字符型输入
    char ch = 'a';
    cout << "请输入字符型变量：" << endl;
    cin >> ch;
    cout << ch << endl;

    // 字符串型输入
    string str = "abc";
    cout << "请输入字符型变量：" << endl;
    cin >> str;
    cout << str << endl;

    // 布尔类型输入
    bool flag = false;
    cout << "请输入字符型变量：" << endl;
    cin >> flag;
    cout << flag << endl;
  
    system("pause");
    
    return 0;
    
}
```

# 3 运算符

1. **作用**：用于执行代码的运算

2. **类别**：算术、赋值、比较、逻辑运算符

| 运算符类型 | 作用 |
| --- | --- |
| 算术运算符 | 四则运算 |
| 赋值运算符 | 将表达式的值赋给变量 |
| 比较运算符 | 表达式的比较，并返回一个真值或假值 |
| 逻辑运算符 | 根据表达式的值返回真或假值 |

## 3.1 算术运算符

1. **作用**：四则运算

2. **符号意义**：

| 运算符 | 术语 | 示例 | 结果 |
| --- | --- | --- | --- |
| + | 正号 | +3 | 3 |
| - | 负号 | -3 | -3 |
| + | 加 | 10 + 5 | 15 |
| - | 减 | 10 - 5 | 5 |
| * | 乘 | 10 * 5 | 50 |
| / | 除 (被除数不为 0 ) | 10 / 5 | 2 |
| % | 取模 (取余) | 10 % 3 | 1 |
| ++ | 前置递增 | a=2;b=++a | a=3;b=3; |
| ++ | 后置递增 | a=2;b=a++ | a=3;b=2; |
| -- | 前置递减 | a=2;b=--a | a=1;b=1; |
| -- | 后置递减 | a=2;b=a-- | a=1;b=2; |

## 3.2 赋值运算符

1. **作用**：将表达式的值赋值给变量

2. **符号意义**：

| 运算符 | 术语 | 示例 | 结果 |
| --- | --- | --- | --- |
| = | 赋值 | a=2;b=3; | a=2;b=3; |
| += | 加等于 | a=0;a+=2; | a=2; |
| -= | 减等于 | a=5;a-=3; | a=2; |
| *= | 乘等于 | a=2;a*=2; | a=4; |
| /= | 除等于 | a=4;a/=2; | a=2; |
| %= | 模等于 | a=3;a%=2; | a=1; |

## 3.3 比较运算符

1. **作用**：表达式比较，并返回一个真/假值

2. **符号意义**：

| 运算符 | 术语 | 示例 | 结果 |
| --- | --- | --- | --- |
| == | 相等于 | 4 == 3 | 0 |
| != | 不等于 | 4 != 3 | 1 |
| < | 小于 | 4 < 3 | 0 |
| > | 大于 | 4 > 3 | 1 |
| <= | 小于等于 | 4 <= 3 | 0 |
| >= | 大于等于 | 4 >= 3 | 1 |

示例：

```
#include <iostream>
using namespace std;

int main() {

    int a1 = 2;
    int b1 = 3;
        
    cout << (a1 == b1) << endl;
    cout << (a1 != b1) << endl;
    cout << (a1 < b1) << endl;
    cout << (a1 > b1) << endl;
    cout << (a1 <= b1) << endl;
    cout << (a1 >= b1) << endl;
  
    system("pause");
    
    return 0;
    
}
```

## 3.4 逻辑运算符

1. **作用**：根据表达式的值返回真/假值

2. **符号意义**：

| 运算符 | 术语 | 示例 | 结果 |
| --- | --- | --- | --- |
| ! | 非 | !a | 如果 a 假，则 a 为真；如果 a 真，则 a 为假。 |
| && | 与 | a && b | 如果 a 和 b 都为真，则结果为真，否则为假。 |
| || | 或 | a || b | 如果 a 和 b 有一个为真，则结果为真；两者都为假时，结果为假。 |

示例：

```
#include <iostream>
using namespace std;

int main() {

    int a = 2;
    int b = 0;

    cout << a << endl;
    cout << b << endl;
    cout << !a << endl;
    cout << (a && b) << endl;
    cout << (a || b) << endl;
    
  
    system("pause");
    
    return 0;
    
}
```

# 4 程序流程结构

C/C++ 支持最基本的三种程序运行结构：**顺序结构、选择结构、循环结构**

- 顺序结构：程序按顺序执行，不发生跳转
- 选择结构：依据条件是否满足，有选择地执行相应功能
- 循环结构：依据条件是否满足，循环多次执行某些代码

## 4.1 选择结构

### 4.1.1 if 语句

1. 单行格式 if 语句

```
#include <iostream>
using namespace std;

int main() {

    int a = 2;
    int b = 0;

    cout << a << endl;
    cout << b << endl;
    cout << !a << endl;
    cout << (a && b) << endl;
    cout << (a || b) << endl;
    
  
    system("pause");
    
    return 0;
    
}
```

2. 多行格式 if 语句



3. 多条件的 if 语句
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

1. 单行格式 if 语句：`if (条件){条件满足执行的语句}`

```
#include <iostream>
using namespace std;

int main() {

    // 1. 用户输入分数
    int score = 0;
    cout << "请输入一个分数：" << endl;
    cin >> score;

    // 2. 打印用户输入的分数
    cout << "您输入的分数是：" << score << endl;

    // 3. 判断分数是否大于600，如果大于，那么输出
    // 注意 if 后面不能加分号
    if (score > 600)
    {
        cout << "恭喜您考上了一本大学" << endl;
    }

    system("pause");
    
    return 0;
    
}
```

2. 多行格式 if 语句：`if (条件){条件满足执行的语句}else{条件不满足执行的语句}`

```
#include <iostream>
using namespace std;

int main() {

    // 1. 用户输入分数
    int score = 0;
    cout << "请输入一个分数：" << endl;
    cin >> score;

    // 2. 打印用户输入的分数
    cout << "您输入的分数是：" << score << endl;

    // 3. 判断
    if (score > 600)
    {
        cout << "恭喜您考上了一本大学" << endl;
    }
    else
    {
        cout << "可惜您没有考上一本大学" << endl;
    }

    system("pause");
    
    return 0;
    
}
```


3. 多条件的 if 语句：`if (条件1){条件1满足执行的语句}else if (条件2){条件2满足执行的语句}...else{都不满足执行的语句}`

```
#include <iostream>
using namespace std;

int main() {

    // 1. 用户输入分数
    int score = 0;
    cout << "请输入一个分数：" << endl;
    cin >> score;

    // 2. 打印用户输入的分数
    cout << "您输入的分数是：" << score << endl;

    // 3. 判断
    if (score > 600)
    {
        cout << "恭喜您考上了一本大学" << endl;
    }
    else if (score > 500)
    {
        cout << "恭喜您考上了二本大学" << endl;
    }
    else if (score > 400)
    {
        cout << "恭喜您考上了三本大学" << endl;
    }
    else
    {
        cout << "可惜您没考上大学" << endl;
    }

    system("pause");
    
    return 0;
    
}
```

4. 嵌套 if 语句：在 if 语句中，可以嵌套使用 if 语句，达到更精确的条件判断。

示例：

```
#include <iostream>
using namespace std;

int main(){

    // 1. 用户输入分数
    int score = 0;
    cout << "请输入一个分数：" << endl;
    cin >> score;

    // 2. 打印用户输入的分数
    cout << "您输入的分数是：" << score << endl;

    // 3. 判断
    /*
    如果大于600 一本
        如果大于700 北大
        如果大于650 清华
        其余        人大
    如果大于500 二本
    如果大于400 三本
    其余情况，未考上本科
    */

    if (score > 600)
    {
        cout << "恭喜您考上了一本大学" << endl;
        if (score > 700)
        {
            cout << "恭喜您考上了北京大学" << endl;
        }
        else if (score > 650)
        {
            cout << "恭喜您考上了清华大学" << endl;
        }
        else
        {
            cout << "恭喜您考上了人民大学" << endl;
        }
    }
    else if (score > 500)
    {
        cout << "恭喜您考上了二本大学" << endl;
    }
    else if (score > 400)
    {
        cout << "恭喜您考上了三本大学" << endl;
    }
    else
    {
        cout << "可惜您没考上大学" << endl;
    }

    system("pause");

    return 0;
}
```

**练习案例**：三只小猪称体重

有三只小猪 A、B、C ，请分别输入三只小猪的体重，并且判断哪只小猪最重？

```
#include <iostream>
using namespace std;

int main(){

    int A = 0;
    int B = 0;
    int C = 0;

    cout << "请输入 A 小猪的体重：" << endl;
    cin >> A;
    cout << "A 小猪的体重：" << A << endl;

    cout << "请输入 B 小猪的体重：" << endl;
    cin >> B;
    cout << "B 小猪的体重：" << B << endl;
    
    cout << "请输入 C 小猪的体重：" << endl;
    cin >> C;
    cout << "C 小猪的体重：" << C << endl;

    if (A > B)
    {
        if (A > C)
        {
            cout << "A 小猪最重" << endl;
        }
        else
        {
            cout << "C 小猪最重" << endl;
        }
    }
    else
    {
        if (B > C)
        {
            cout << "B 小猪最重" << endl;
        }
        else
        {
            cout << "C 小猪最重" << endl;
        }
    }

    system("pause");

    return 0;
}
```

### 4.1.2 三目运算符

1. **作用**：通过三目运算符号实现简单判断

2. **语法**：`表达式1 ? 表达式2 : 表达式3`
   
3. **解释**：
   如果表达式 1 的值为真，执行表达式 2，并返回表达式 2 的结果；
   如果表达式 1 的值为假，执行表达式 3，并返回表达式 3 的结果。

示例：

```
#include <iostream>
using namespace std;

int main(){

    int a = 10;
    int b = 20;
    int c = 0;

    c = a > b ? a : b;
    cout << "c = " << c << endl;

    // C++ 中三目运算符返回的是变量，可以继续赋值

    (a > b ? a : b) = 100;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    system("pause");

    return 0;

}
```

### 4.1.3 switch 语句

1. **作用**：执行多条件分支语句

2. **语法**：

```
switch (表达式)

{

case 结果1 : 
    执行语句;
    break;

case 结果2 : 
    执行语句;
    break;

    ...

default:
    执行语句;
    break;

}
```

示例：

```
#include <iostream>
using namespace std;

int main(){

    /*
    给电影进行打分
    10 ~ 9 经典
    8 ~ 7 非常好
    6 ~ 5 一般
    5 以下 烂片
    */
    
    cout << "请给电影进行打分" << endl;

    int score = 0;
    cin >> score;
    cout << "您打的分数为：" << score << endl;

    switch (score)

    {
    case 10:
        cout << "您认为是经典电影" << endl;
        break;
    case 9:
        cout << "您认为是经典电影" << endl;
        break;
    case 8:
        cout << "您认为是非常好的电影" << endl;
        break;
    case 7:
        cout << "您认为是非常好的电影" << endl;
        break;
    case 6:
        cout << "您认为是一般的电影" << endl;
        break;
    case 5:
        cout << "您认为是一般的电影" << endl;
        break;
    default : 
        cout << "您认为是烂片" << endl;
        break;

    }


    system("pause");

    return 0;

}
```

3. if 和 switch 区别 ？

- switch 缺点是判断只能是整型或字符型，不可以是一个区间；
- switch 优点是结构清晰，执行效率高；

## 4.2 循环结构

### 4.2.1 while 循环语句

1. **作用**：满足循环条件，执行循环语句

2. **语法**：`while (循环条件){循环语句}`

3. **解释**：只要循环条件的结果为真，就执行循环语句

示例：

```
#include<iostream>
using namespace std;

int main(){

    // 打印 0 ~ 9
    int num = 0;
    

    while (num < 10)
    {
        cout << num << endl;
        num++;
    }

    system("pause");

    return 0;
}
```

**猜数字**：系统随机生成一个 (1~10) 的数字，玩家进行猜测，如果猜错，提示玩家数学过大或者过小，如果猜对恭喜玩家胜利，并退出游戏。

```
#include <iostream>
using namespace std;
// time 系统时间头文件包含
#include <ctime>
    
int main(){
    
    srand((unsigned int)time(NULL)); // 通过将当前时间作为种子

    // 1. 系统生成随机数 (随机生成0 + 1 ~ 99 + 1 随机数)
    int num = rand()%10 + 1;
    cout << num << endl;

    // 2. 玩家进行猜测
    int val = 0;


    while (1)
    {
        cout << "请输入猜测的数字（1~10）：" << endl;
        cin >> val;

        // 3. 判断玩家的猜测
        if (val > num)
        {
            cout << "过大" << endl;
        }
        else if (val < num)
        {
            cout << "过小" << endl; 
        }
        else
        {
            cout << "猜对啦" << endl;
            break; // break 退出当前循环
        }
    }
    

    system("pause");

    return 0;

    
}
```

### 4.2.2 do...while 循环语句

1. **作用**：满足循环条件，执行循环语句

2. **语法**：`do{循环语句} while(循环条件);`

3. **注意**：与while的区别在于do...while会先执行一次循环语句，再判断循环条件

示例：

```
#include <iostream>
using namespace std;

int main(){

    int num = 0;

    do
    {
        cout << num << endl;
        num++;
    }
    while(num < 10);

    system("pause");

    return 0;

}
```

**水仙花数**：水仙花数是指一个 3 位数，它的每位上的数字的3次幂之和等于它本身

```
#include <iostream>
using namespace std;

int main(){

    // 1. 所有三位数输出

    int num = 100;

    do{
        int a = 0;
        int b = 0;
        int c = 0;
        
        a = num % 10;       // 获取个位
        b = num / 10 % 10;  // 获取十位
        c = num /100 % 100; // 获取百位
        
        if (a*a*a + b*b*b + c*c*c == num)
        {
            cout << num << endl;
        }
        
        
        num++;
    } while (num < 1000);

    system("pause");

    return 0;

}
```

### 4.2.3 for 循环语句

1. **作用**：满足循环条件，执行循环语句

2. **语法**：``for(起始表达式;条件表达式;末尾循环体) { 循环语句 }`

示例：

```
#include <iostream>
using namespace std;

int main(){

    for (int i = 0; i < 10; i++)
    {
        cout << i << endl;
    }

    system("pause");

    return 0;
}
```
同理：
```
#include <iostream>
using namespace std;

int main(){

    int i = 0;
    for (; ; )
    {
       if (i >= 10)
       {
        break;
       }
    }
    cout << i << endl;
    i++;

    system("pause");

    return 0;
}
```

**练敲桌子**：从 1 开始数到数字 100，如果数字个位含有 7，或者该数字是 7 的倍数，打印敲桌子，其余的数字直接打印输出。

```
#include <iostream>
using namespace std;

int main(){

    for (int i = 1; i < 101; i++)
    {
        if (i % 10  == 7 || i / 10 == 7 || i % 7 == 0)
        {
            cout << "敲桌子" << endl;
        }
        else
        {
            cout << i << endl;
        }
    }

    system("pause");

    return 0;
}
```

### 4.2.4 嵌套循环

**作用**：在循环体中再嵌套一层循环，解决一些实际问题

示例：

```
#include <iostream>
using namespace std;

int main(){

    for (int i = 0; i < 10; i++)
    {
        for (int i = 0; i < 10; i++)
        {
            cout << "* " ;
        }
        cout << endl;
    }

    system("pause");

    return 0;
}

```

**乘法口诀表**

```
#include <iostream>
using namespace std;

int main(){

    for (int i = 1; i < 10; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j << " × " << i << " = " << i*j << " ";
        }
        cout << endl;
    }

    system("pause");

    return 0;
}
```

## 4.3 跳转语句

### 4.3.1 break 语句

1. **作用**：用于跳出**选择结构**或者**循环结构**

2. **使用时机**：

    - 出现在 switch 条件语句中，作用是终止 case 并跳出 switch
    - 出现在循环语句中，作用是跳出当前的循环语句
    - 出现在嵌套循环中，跳出最近的内层循环语句

示例 1 ：

```
#include <iostream>
using namespace std;

int main(){


    // 1. switch 语句
    cout << "请选择副本难度" << endl;
    cout << "1. 普通" << endl;
    cout << "2. 中等" << endl;
    cout << "3. 困难" << endl;

    int select = 0;

    cin >> select;

    switch (select)
    {
    case 1:
        cout << "您选择的是普通难度" << endl;
        break;
    case 2:
        cout << "您选择的是中等难度" << endl;
        break;
    case 3:
        cout << "您选择的是困难难度" << endl;
        break;
    default:
        break;
    }
    
    // 2. 出现在循环语句中
    for (int i = 0; i < 10; i++)
    {
        // 如果 i 等于 5，退出循环
        if (i == 5)
        {
            break;
        }
        cout << i << endl;
    }

    // 3. 出现在嵌套循环语句中
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (j == 5)
            {
                break;
            }
            cout << "*";
        }
        cout << endl;
    }

    system("pause");

    return 0;
}
```

### 4.3.2 continue 语句

**作用**：在循环语句中，跳过本次循环中余下尚未执行的语句，继续执行下一次循环

示例：

```
#include <iostream>
using name std;

int main(){

    for (int i = 0; i < 10; i++)
    {
        // 如果是奇数输出，偶数不输出
        if (i % 2 == 0)
        {
            continue;
        }
        else
        {
            cout << i << endl;
        }
    }

    system("pause");

    return 0;
}
```

### 4.3.3 goto 语句

1. **作用**：可以无条件跳转语句

2. **语法**：`goto 标记`

3. **解释**：如果标记的名称存在，执行到 goto 语句时，会跳转到标记的位置

示例：

```
#include <iostream>
using namespace std;

int main(){

    cout << "1. ××××××××" << endl;

    cout << "2. ××××××××" << endl;

    goto FLAG;

    cout << "3. ××××××××" << endl;

    cout << "4. ××××××××" << endl;

    FLAG:
    cout << "5. ××××××××" << endl;

    system("pause");

    return 0;
}
```

# 5 数组

## 5.1 概述

数组是一个集合，存放相同类型的数据元素。

- **特点 1**：数组中的每个数据元素都是相同的数据类型
- **特点 2**：数组是由连续的内存位置组成的

## 5.2 一维数组

### 5.2.1 一维数组定义方式

一维数组定义的三种方式：

1. `数据类型 数组名[ 数组长度 ];`
2. `数据类型 数组名[ 数组长度 ] = {值1, 值2, ...};`
3. `数据类型 数组名[  ] = {值1, 值2, ...};`

示例：

```
#include <iostream>
using namespace std;

int main(){

    // 定义方式1
    // 数据类型 数组名[ 数组长度 ];
    int arr[5];
    // 给数组中的元素进行赋值 (下标是从 0 开始)
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    arr[3] = 40;
    arr[4] = 50;
    // 访问数据元素
    cout << arr[0] << endl;
    cout << arr[1] << endl;
    cout << arr[2] << endl;
    cout << arr[3] << endl;
    cout << arr[4] << endl;

    // 定义方式2
    // 数据类型 数组名[ 数组长度 ] = {值1, 值2, ...};
    // 如果在初始化数据时，没有全部填完，会用 0 填补剩余数据
    int arr2[5] = {15, 25, 35, 45, 55};
    
    // 访问数据元素
    cout << arr2[0] << endl;
    cout << arr2[1] << endl;
    cout << arr2[2] << endl;
    cout << arr2[3] << endl;
    cout << arr2[4] << endl;

    // 定义方式3
    // 数据类型 数组名[  ] = {值1, 值2, ...};
    int arr3[ ] = {16, 26, 36, 46, 56, 42, 32, 45,223};
    
    // 访问数据元素
    for (int i = 0; i < 9; i++)
    {
        cout << arr3[i] << endl;
    }
    
    system("pause");

    return 0;
}
```

### 5.2.2 一维数组数组名

一维数组名称的**用途**：

1. 可以统计整个数组在内存中的长度
2. 可以获取数组在内存中的首地址
3. 注意：数组名为常量，不可以进行赋值操作

示例：

```
#include <iostream>
using namespace std;

int main(){

    int arr[5] = {1, 2, 3, 4, 5};
    
    // 统计内存大小
    cout << "整个数组占用内存空间：" << sizeof(arr) << endl;
    cout << "数组单个元素占用内存空间：" << sizeof(arr[0]) << endl;
    cout << "数组中元素个数：" << sizeof(arr) / sizeof(arr[0]) << endl;

    // 查看首位地址
    cout << "数组的首位地址：" << arr << endl;
    cout << "数组第一个元素的首位地址：" << &arr[0] << endl;

    // 数组名是常量，不可以进行赋值操作
    // arr = 100;
    
    system("pause");

    return 0;
}
```

**五只小猪称体重**：记录五只小猪的体重，如：`int arr[5] = {300, 350, 200, 400, 250};`，找出并打印最重的小猪体重。

```
#include <iostream>
using namespace std;

int main(){
    
    int max = 300;
    int arr[5] = {300, 350, 200, 400, 250};

    for (int i = 0; i < 5; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        else
        {
            continue;
        }
    }

    cout << "最重的小猪体重为" << max << endl;
    
    system("pause");

    return 0;
}
```

**数组元素逆置**：声明一个 5 个元素的数组，并且将元素逆置。

```
#include <iostream>
using namespace std;

int main(){
    
    int start = 0;
    int arr[5] = {1, 2, 3, 4, 5};
    int end = sizeof(arr) / sizeof(arr[0]) - 1;
    
    cout << "逆置前" << endl;
    for (int i = 0; i < 5; i++)
    {
       cout << arr[i] << endl; 
    }

    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }

    cout << "逆置后" << endl;
    for (int i = 0; i < 5; i++)
    {
       cout << arr[i] << endl; 
    }
    
    
    system("pause");

    return 0;
}
```

### 5.2.3 冒泡排序

**作用**：最常见的排序算法，对数组内元素进行排序

1. 比较相邻的元素。如果第一个比第二个大，就交换他们两个。

2. 对每一对相邻元素做同样的工作，执行完毕后，找到第一个最大值。

3. 重复以上的步骤，每次比较次数-1，直到不需要比较。

示例：

将数组{4, 2, 8, 0, 5, 7, 1, 3, 9}进行升序排序。

```
#include <iostream>
using namespace std;

int main(){

    int arr[9] = {4, 2, 8, 0, 5, 7, 1, 3, 9};

    cout << "排序前：" << endl;
    for (int i = 0; i < 9; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // 开始冒牌排序
    /* 排序总轮数 = 元素个数 - 1
       每轮对比次数 = 元素个数 - 排序轮数 -1 */
    for (int i = 0; i < 9 - 1; i++)
    {
        for (int j = 0; j < 9 - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            else
            {
                continue;
            }
        }        
    }

    cout << "排序前：" << endl;
    for (int i = 0; i < 9; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    system("pause");

    return 0;
}
```

## 5.3 二维数组

### 5.3.1 二维数组定义方式

二维数组定义的四种方式：

1. `数据类型 数组名[ 行数 ][ 列数 ];`
2. `数据类型 数组名[ 行数 ][ 列数 ] = { {数据1, 数据2}, {数据3, 数据4} };`
3. `数据类型 数组名[ 行数 ][ 列数 ] = {数据1, 数据2, 数据3, 数据4};`
4. `数据类型 数组名[  ][ 列数 ] = {数据1, 数据2, 数据3, 数据4};`

> 建议使用第二种，比较明晰

```
#include <iostream>
using namespace std;

int main(){

    // 1. 数据类型 数组名[ 行数 ][ 列数 ];
    int arr[2][3];
    arr[0][0] = 1;
    arr[0][1] = 5;
    arr[0][2] = 4;
    arr[1][0] = 3;
    arr[1][1] = 4;
    arr[1][2] = 8;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // 2. 数据类型 数组名[ 行数 ][ 列数 ] = { {数据1, 数据2}, {数据3, 数据4} };
    int arr2[2][3] = 
    {
        {5, 2, 3},
        {7, 5, 6}
    };
    
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr2[i][j] << " ";
        }
        cout << endl;
    } 

    // 3. 数据类型 数组名[ 行数 ][ 列数 ] = {数据1, 数据2, 数据3, 数据4};
    int arr3[2][3] = {1, 5, 6, 8, 4, 6};
    
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr3[i][j] << " ";
        }
        cout << endl;
    } 

    // 4. 数据类型 数组名[  ][ 列数 ] = {数据1, 数据2, 数据3, 数据4};
    int arr4[][3] = {1, 5, 6, 8, 4, 6};
    
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr4[i][j] << " ";
        }
        cout << endl;
    } 

    system("pause");

    return 0;
}
```

### 5.3.2 二维数组组名

- 查看二维数组所占内存空间
- 获取二维数组首地址

示例：

```
#include <iostream>
using namespace std;

int main(){

    
    int arr[2][3] = 
    {
        {5, 2, 3},
        {7, 5, 6}
    };
    
    // 内存占用
    cout << "数组所占的内存空间：" << sizeof(arr) << endl;
    cout << "数组一行元素所占的内存空间：" << sizeof(arr[0]) << endl;
    cout << "数组元素所占的内存空间：" << sizeof(arr[0][0]) << endl;
    cout << "数组行数所占的内存空间：" << sizeof(arr) / sizeof(arr[0]) << endl;
    
    // 首地址
    cout << "数组的首地址：" << arr << endl;
    cout << "数组第一行的首地址：" << arr[0] << endl;
    cout << "数组第一元素的首地址：" << &arr[0][0] << endl;
    
    system("pause");

    return 0;
}
```

### 5.3.3 二维数组应用案例

**考试成绩统计**：有三名同学 (张三、李四、王五)，在一次考试中的成绩分别如下表，请分别输出三名同学的总成绩。

|   | 语文 | 数学 | 英语 |
| --- | --- | --- | --- |
| 张三 | 100 | 100 | 100 |
| 李四 | 90 | 50 | 100 |
| 王五 | 60 | 70 | 80 |

```
#include <iostream>
using namespace std;
#include <string>

int main(){

    
    int score[3][3] = 
    {
        {100, 100, 100},
        {90, 50, 100},
        {60, 70, 80}
    };
    
    string name[3] = {"张三", "李四", "王五"};

    // 统计每个人总分
    for (int i = 0; i < 3; i++)
    {
        int sum = 0;
        for (int j = 0; j < 3; j++)
        {
            sum += score[i][j];
        }
        cout << name[i] << "的总分为：" << sum << endl;
    }
       
    system("pause");

    return 0;
}
```

# 6 函数

## 6.1 概述

**作用**：将一段经常使用的代码封装起来，减少重复代码

一个较大的程序，一般分为若干个程序块，每个模块实现特定的功能。

## 6.2 函数的定义

函数的定义一般主要有 5 个步骤：

1. 返回值类型
2. 函数名
3. 参数列表
4. 函数体语句
5. return 表达式

**语法**：

```
返回值类型 函数名 (参数列表)
{

    函数体语句

    return 表达式

}
```

示例：实现一个加法函数，功能是，传入两个整型数据，计算数据相加的结果，并返回。

```
#include <iostream>
using namespace std;

// 函数的定义
int add(int num1, int num2)
{
    int num = num1 + num2;
    return num;
}

int main(){
    system("pause");
    return 0;
}
```

## 6.3 函数的调用

1. **作用**：调用定义的函数

2. **语法**：`函数名 (参数)`

3. 函数定义时的参数是形参，调用函数时的参数是实参

示例：

```
#include <iostream>
using namespace std;

// 函数的定义，num1 和 num2 是形参
int add(int num1, int num2)
{
    int num = num1 + num2;
    return num;
}

int main(){

    // main 函数中调用 add 函数，a 和 b 是实参
    int a = 10;
    int b = 20;

    // 调用函数

    int c = add(a, b);

    cout << "c = " << c << endl;

    system("pause");
    return 0;
}
```

## 6.4 值传递

1. 函数调用时实参将数值传入给形参

2. 值传递过程中，**如果形参发生改变，不会影响实参**

示例：

```
#include <iostream>
using namespace std;

// 函数的定义，实现两个数字进行交换
// 如果函数不需要返回值，声明可以用 void

void swap(int num1, int num2)
{
    cout << "交换前：" << endl;
    cout << "num1 = " << num1 << endl;
    cout << "num2 = " << num2 << endl;
    int temp = num1;
    num1 = num2;
    num2 = temp;

    cout << "交换后：" << endl;
    cout << "num1 = " << num1 << endl;
    cout << "num2 = " << num2 << endl;
    
    // return; // 返回值不需要的时候，可以不写
}

int main(){

    // main 函数中调用 add 函数，a 和 b 是实参
    int a = 10;
    int b = 20;

    // 调用函数
    // 当值传递时，形参发生改变，并不影响实参
    swap(a, b);

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    system("pause");
    return 0;
}
```

## 6.5 函数的常见样式

常见的函数样式有 4 种：

1. 无参无返
2. 有参无返
3. 无参有返
4. 有参有返

示例：

```
#include <iostream>
using namespace std;

// 1. 无参无返
void test01()
{
    cout << "this is test01" << endl;
}

// 2. 有参无返
void test02(int a)
{
    cout << "this is test02 a = " << a << endl;
}

// 3. 无参有返
int test03()
{
    cout << "this is test03" << endl;
    return 1000;
}

// 4. 有参有返
int test04(int a)
{
    cout << "this is test04 a = " << a << endl;
    return a;
}

int main(){

    test01();
    test02(4);
    int num1 = test03();
    cout << "num1 = " << num1 << endl;
    test04(2);

    system("pause");
    return 0;
}
```

## 6.6 函数的声明

**作用**：告诉编译器函数名称及如何调用函数，函数的实际主体可以单独定义。

- 函数的**声明可以多次**，但是函数的**定义只能有一次**

示例：

```
#include <iostream>
using namespace std;

// 提前告诉编译器函数的存在，可以利用函数的声明
// 声明
int max(int a, int b);

int main(){

    int a = 10;
    int b = 20;

    cout << max(a, b) << endl;

    system("pause");
    return 0;
}

// 定义
int max(int a, int b)
{
    return a > b ? a : b;
}
```

## 6.7 函数的分文件编写

**作用**：让代码结构更加清晰

函数分文件编写一般有 4 个步骤：

1. 创建后缀名为 `.h` 的头文件
2. 创建后缀名为 `.cpp` 的源文件
3. 在头文件中写函数声明
4. 在源文件中写函数的定义

示例：

> `swap.h` 头文件

```
// 函数声明
void swap(int a, int b);
```

> `swap.cpp` 源文件

```
#include <iostream>
#include "swap.h"
using namespace std;


// 函数定义
void swap(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}
```

> `main.cpp` 主文件
```
#include <iostream>
#include "swap.h"
using namespace std;

int main(){

    int a = 10;
    int b = 20;
    swap(a, b);

    system("pause");

    return 0;

}
```

# 7 指针

## 7.1 指针的基本概念

**指针的作用**：可以通过指针间接访问内存

- 内存编号是从 0 开始记录的，一般用十六进制数字表示
- 可以利用指针变量保存地址

## 7.2 指针变量的定义和使用

**指针定义的语法**：`数据类型 * 指针变量名`

示例：

```
#include <iostream>
using namespace std;

int main(){

    // 1. 定义指针
    int a = 10;
    int * p;
    // 让指针记录变量 a 的地址
    p = &a;
    cout << "a 的地址为：" << &a << endl;
    cout << "指针 p 为：" << p << endl;

    // 2. 使用指针
    // 可以通过解引用的方式来找到指针指向的内存
    // 指针前加 * 代表解引用，找到指针指向的内存中的数据
    *p = 1000;
    cout << "a = " << a << endl;
    cout << "*p 为：" << *p << endl;


    system("pause");

    return 0;
}
```

## 7.3 指针所占内存空间

提问：指针也是数据类型，那么这种数据类型占用多少内存空间？

- 在 32 位系统 上，指针大小通常是 4 字节。
- 在 64 位系统 上，指针大小通常是 8 字节。

示例：

```
#include <iostream>
using namespace std;

int main(){

    int a = 10;
    int * p = &a;
    
    cout << *p << endl;
    cout << sizeof(p) << endl;
    cout << sizeof(int *) << endl;
    cout << sizeof(char *) << endl;
    cout << sizeof(float *) << endl;
    cout << sizeof(double *) << endl;

    system("pause");

    return 0;
}
```

## 7.4 空指针和野指针

1. **空指针**：指针变量内存中编号为 0 的空间

2. **野指针**：指针变量指向非法的内存空间，程序中尽量避免出现野指针

3. **用途**：初始化指针变量

4. **注意**：空指针指向的内存是不可以访问的，内存编号 0 ~ 255 为系统占用内存，不允许用户访问

示例 1 ：空指针

```
#include <iostream>
using namespace std;

int main(){

    int * p = NULL;

    // *p = 100; // 不可以访问
    
    cout << *p << endl;

    system("pause");

    return 0;
}
```


示例 2 ：野指针

```
#include <iostream>
using namespace std;

int main(){

    int * p = (int *)0x1100;
    
    cout << *p << endl;

    system("pause");

    return 0;
}
```

## 7.5 const 修饰指针

const 修饰指针有三种情况：

1. const 修饰指针   --- 常量指针：指针的指向可以改，但是指针指向的值不可以改

```
int a = 10;
int b = 20;

const int * p = &a;

// *p = 20; // 错误，不可以改指针指向的值
p = &b;  // 正确，可以改指针指向
```

2. const 修饰常量   --- 指针常量：指针的指向不可以改，指针指向的值可以改

```
int a = 10;
int b = 20;

int * const p = &a;

*p = 20; // 正确，可以改指针指向的值
// p = &b;  // 错误，不可以改指针指向
```


3. const 既修饰指针，又修饰常量：指针的指向和指针指向的值都不可以改

```
int a = 10;
int b = 20;

const int * const p = &a;

// *p = 20; // 错误，不可以改指针指向的值
// p = &b;  // 错误，不可以改指针指向
```

## 7.6 指针和数组

**作用**：利用指针访问数组中元素

示例：

```
#include <iostream>
using namespace std;

int main(){

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int * p = arr; // 指向数组的指针

    cout << "第一个元素：" << arr[0] << endl;
    cout << "指针访问第一个元素：" << *p << endl;
    
    for (int i = 0; i < 10; i++)
    {
        // 利用指针遍历数组
        cout << *p << endl;
        p++; // 指针自增，根据指针类型大小增加
    }

    system("pause");

    return 0;
}
```

## 7.7 指针和函数

**作用**：利用指针作函数参数，可以修改实参的值 (地址传递)

示例：

```
#include <iostream>
using namespace std;

void swap01(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
    cout << "swap01 a = " << a << endl;
    cout << "swap01 b = " << b << endl;
}

void swap02(int *p1, int *p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
    cout << "swap02 *p1 = " << *p1 << endl;
    cout << "swap02 *p2 = " << *p2 << endl;

}


int main(){

    // 1. 值传递
    int a = 10;
    int b = 20;
    // swap01(a, b);
    
    // 2. 地址传递
    // 如果是地址传递，则可以修改实参
    swap02(&a, &b);

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    system("pause");

    return 0;

}
```

## 7.8 指针、数组、函数

**案例描述**：封装一个函数，利用冒泡排序，实现对整型数组的升序排序

**数组传参时会退化成指针，所以看起来是 “值传递”，其实是 “地址传递”，会直接修改原数组**

例如数组：int arr[10] = {2, 9, 7, 10, 4, 5, 6, 3, 8, 1}

示例：

```
#include <iostream>
using namespace std;

void bubbleSort(int * arr, int len) // int * arr 也可以写成 int arr[]，
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printArray(int * arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << endl;
    }
}

int main(){

    int arr[10] = {2, 9, 7, 10, 4, 5, 6, 3, 8, 1};

    int len = sizeof(arr) / sizeof(arr[0]);

    bubbleSort(arr, len);

    printArray(arr, len);

    system("pause");

    return 0;

}
```

# 8 结构体

## 8.1 结构体基本概念

结构体属于用户**自定义的数据类型**，允许用户存储不同的数据类型

## 8.2 结构体定义和使用

**语法**：`struct 结构体名 {结构体成员列表}`

通过结构体创建变量的方式有三种：

- struct 结构体 变量名;
- struct 结构体 变量名 = {成员1值, 成员2值...};
- 定义结构体时顺便创建变量

示例：

```
#include <iostream>
using namespace std;
#include <string>

// 创建学生数据类型，学生包括 (姓名、年龄、分数)
// 自定义数据类型，一些类型集合组成一个类型

struct Student
{
    string name;
    int age;
    int score;
}s3; // 顺便创建结构体变量

// 通过学生类型创建具体学生

int main(){

    // 1. struct Student s1
    struct Student s1;
    // 给 s1 属性赋值，通过 . 访问结构体变量中的属性
    s1.name = "张三";
    s1.age = 18;
    s1.score = 100;

    cout << "姓名：" << s1.name << " 年龄：" << s1.age << " 分数：" << s1.score << endl;

    // 2. struct Student s2 = {...}
    struct Student s2 = {"李四", 19, 80};

    cout << "姓名：" << s2.name << " 年龄：" << s2.age << " 分数：" << s2.score << endl;

    // 3. 定义结构体时顺便创建变量
    s3.name = "王五";
    s3.age = 20;
    s3.score = 70;

    cout << "姓名：" << s3.name << " 年龄：" << s3.age << " 分数：" << s3.score << endl;
    

    system("pause");

    return 0;

}
```

## 8.3 结构体数组

1. **作用**：将自定义的结构体放入到数组中方便维护

2. **语法**：`struct 结构体 数组名[元素个数] = { {}, {}, ... {} };`

示例：

```
#include <iostream>
using namespace std;
#include <string>

// 创建学生数据类型，学生包括 (姓名、年龄、分数)
// 自定义数据类型，一些类型集合组成一个类型

struct Student
{
    string name;
    int age;
    int score;
};

int main(){

    // 结构体数组
    struct Student stuArray[3] = 
    {
        {"张三", 18, 100},
        {"李四", 19, 80},
        {"王五", 20, 60},
    };

    // 给结构体数组中的元素赋值
    stuArray[2].name = "赵六";
    stuArray[2].age = 19;
    stuArray[2].score = 90;

    // 遍历结构体数组
    for (int i = 0; i < 3; i++)
    {
        cout << "姓名为" << stuArray[i].name 
             << " 年龄为" << stuArray[i].age 
             << " 分数为" << stuArray[i].score << endl;
    }

    system("pause");

    return 0;

}
```

## 8.4 结构体指针

**作用**：通过指针访问结构体中的成员

- 利用操作符 `->` 可以通过结构体指针访问结构体属性

示例：

```
#include <iostream>
using namespace std;
#include <string>

// 创建学生数据类型，学生包括 (姓名、年龄、分数)
// 自定义数据类型，一些类型集合组成一个类型

struct Student
{
    string name;
    int age;
    int score;
};

int main(){

    struct Student stu = {"张三", 18, 100};

    // 通过指针指向结构体变量
    struct Student * p = &stu;

    // 通过指针访问结构体变量中的数据
    cout << "姓名：" << p->name 
         << " 年龄：" << p->age 
         << " 分数：" << p->score << endl;

    system("pause");

    return 0;

}
```

## 8.5 结构体嵌套结构体

1. **作用**：结构体中的成员可以是另一个结构体

2. **例如**：每个老师辅导一个学员，一个老师的结构体中，记录一个学生的结构体

示例：

```
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

// 教师结构体定义

struct Teacher
{
    // 成员列表
    int id; // 职工编号
    string name; // 教师姓名
    int age; // 教师年龄
    struct Student stu; // 子结构体，辅导的学生
};

int main(){

    Teacher t;
    t.id = 001;
    t.name = "张八";
    t.age = 30;
    t.stu.name = "张三";
    t.stu.age = 18;
    t.stu.score = 100;

    cout << "老师姓名：" << t.name
         << " 老师编号：" << t.id
         << " 老师年龄：" << t.age 
         << " 老师辅导的学生姓名：" << t.stu.name 
         << " 老师辅导的学生年龄：" << t.stu.age
         << " 老师辅导的学生分数：" << t.stu.score
         << endl;

    system("pause");

    return 0;

}
```

## 8.6 结构体做函数参数

**作用**：将结构体作为参数向函数中传递

传递方式有两种：

- 值传递
- 地址传递

示例：

```
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

// 1. 值传递
void printStudent1(struct Student stu)
{
    stu.score = 70;
    cout << "子函数中 姓名：" << stu.name
         << " 年龄：" << stu.age
         << " 分数：" << stu.score << endl;
}

// 2. 地址传递
void printStudent2(struct Student * stu)
{
    stu->score = 50;
    cout << "子函数中 姓名：" << stu->name
         << " 年龄：" << stu->age
         << " 分数：" << stu->score << endl;
}


int main(){

    Student stu;
    stu.name = "张三";
    stu.age = 18;
    stu.score = 100;

    printStudent1(stu);
    printStudent2(&stu);

    system("pause");

    return 0;

}
```

## 8.7 结构体中 const 使用场景

**作用**：用 const 来防止误操作

将函数中的形参改为指针，可以减少内存空间，而且不会复制新的副本出来

示例：

```
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
// 将函数中的形参改为指针，可以减少内存空间
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
```

## 8.8 结构体案例

### 8.8.1 案例 1

学校正在做毕业设计，每名老师带领 5 个学生，总共有 3 名老师，需求如下

设计学生和老师的结构体，其中在老师的结构体中，有老师姓名和一个存放 5 名学生的数组作为成员，学生的成员有姓名、考试分数，创建数组存放 3 名老师，通过函数给每个老师及所带学生赋值，最终打印出老师数据以及老师所带的学生数据。

```
#include <iostream>
using namespace std;
#include <string>
#include <cstdlib>
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

            int random = rand() % 61 +40; // 41 ~ 100
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

    // 随机种子
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
```

### 8.8.2 案例 2

设计一个英雄的结构体，包括组员姓名、年龄、性别，创建结构体数组，数组中存放 5 名英雄。通过冒泡排序的算法，将数组中的英雄按照年龄进行升序排序，最终法院排序后的结构。

五名英雄的信息如下：

```
{"刘备", 23, "男"},
{"关羽", 22, "男"},
{"张飞", 23, "男"},
{"赵云", 21, "男"},
{"貂蝉", 19, "女"},
```

```
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
void bubble(struct hero arr[], int len)
{

    
    // 给老师赋值
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len -1; j++)
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

    bubble(arr, len);

    printInfo(arr, len);

    system("pause");

    return 0;

}
```
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
    cout << "数组的首位地址：" << (int)arr << endl;
    cout << "数组第一个元素的首位地址：" << (int)&arr[0] << endl;

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
    
    int i = 0;
    int max = 300;
    int arr[5] = {300, 350, 200, 400, 250};

    for (i = 0; i < 5; i++)
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
    
    int i = 0;
    int start = 0;
    int arr[5] = {1, 2, 3, 4, 5};
    int end = sizeof(arr) / sizeof(arr[0]) - 1;
    
    cout << "逆置前" << endl;
    for (i = 0; i < 5; i++)
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
    for (i = 0; i < 5; i++)
    {
       cout << arr[i] << endl; 
    }
    
    
    system("pause");

    return 0;
}
```
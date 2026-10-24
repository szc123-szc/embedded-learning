# Week 02：C语言复习（位运算、宏、模块化、状态机）

每天的代码放在各自的子文件夹里。

## 每日内容

| 文件夹 | 内容 | 文件 |
|---|---|---|
| mon | 位运算与掩码练习 | 2幂.c、掩码.c |
| tue | volatile 示例、条件编译 | Volatile.c、条件编译.c |
| wed | 大小端检测、用一个字节模拟8个标志位 | 大小端检测.c、字节模拟标志位.c |
| thu | 把计算器和计数器拆成多文件工程 | calculator.c/.h、counter.c/.h、main.c |
| fri | switch-case 按键状态机（电脑上模拟） | SWITCH状态机.c |
| sat | 项目：8个LED状态寄存器命令行程序 | main.c、command.c/.h、led.c/.h |

## 周六项目：LED 寄存器命令行程序

用一个 `uint8_t` 当作8个LED的状态寄存器（bit0 对应 LED0，bit7 对应 LED7，1 亮 0 灭），
用文字命令控制，综合用到位运算、状态机和多文件。

### 命令

| 命令 | 作用 |
|---|---|
| `ON n` | 点亮第 n 个灯 |
| `OFF n` | 熄灭第 n 个灯 |
| `TOGGLE n` | 翻转第 n 个灯 |
| `SHOW` | 显示8个灯的状态 |

n 的范围是 0~7，命令不区分大小写，多个空格可以。错误命令返回 `ERROR`，不影响后续命令。

### 运行示例

```
>ON 3
OK
>SHOW
LED: 0000 1000
OK
>ON 8
ERROR
```

### 文件分工

- `led.c / led.h`：管寄存器，`static` 变量保存状态，提供 `led_on`、`led_off`、`led_tog`、`led_show`
- `command.c / command.h`：管解析，用4个状态（ST_CMD、ST_GAP、ST_NUM、ST_ERR）逐字符解析命令
- `main.c`：读一行输入，调用解析函数，打印 OK 或 ERROR

### 编译运行

在 Visual Studio 里新建控制台项目，把 sat 文件夹里的5个文件加入项目，直接运行。
用 gcc 的话：

```
gcc main.c command.c led.c -o led_cli
```

## 本周易错点

- 状态机的状态变量必须写在函数里，每次调用重新初始化，写成全局变量会让上一条命令的状态残留
- 数字要边读边检查范围，读完再检查会溢出，强转成 `uint8_t` 还会截断（例如 259 变成 3）
- 数字字符要减 `'0'` 才是数值
- 扫描字符串要同时认 `\0`、`\n`、`\r` 作为结束

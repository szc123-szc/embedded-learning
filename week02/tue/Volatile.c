#include <stdio.h>
#include <signal.h>

volatile sig_atomic_t flag = 0;//sig_atomic_t：C 标准规定的一种整数类型，保证读写它是原子的（不会被信号打断在半途）。信号处理函数里改的变量，标准推荐用这个类型。它通常就是 int。

void handler(int sig)//参数 sig 是触发它的信号编号,这里用不到，但函数签名必须是 void f(int)
{
    flag = 1;
}

int main(void)
{
    signal(SIGINT, handler);//注册：告诉系统"收到 SIGINT 信号时，去调用 handler",不用main调用。SIGINT 是"中断信号"，在终端按 Ctrl+C 就会产生它。
    printf("按 Ctrl+C\n");
    while (!flag) {}
    printf("收到中断\n");
    return 0;
}

#include <stdio.h>
// auto 存储类是所有局部变量默认的存储类。
// register 存储类用于定义存储在寄存器中而不是 RAM 中的局部变量。这意味着变量的最大尺寸等于寄存器的大小（通常是一个词），且不能对它应用一元的 '&' 运算符（因为它没有内存位置）。
// static 存储类指示编译器在程序的生命周期内保持局部变量的存在，而不需要在每次它进入和离开作用域时进行创建和销毁。
// extern 存储类用于提供一个全局变量的引用，全局变量对所有的程序文件都是可见的。 
/* 函数声明 */
void func1(void);
 
int count = 20;        /* 全局变量 - static 是默认的 */
 
int main()
{
  count = 30;  
  while (count--) {
      func1();
  }
  return 0;
}
 
void func1(void)
{
/* 'thingy' 是 'func1' 的局部变量 - 只初始化一次
 * 每次调用函数 'func1' 'thingy' 值不会被重置。
 */                
  static int thingy=5;
  thingy++;
  printf(" thingy = %d , count = %d\n", thingy, count);
}
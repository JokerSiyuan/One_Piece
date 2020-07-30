#include "system.h"
#include <unistd.h>
#include <getch.h>


int main()
{
//	debug("%s\n",__func__);
	//初始化系统，加载数据
	init_system();
	//进入系统，运行系统
	run_system();
	//退出系统，保存数据
	exit_system();
}

#include "Hufman_Tree.h"
#include "BM.h"
#include "index.h"
#include "Congress.h"
#include "Extract.h"
#include "Execute.h"
#include <windows.h>
using namespace std;

int main()
{
    system("color");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),48);
    printf("\n**Welcome to WHJ's amazing zip tool cabinet!\n**You can compress, extrace, and index from any existing files\n");
    printf("**Now let's begin\n");
    for(int i = 1; i <= 45; i++)
        printf("*");
    printf("\n\n");
    while(1)
    {
        int func, flag = 0;		// 每次进入循环都要初始化flag为0
        char ifname[20], ofname[20], Frname[20];		// 保存输入输出源文件名;
        // 输入功能序号：1：压缩，2：解压，3：检索，4：退出
        printf("Please input the number of operations:\n 1: compress\n 2: extract\n 3: index\n 4: quit\n\n");
        for(int i = 1; i <= 45; i++)
            printf("*");
        printf("\n");
        scanf("%d", &func);
        if (func == 4)
            break;

        switch(func)
        {
            case 1: flag = execute1(ifname, ofname);
                break;
            case 2: flag = execute2(ifname, ofname);
                break;
            case 3: flag = execute3(Frname);
                break;
            case 4: printf("Quit...\n");
                return 0;
        }
        if (flag == -1)
            printf("Ops! infile \"%s\" is not existed!\n", ifname);		// 如果标志为‘-1’则输入文件不存在
        else
            printf("Finished!\n");		// 操作完成
    }

    return 0;
}

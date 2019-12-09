#include <stdio.h>
int main(int argc, const char * argv[]) {
    int num = 0;
    int arr[5][5] = {0};        //电影院的几排几列
    int row = 0;
    int line = 0;
    int baby = 1;
    printf("*********欢迎光临怪小魔e的购票系统***********\n");
    printf("************查询座位信息请输入0**************\n");
    printf("****************购票请输入1*****************\n");
    printf("****************退票请输入2*****************\n");
    printf("*************退出系统请输入3*****************\n");
    
    while (baby) {
        scanf("%d",&num);
        switch (num) {
            case 0:
            {
                printf("查询座位信息:\n");
                for (int i=0; i<5; i++) {
                    for (int j=0; j<5; j++) {
                        printf("[%d]",arr[i][j]);
                    }
                    printf("\n");
                }
                printf("*****购票请输入1;退票请输入2;退出系统请输入3******\n");
                
                break;
            }
            case 1:
            {
                printf("购票:\n");
                printf("请输入行号:\n");
                scanf("%d",&row);
                printf("请输入列号:\n");
                scanf("%d",&line);
                if (arr[row-1][line-1]==1) {
                    printf("您选择的座位已经出售,请重新输入;\n");
                }else{
                    arr[row-1][line-1]=1;
                    printf("恭喜您购买成功!!\n");
                    
                }
                   printf("********查询座位信息请输入0;购票请输入1;退票请输入2;退出系统请输入3*********");
                
                break;
            }
            case 2:
            {
                printf("退票:\n");
                printf("请输入座位行号:\n");
                scanf("%d",&row);
                printf("请输入座位列数:\n");
                scanf("%d",&line);
                if (arr[row-1][line-1]==0) {
                    printf("输入错误,请重新输入!\n");
                }else{
                    arr[row-1][line-1] = 0;
                    printf("退票成功!\n");
                }
                   printf("********查询座位信息请输入0;购票请输入1;退票请输入2;退出系统请输入3*********");
                
                
                break;
            }
            case 3:
            {
                printf("退出系统成功!!欢迎下次光临****\n");
                baby = 0;
                break;
            }
            default:
                break;
        }
        
    }
    
    
    
    
    return 0;
}

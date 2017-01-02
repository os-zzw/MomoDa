#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main(int ac, char *av[]) {

    int sock;
    char str[20];
    char buf[20];
    int number = 0;
    int score=0;

    struct sockaddr_in serv_addr;

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("socket failure!\n");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_addr.sin_port = htons(1234);

    if (connect(sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) != 0) {
        printf("connect failure!\n");
        exit(1);
    }

    //欢迎你玩么么答游戏!!!好的现在游戏开始了哦!
    printf("欢迎你玩 么么答 游戏!!!准备好了吗?现在游戏开始了哦!\n");
    while (1) {
        //这是第几道题
        number++;

        memset(&buf, 0, sizeof(buf));
        //问题:
        switch (number) {
            case 1:
                printf("下列哪个不是文件的逻辑结构:\n");//b
                printf("a:链表结构\n");
                printf("b:顺序结构\n");
                printf("c:层次结构\n");
                printf("d:树形结构\n");
                break;
            case 2:
                printf("如果将固定块大小的文件系统中的块大小设置大一些，会造成:\n");//a
                printf("a:更好的磁盘吞吐量和更差的磁盘空间利用率\n");
                printf("b:更好的磁盘吞吐量和更好的磁盘空间利用率\n");
                printf("c:更差的磁盘吞吐量和更好的磁盘空间利用率\n");
                printf("d:更差的磁盘吞吐量和更差的磁盘空间利用率\n");
                break;
            case 3:
                printf("选择在最近的过去使用次数最少的页面予以淘汰的算法称为:\n");//d
                printf("a:Opt\n");
                printf("b:LRU\n");
                printf("c:MFU\n");
                printf("d:LFU\n");
                break;
            case 4:
                printf("下列关于虚拟存储的叙述中，正确的是（）:\n");//b
                printf("a:虚拟存储只能基于连续分配技术\n");
                printf("b:虚拟存储只能基于非连续分配技术\n");
                printf("c:虚拟存储只受外存容量的限制\n");
                printf("d:虚拟存储只受内存容量的限制\n");
                break;
            case 5:
                printf("系统\"抖动\"现象的发生是由（）引起的？:\n");//a
                printf("a:置换算法不当\n");
                printf("b:交换的信息量过大\n");
                printf("c:内存容量充足\n");
                printf("d:请求页式管理方案\n");
                break;
        }


        scanf("%s", str);

        switch (number){
            case 1:
                if (str[0]=='b'){
                    score++;
                }
                break;
            case 2:
                if (str[0]=='a'){
                    score++;
                }
                break;
            case 3:
                if (str[0]=='d'){
                    score++;
                }
                break;
            case 4:
                if (str[0]=='b'){
                    score++;
                }
                break;
            case 5:
                if (str[0]=='a'){
                    score++;
                }
                break;
        }

        write(sock, str, sizeof(str));
        read(sock, buf, sizeof(buf));
        printf("Message from Server: %s\n", buf);

        if (number == 5) {
           printf("游戏结束了\n");
            char result[40] = "您最终的得分是:\n";
            char tmp[10];
            sprintf(tmp, "%d", score);
            strcat(result,tmp);
            printf(result);
            exit(1);
        }


    }


    close(sock);

    return 0;
}

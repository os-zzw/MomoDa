#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {

    struct sockaddr_in serv_addr;
    struct sockaddr_in clnt_addr;

    int serv_sock;
    char buf[20];
    char buffer[40];
    int score = 0;
    int number = 0;


    socklen_t clnt_addr_size = sizeof(clnt_addr);
    int clnt_sock;

    if ((serv_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1) {
        printf("socket failure!\n");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_addr.sin_port = htons(1234);

    if (bind(serv_sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) != 0) {
        printf("bind failure!\n");
        exit(1);
    }

    if (listen(serv_sock, 20) != 0) {
        printf("listen failure!\n");
        exit(1);
    }

    while (1) {

        int rv;

        clnt_sock = accept(serv_sock, (struct sockaddr *) &clnt_addr, &clnt_addr_size);

        while ((rv = fork()) == -1);

        if (rv == 0) {

            while (1) {
                //这是第几道题
                number++;

                if (read(clnt_sock, buffer, sizeof(buffer) - 1) == -1) {
                    printf("read failure!\n");
                    exit(1);
                }

                switch (number) {
                    case 1:
                        if (buffer[0] == 'b') {
                            char reply[40] = "恭喜你答对了";
                            score++;
                            if (write(clnt_sock, reply, strlen(reply)) == -1) {
                                printf("write failure!\n");
                                exit(1);
                            }
                        } else {
                            char reply[40] = "好笨哦,答错了";
                            if (write(clnt_sock, reply, strlen(reply)) == -1) {
                                printf("write failure!\n");
                                exit(1);
                            }
                        }
                        break;
                    case 2:
                        if (buffer[0] == 'a') {
                            char reply[40] = "恭喜你答对了";
                            score++;
                            if (write(clnt_sock, reply, strlen(reply)) == -1) {
                                printf("write failure!\n");
                                exit(1);
                            }
                        } else {
                            char reply[40] = "好笨哦,答错了";
                            if (write(clnt_sock, reply, strlen(reply)) == -1) {
                                printf("write failure!\n");
                                exit(1);
                            }
                        }
                        break;
                    case 3:
                        if (buffer[0] == 'd') {
                            char reply[40] = "恭喜你答对了";
                            score++;
                            if (write(clnt_sock, reply, strlen(reply)) == -1) {
                                printf("write failure!\n");
                                exit(1);
                            }
                        } else {
                            char reply[40] = "好笨哦,答错了";
                            if (write(clnt_sock, reply, strlen(reply)) == -1) {
                                printf("write failure!\n");
                                exit(1);
                            }
                        }
                        break;
                    case 4:
                        if (buffer[0] == 'b') {
                            char reply[40] = "恭喜你答对了";
                            score++;
                            if (write(clnt_sock, reply, strlen(reply)) == -1) {
                                printf("write failure!\n");
                                exit(1);
                            }
                        } else {
                            char reply[40] = "好笨哦,答错了";
                            if (write(clnt_sock, reply, strlen(reply)) == -1) {
                                printf("write failure!\n");
                                exit(1);
                            }
                        }
                        break;
                    case 5:
                        if (buffer[0] == 'a') {
                            char reply[40] = "恭喜你答对了";
                            score++;
                            if (write(clnt_sock, reply, strlen(reply)) == -1) {
                                printf("write failure!\n");
                                exit(1);
                            }
                        } else {
                            char reply[40] = "好笨哦,答错了";
                            if (write(clnt_sock, reply, strlen(reply)) == -1) {
                                printf("write failure!\n");
                                exit(1);
                            }
                        }
                        break;
                }

                //答题结束时
                if (number == 5) {
                    char result[1000] = "游戏结束,您最后的得分是";
                    char tmp[100];
                    sprintf(tmp, "%d", score);
                    strcat(result,tmp);
                    if (write(clnt_sock, result, strlen(result)) == -1) {
                        printf("write failure!\n");
                        exit(1);
                    }
                    exit(1);
                }

            }

        }

    }

    close(clnt_sock);
    close(serv_sock);

    return 0;
}


    


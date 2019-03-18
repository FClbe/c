// dian3client.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//


#include "pch.h"
#include <iostream>
#include <WS2tcpip.h>
#include <WinSock2.h>
#define DEST_PORT 2019//目标地址端口号 
#define DEST_IP "127.0.0.1"/*目标地址IP，这里设为本机*/ 

int main()
{
	WSADATA  wsd;  //定义WSADATA对象
	WSAStartup(MAKEWORD(2, 2), &wsd);     //初始化套接字
	int sockfd, new_fd;/*cocket句柄和接受到连接后的句柄 */
	struct sockaddr_in dest_addr;/*目标地址信息*/
	char buf[50];//储存接收数据 
	char sendbuf[50];

	sockfd = socket(AF_INET, SOCK_STREAM, 0);/*建立socket*/
	if (sockfd == -1) {
		printf("socket failed:%d", errno);
	}
	//参数意义见上面服务器端 
	struct in_addr s;
	memset(&(dest_addr.sin_zero), 0, 8);
	dest_addr.sin_family = AF_INET;
	dest_addr.sin_port = htons(DEST_PORT);
	inet_pton(AF_INET, DEST_IP, &dest_addr.sin_addr.s_addr);
	

	if (connect(sockfd, (struct sockaddr*)&dest_addr, sizeof(struct sockaddr)) == -1) {//连接方法，传入句柄，目标地址和大小 
		printf("connect failed:%d", errno);//失败时可以打印errno 
	}
	else {
		printf("connect success\n");
		while (1) {
			scanf_s("%s", sendbuf, 50);
			send(sockfd, sendbuf, strlen(sendbuf), 0);
			if (strcmp(sendbuf, "quit") == 0)
				break;
			int length = recv(sockfd, buf, 50, 0);//将接收数据打入buf，参数分别是句柄，储存处，最大长度，其他信息（设为0即可）。 
			buf[length] = '\0';
			printf("Server :%s\n", buf);
		}
		
	}
	closesocket(sockfd);//关闭socket 
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

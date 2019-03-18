
#include "pch.h"
#include <iostream>
#include <WS2tcpip.h>
#include <WinSock2.h>
#define DEST_PORT 2019//目标地址端口号 
#define DEST_IP "127.0.0.1"/*目标地址IP，这里设为本机*/ 
void create();

int main()
{
	WSADATA  wsd;  //定义WSADATA对象
	WSAStartup(MAKEWORD(2, 2), &wsd);     //初始化套接字
	int serverSocket;
	//声明两个套接字sockaddr_in结构体变量，分别表示客户端和服务器
	struct sockaddr_in server_addr;
	struct sockaddr_in clientAddr;
	int addr_len = sizeof(clientAddr);
	int client;
	char buffer[200];
	int iDataNum;
	int flag = 1, len = sizeof(int);
	//socket函数，失败返回-1
	//int socket(int domain, int type, int protocol);
	//第一个参数表示使用的地址类型，一般都是ipv4，AF_INET
	//第二个参数表示套接字类型：tcp：面向连接的稳定数据传输SOCK_STREAM
	//第三个参数设置为0
	if ((serverSocket = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		perror("socket");
		return 1;
	}
	memset(&server_addr, 0, sizeof(server_addr));
	//初始化服务器端的套接字，并用htons和htonl将端口和地址转成网络字节序
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(2019);
	//ip可是是本服务器的ip，也可以用宏INADDR_ANY代替，代表0.0.0.0，表明所有地址
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	
	//对于bind，accept之类的函数，里面套接字参数都是需要强制转换成(struct sockaddr *)
	//bind三个参数：服务器端的套接字的文件描述符，
	if (setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR, (const char*)&flag, len) == -1)
	{
		perror("connect");
		return 1;
	}
	if (bind(serverSocket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
	{
		printf("%d", GetLastError());
		perror("bind");
		return 1;
	}
	//设置服务器上的socket为监听状态
	if (listen(serverSocket, 5) < 0)
	{
		perror("listen");
		return 1;
	}
	while (1)
	{
		printf("监听端口: %d\n", 2019);
		//调用accept函数后，会进入阻塞状态
		//accept返回一个套接字的文件描述符，这样服务器端便有两个套接字的文件描述符，
		//serverSocket和client。
		//serverSocket仍然继续在监听状态，client则负责接收和发送数据
		//clientAddr是一个传出参数，accept返回时，传出客户端的地址和端口号
		//addr_len是一个传入-传出参数，传入的是调用者提供的缓冲区的clientAddr的长度，以避免缓冲区溢出。
		//传出的是客户端地址结构体的实际长度。
		//出错返回-1
		client = accept(serverSocket, (struct sockaddr*)&clientAddr, &addr_len);
		if (client < 0)
		{
			perror("accept");
			continue;
		}
		printf("等待消息...\n");
		//inet_ntoa ip地址转换函数，将网络字节序IP转换为点分十进制IP
		//表达式：char *inet_ntoa (struct in_addr);
		//printf("IP is %s\n", inet_ntop(AF_INET, " ", clientAddr.sin_addr));//inet_ntoa(clientAddr.sin_addr)
		printf("Port is %d\n", htons(clientAddr.sin_port));
		while (1)
		{
			printf("读取消息:");
			iDataNum = recv(client, buffer, 50, 0);
			if (iDataNum < 0)
			{
				perror("recv null");
				continue;
			}
			buffer[iDataNum] = '\0';
			printf("%s\n", buffer);
			printf("发送消息:");
			printf("%s\n", buffer);
			send(client, buffer, iDataNum, 0);
			if (strcmp(buffer, "quit") == 0)
				break;
		}
	}
	//create();
	system("pause");
	closesocket(serverSocket);
	return 0;
}

void create() {

	int sockfd, new_fd;/*cocket句柄和接受到连接后的句柄 */
	struct sockaddr_in dest_addr;/*目标地址信息*/
	char buf[50];//储存接收数据 

	sockfd = socket(AF_INET, SOCK_STREAM, 0);/*建立socket*/
	if (sockfd == -1) {
		printf("socket failed:%d", errno);
	}
	//参数意义见上面服务器端 
	struct in_addr s;
	dest_addr.sin_family = AF_INET;
	dest_addr.sin_port = htons(DEST_PORT);
	dest_addr.sin_addr.s_addr = inet_pton(AF_INET, DEST_IP, (void*)&s);
	memset(&(dest_addr.sin_zero),0, 8);

	if (connect(sockfd, (struct sockaddr*)&dest_addr, sizeof(struct sockaddr)) == -1) {//连接方法，传入句柄，目标地址和大小 
		printf("connect failed:%d", errno);//失败时可以打印errno 
	}
	else {
		printf("connect success");
		recv(sockfd, buf, 50, 0);//将接收数据打入buf，参数分别是句柄，储存处，最大长度，其他信息（设为0即可）。 
		printf("Received:%s", buf);
	}
	closesocket(sockfd);//关闭socket 
}
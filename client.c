#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <arpa/inet.h>
int main(){
	int sock;
	sock = socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in serverAddr;
	serverAddr.sin_family=AF_INET;
	serverAddr.sin_port=htons(8888);
	serverAddr.sin_addr.s_addr=inet_addr("192.168.1.162");
	if(connect(sock,(struct sockaddr*) &serverAddr,sizeof(serverAddr))<0){
		printf("Can't connect\n");
		return 0;
		}
	int nr;
	printf("Introduceti numarul: ");
	scanf("%d",&nr);
	printf("Trimit numarul: %d\n",nr);
	send(sock,&nr,sizeof(int),0);
	int numarPrimit;
	recv(sock,&numarPrimit,sizeof(int),0);
	printf("Am primit: %d\n",numarPrimit);
	
	return 0;	
	}


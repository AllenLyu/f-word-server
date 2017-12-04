#include "stdio.h"
#include "string.h"
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h> // for open
#include <unistd.h> // for close

int main(int argc,char **argvs){
    int listenfd,clientfd;
    socklen_t len;
    struct sockaddr_in serveraddr,clientaddr;
    char buff[1024];

    listenfd = socket(AF_INET,SOCK_STREAM,0);

    memset(&serveraddr,0,sizeof(serveraddr));

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serveraddr.sin_port = htons(6543);

    bind(listenfd,(struct sockaddr *)&serveraddr,sizeof(serveraddr));
    listen(listenfd,1024);

    while(1){
        len = sizeof(clientaddr);
        clientfd = accept(listenfd,(struct sockaddr *)&clientaddr,&len);
        printf("connect from %s,port %d \n",inet_ntop(AF_INET,&clientaddr,buff,sizeof(buff)),ntohs(clientaddr.sin_port));
        snprintf(buff,sizeof(buff),"HTTP/1.1 200 OK");
        close(clientfd);
    }


}
#include "stdio.h"
#include "string.h"
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h> // for open
#include <unistd.h> // for close
#define LISTEN 1
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

    memset(buff,0,sizeof(buff));
    while(LISTEN){
        len = sizeof(clientaddr);
        clientfd = accept(listenfd,(struct sockaddr *)&clientaddr,&len);
        // printf("connect from %s,port %d \n",inet_ntop(AF_INET,&clientaddr,buff,sizeof(buff)),ntohs(clientaddr.sin_port));
        // snprintf(buff,sizeof(buff),"HTTP/1.1 200 OK \r\nContent-type: text\\plain \r\n \r\n\r\n");
        
        // snprintf(buff,sizeof(buff),"\r\n\r\n");
        // snprintf(buff,sizeof(buff),"qqq");

        FILE *f = fopen("/home/baofeng/Project/f-word-server/socket/http_example","r");

        while(!feof(f)){
            fscanf(f,"%s",buff);
            printf("%s",buff);
        }

        fclose(f);
    

        char recv_buff[1024];
        read(clientfd,&recv_buff,sizeof(recv_buff));
        printf("%s",recv_buff);


        write(clientfd,buff,sizeof(buff));
        memset(buff,0,sizeof(buff));
        close(clientfd);
    }


}
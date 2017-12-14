#include "stdio.h"
#include "string.h"
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h> // for close
#include "../http/f_word_request.h"

int main(int argc,char **argvs){
    int listenfd,clientfd;
    socklen_t len;
    struct sockaddr_in serveraddr,clientaddr;
    char buff[128];

    listenfd = socket(AF_INET,SOCK_STREAM,0);

    memset(&serveraddr,0,sizeof(serveraddr));

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serveraddr.sin_port = htons(6543);


    bind(listenfd,(struct sockaddr *)&serveraddr,sizeof(serveraddr));
    listen(listenfd,1024);

    memset(buff,0,sizeof(buff));
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    printf("start listening on port %d",serveraddr.sin_port);
    while(1){
        len = sizeof(clientaddr);
        clientfd = accept(listenfd,(struct sockaddr *)&clientaddr,&len);

        FILE *f = fopen("/home/baofeng/Project/f-word-server/socket/http_example","r");
        fread(buff,sizeof(char),1024,f);
        write(clientfd,buff,sizeof(buff));
        memset(buff,0,sizeof(buff));

        fclose(f);

        char recv_buff[1024];
        read(clientfd,&recv_buff,sizeof(recv_buff));
        printf("%s",recv_buff);

        f_word_request_t *request = get_request(recv_buff);

        close(clientfd);
    }
#pragma clang diagnostic pop


}
#include<iostream>
#include<string>
#include<iostream>
#include<fstream>
#include<stdio.h>
#include"head.h"

using namespace std;

node* load(){
    int i=0;
    node *head,*tail,*p;
    head=tail=new node;

    tail->next=NULL;
    ifstream in("D:\\program\\git\\project1\\tongxunlu\\test.txt");
    if(! in.is_open())
    {cout<<"erro opening file"<<endl;}
    while(!in.eof()){
        p=new node;
        in.read(p->info.no,9);
        in.read(p->info.num,11);
        
       printf("正在读取第%d个数据\n",i);
       i++;
       p->next=NULL;
       tail->next=p;
       tail=p;

    }
    in.close();
    return head;
}

int add(node* head){
    printf("请问你是否添加联系人？<y/n>");
    char h;
    cin>>h;
    if(h=='Y'||h=='y'){
        node* p;
      while(h=='Y'||h=='y'){
        p=new node;
        printf("请输入姓名\n");
        fflush(stdin);
        scanf("%s",p->info.no);
        printf("请输入手机号\n");
        fflush(stdin);
        scanf("%s",p->info.num);
        p->next=head->next;
        head->next=p;
        printf("请问是否还要添加联系人？<y/n>");
        fflush(stdin);
        cin>>h;
          }
    ofstream out("D:\\program\\git\\project1\\tongxunlu\\test.txt",ios::app);
    if(!out.is_open()){
        printf("打开失败\n");
    }
    else{
        while(head->next!=NULL){
            head=head->next;
         out.write(head->info.no,9);
         out.write(head->info.num,11);
         out<<endl;
        }

        out.close();
        printf("保存成功");
    }
    }
    return 0;
}

int freelist(node*head){
    node*p1,*p2;
    p1=p2=head;
    p2=p2->next;
    while(p2!=NULL){
        delete(p1);
        p1=p2;
        p2=p2->next;
    }
    delete(p1);
    return 0;
}
int view(node*head){
    node *p1;
    p1=head;
    if(head->next==NULL){
        printf("链表为空\n");
        return 0;
    }
    printf(".......................................\n");
    printf("姓名            手机号\n");
    p1=head->next;
    while(p1!=NULL){
        printf("%-11s   %s\n",p1->info.no,p1->info.num);
       
        p1=p1->next;
    }
    return 0;
}
int main(){
node* head;
cout<<"正在读取数据，请稍后。。。。"<<endl;
head=load();


    printf("........................\n");
    printf(".......管理通讯系统.......\n");
    printf("欢迎进入通讯录\n");
    printf("请选择\n");
    printf("1.......增加联系人\n");
    printf("2.......查看通讯录\n");
    printf("3.......\n");
    printf("7.......退出\n");
    int s=1;
    cin>>s;
    switch(s){
        case 1:add(head);
        case 2:view(head);
        case 7:freelist(head);exit(0);
        default:printf("erro!请重新输入\n");
    }



}

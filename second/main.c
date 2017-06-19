#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct personnelArchiveInfo{
    char num[15];
    char name[10];
    char sex[5];
    int age;
    char job[10];
    char post[10];
    char politic[10];
    char edu_level[10];
    char period[10];
    char start_time[10];
}PAInfo;
struct link{
    PAInfo data;
    struct link *next;
};

/*�������������еĸ�������*/
void password();//��ӭ��䣬�������롣
struct link *selectMe(int i,struct link *head,int *padd );//ѭ�����ú���
void hello();//��ʼ����

/*�����ǲ˵��ڵİ˸�����*/
struct link *Inputdata(struct link *head,int *padd );//��������ģ��
struct link *ReadandInput(struct link *head,int *padd );//�������ģ��
struct link *DeleteData(struct link *head,int *padd );//����ɾ��ģ��
void InquiryData(struct link *head);//���ݲ�ѯģ��
struct link *ReviseData(struct link *head);//�����޸�ģ��
void DisplayNode(struct link *head,int *padd);//��ʾ�ļ��е�����
struct link *SelectSort(struct link *head);//��������ģ��
void CountData(struct link *head);//ͳ�Ƹ�������

struct link *AppendNode(struct link *head);//���һ������
void DisplyNode(struct link *head);//��ӡ��������ڵ������
void DeleteMemory(struct link *head);//�ͷ��ڴ�
void WritetoFile(struct link *head,int i);//������д���ļ�
void PrintScore(struct link *head);//��ӡ����

int main()
{
    int add;
    int se;
    int a;
    int *padd = &add;
    struct link *head = NULL;
    password();
    for(;;){
    hello();
    printf("���������\n");
    a = scanf("%d",&se);
    while(getchar()!='\n');
    while(a!=1){
    printf("��������ȷ����ţ�\n");
    a = scanf("%d",&se);
    }
    head = selectMe(se,head,padd);
    system("pause");
    system("cls");
    }
    return 0;
}

void password(){//��ӭ��䣬�������롣
    printf("Hello!\n");
    printf("welcome to use the personal management system!\n");
    char password[11] = {"jiangkaida"};
    char s[11];
    int flag = 0;
    int n = 3;
    int m;
    do{
        printf("please input your password:\n");
        for(m = 0;m < 10;m++){
            s[m] = getch();
            putchar('*');
        }
        s[m] = '\0';
        printf("\n");
        if((!strcmp(s,password))){
            printf("land successfully!\n");
            flag = 1;
            break;

        }
        else{
            printf("error!please input again!\n");
            n--;
        }
    }while(n>0);
    if(!flag){
        printf("Input error more than three times!");
        exit(0);
    }
}

void hello(){//��ʼ����
    printf("* * * * * * * * * * * * * * * * * * * \n");
    printf("*      ��ӭʹ�����¹���ϵͳ��       * \n");
    printf("*     �����빦����Ž���ʹ�ã�      * \n");
    printf("*\t1.�½�Ա����Ϣ              * \n");
    printf("*\t2.���Ա����Ϣ              * \n");
    printf("*\t3.ɾ��Ա����Ϣ              * \n");
    printf("*\t4.��ѯԱ����Ϣ              * \n");
    printf("*\t5.�޸�Ա����Ϣ              * \n");
    printf("*\t6.��ʾԱ����Ϣ              * \n");
    printf("*\t7.����Ϣ��������            * \n");
    printf("*\t8.ͳ��Ա����Ϣ              * \n");
    printf("*\t9.�˳�����ϵͳ              * \n");
    printf("* * * * * * * * * * * * * * * * * * * \n");
}

struct link *selectMe(int i,struct link *head,int *padd){//ѭ�����ú���
    if(i == 1){
        head = Inputdata(head,padd);
    }
    else if(i == 2){
        head = ReadandInput(head,padd);
    }
    else if(i == 3){
        head = DeleteData(head,padd);
    }
    else if(i == 4){
        InquiryData(head);
    }
    else if(i == 5){
        head = ReviseData(head);
    }
    else if(i == 6){
        DisplayNode(head,padd);
    }
    else if(i == 7){
        head = SelectSort(head);
    }
    else if(i == 8){
         CountData(head);
    }
    else if(i == 9){
        printf("лл����ʹ�ã�\n");
        exit(0);
    }
    else{
        printf("��������ȷ��ѡ�\n");
    }
    return head;
}

struct link *Inputdata(struct link *head,int *padd){//��������ģ��
    char c;
    char a[20];
    int i = 0;
    *padd = 0;
    int x;
    printf("����Ҫ�½�һ��Ա��������(Y/N)?");
    scanf(" %c",&c);
    while(c == 'Y' || c == 'y'){
        head = AppendNode(head);
        printf("����Ҫ���½�һ��Ա��������(Y/N)?");
            scanf(" %c",&c);
            i++;
            *padd = *padd + 1;
    }
    printf("���ɹ��½��� %d ��Ա������,��׼����Ա������д�����µ����ļ�...\n",i);
    printf("�Ƿ���Ҫ��ʾԱ�����ݵ���ϸ��Ϣ(Y/N)?\n");
    scanf(" %c",&c);
    while(c == 'y' || c == 'Y'){
    DisplyNode(head);
    c = 'n';
    }
    WritetoFile(head,i);
    printf("�ѳɹ���Ա������д���ļ���\n");
    return head;
}

struct link *AppendNode(struct link *head){
    struct link *p = NULL, *pr = head;
    PAInfo data;
    p = (struct link *)malloc(sizeof(struct link));
    if(p == NULL){
        printf("�ڴ治�㣡");
        exit(0);
    }
    if(head ==NULL){
        head = p;
    }
    else{
        while(pr->next!=NULL){
            pr = pr ->next;
        }
        pr->next = p;
    }
    printf("������Ա������ϸ��Ϣ\n");
    printf("�����ţ�");
    scanf("%s",data.num);
    printf("����������");
    scanf("%s",data.name);
    printf("�����Ա�");
    scanf("%s",data.sex);
    printf("�������䣺");
    scanf("%d",&data.age);
    printf("����ְ��");
    scanf("%s",data.job);
    printf("����ְ�ƣ�");
    scanf("%s",data.post);
    printf("����������ò��");
    scanf("%s",data.politic);
    printf("�������ѧ����");
    scanf("%s",data.edu_level);
    printf("������ְʱ�䣺");
    scanf("%s",data.period);
    printf("������Ժʱ�䣺");
    scanf("%s",data.start_time);
    p->data = data;
    p->next = NULL;
    return head;
}

void DisplyNode(struct link *head){
    struct link *p = head;
    int j = 1;
    while(p != NULL){
        printf("--------�� %d ��Ա����Ϣ--------\n",j);
        printf("\t������%s            \n",p->data.name);
        printf("\t��ţ�%s            \n",p->data.num);
        printf("\t�Ա�%s            \n",p->data.sex);
        printf("\t���䣺%d            \n",p->data.age);
        printf("\tְ��%s            \n",p->data.job);
        printf("\tְ�ƣ�%s            \n",p->data.post);
        printf("\t������ò��%s\n",p->data.politic);
        printf("\t���ѧ����%s\n",p->data.edu_level);
        printf("\t��ְʱ�䣺%s\n",p->data.period);
        printf("\t��Ժʱ�䣺%s\n",p->data.start_time);
        printf("--------------------------------\n");
        p = p->next;
        j++;
    }
}

void WritetoFile(struct link *head,int n){
    struct link *p = head;
    FILE *fp;
    if((fp = fopen("student.txt","w")) == NULL){
        printf("�ĵ��޷�������");
        exit(0);
    }
    while(p != NULL){
        fwrite(p,sizeof(PAInfo),n,fp);
        p = p->next;
    }
    fclose(fp);
}

struct link *ReadandInput(struct link *head,int *padd){//�������ģ��
    char c;
    int nexti = 0;
    printf("����Ҫ�򵵰��ļ���׷��һ��Ա����Ϣ��(Y/N)?");
    scanf(" %c",&c);
    while(c == 'Y' || c == 'y'){
        head = AppendNode(head);
        printf("����Ҫ�򵵰��ļ�����׷��һ��Ա����Ϣ��(Y/N)?");
            scanf(" %c",&c);
            nexti++;
    }
    printf("���ɹ�׷���� %d ��Ա������,��׼����Ա������д�����µ����ļ�...\n",nexti);
    printf("�Ƿ���Ҫ��ʾ׷�Ӻ��Ա�����ݵ���ϸ��Ϣ(Y/N)?\n");
    scanf(" %c",&c);
    while(c == 'y' || c == 'Y'){
    DisplyNode(head);
    c = 'n';
    }
    *padd = *padd + nexti;
    WritetoFile(head,*padd);
    printf("�ѳɹ���Ա������д���ļ���\n");
    return head;
}

struct link *DeleteData(struct link *head,int *padd){
    char node[15];
    char c;
    struct link *p =head,*pr = head;
    printf("������Ҫɾ����Ա�ı�ţ�\n");
    scanf("%s",node);
    if(head == NULL){
        printf("û��Ա�����ݣ�\n");
        return(head);
    }
    while (strcmp(node,p->data.num)!=0 && p->next != NULL){
        pr = p;
        p = p->next;
    }
    if(strcmp(node,p->data.num) == 0){
        if(p == head){
            head = p->next;
        }
        else{
            pr->next = p->next;
        }
        free(p);
        *padd = *padd-1;
    }
    else{
        printf("�õ����ļ���û�д˱�ţ�\n");
    }
    printf("�Ƿ���Ҫ��ʾɾ�����Ա�����ݵ���ϸ��Ϣ(Y/N)?\n");
    scanf(" %c",&c);
    while(c == 'y' || c == 'Y'){
    DisplyNode(head);
    c = 'n';
    }
    return head;
}

void InquiryData(struct link *head){
    char node[15];
    char name[15];
    struct link *p =head,*pr = head;
    printf("������Ҫ��ѯ����Ա��ţ�\n");
    scanf("%s",node);
    printf("������Ҫ��ѯ����Ա������\n");
    scanf("%s",name);
    if(head == NULL){
        printf("δ��ѯ��Ա��������\n");
        return(head);
    }
    while (strcmp(node,p->data.num)!=0 && strcmp(name,p->data.name)!=0 && p->next != NULL){
        pr = p;
        p = p->next;
    }
    if(strcmp(node,p->data.num) == 0 && strcmp(name,p->data.name) == 0){
        printf("--------��Ա������ϸ��Ϣ��--------\n");
        printf("\t������%s            \n",p->data.name);
        printf("\t��ţ�%s            \n",p->data.num);
        printf("\t�Ա�%s            \n",p->data.sex);
        printf("\t���䣺%d            \n",p->data.age);
        printf("\tְ��%s            \n",p->data.job);
        printf("\tְ�ƣ�%s            \n",p->data.post);
        printf("\t������ò��%s\n",p->data.politic);
        printf("\t���ѧ����%s\n",p->data.edu_level);
        printf("\t��ְʱ�䣺%s\n",p->data.period);
        printf("\t��Ժʱ�䣺%s\n",p->data.start_time);
        printf("---------------------------------\n");
    }
    else{
        printf("�õ����ļ���û�ж�Ӧ����Ա��\n");
    }
}

struct link *ReviseData(struct link *head){
    char node[15];
    char temp[15];
    char c;
    int j ;
    struct link *p =head,*pr = head;
    printf("�����뱻�޸�Ա���ı�ţ�\n");
    scanf("%s",node);
    printf("����������Ҫ�޸ĵ��������ǰ�����֣�\n");
    printf("1:���   2:����   3:�Ա�   4:����\n");
    printf("5:ְ��   6:ְ��   7:������ò \n");
    printf("8:���ѧ��    9:��ְʱ��    10: ��Ժʱ��\n");
    scanf("%d",&j);
    if(j>10||j<0){
        for(;;){
        printf("��������1~10֮������֣�\n");
        scanf("%d",&j);
            if(j>=1&&j<=10){
                break;
            }
        }
    }
    printf("���������޸ĺ�����ݣ�\n");
    scanf("%s",temp);
    if(head == NULL){
        printf("û��Ա�����ݣ�\n");
        return(head);
    }
    while (strcmp(node,p->data.num)!=0 && p->next != NULL){
        pr = p;
        p = p->next;
    }
    if(strcmp(node,p->data.num) == 0){
        if(j == 1 ){
            strcpy(p->data.num,temp);
        }
        else if(j == 2 ){
            strcpy(p->data.name,temp);
        }
        else if(j == 3 ){
            strcpy(p->data.sex,temp);
        }
        else if(j == 4 ){
            strcpy(p->data.age,temp);
        }
        else if(j == 5 ){
            strcpy(p->data.job,temp);
        }
        else if(j == 6 ){
            strcpy(p->data.post,temp);
        }
        else if(j == 7 ){
            strcpy(p->data.politic,temp);
        }
        else if(j == 8 ){
            strcpy(p->data.edu_level,temp);
        }
        else if(j == 9 ){
            strcpy(p->data.period,temp);
        }
        else if(j == 10 ){
            strcpy(p->data.start_time,temp);
        }
        else{
            printf("��������ȷ�����֣�");
        }

    }
    else{
        printf("�õ����ļ���û�д˱�ţ�\n");
    }
    printf("���ɹ��޸���Ա������,��׼����Ա������д�����µ����ļ�...\n");
    printf("�Ƿ���Ҫ��ʾ�޸ĺ��Ա�����ݵ���ϸ��Ϣ(Y/N)?\n");
    scanf(" %c",&c);
    while(c == 'y' || c == 'Y'){
    DisplyNode(head);
    c = 'n';
    }

    printf("�ѳɹ���Ա������д���ļ���\n");
    return head;
}

void PrintScore(struct link *head){
    struct link *p = head;
    int j = 1;
    while(p != NULL){
        printf("--------��%d��Ա����Ϣ--------\n",j);
        printf("\t������%s            \n",p->data.name);
        printf("\t��ţ�%s            \n",p->data.num);
        printf("\t�Ա�%s            \n",p->data.sex);
        printf("\t���䣺%d            \n",p->data.age);
        printf("\tְ��%s            \n",p->data.job);
        printf("\tְ�ƣ�%s            \n",p->data.post);
        printf("\t������ò��%s\n",p->data.politic);
        printf("\t���ѧ����%s\n",p->data.edu_level);
        printf("\t��ְʱ�䣺%s\n",p->data.period);
        printf("\t��Ժʱ�䣺%s\n",p->data.start_time);
        printf("--------------------------------\n");
        p = p->next;
        j++;
    }

}

void DisplayNode(struct link *head,int *padd){
    char c;
    printf("���Ƿ���Ҫ��ȡ����ʾ�õ����ļ�����Ա��Ϣ��Y/N����\n");
    scanf(" %c",&c);
    while(c == 'y' || c == 'Y'){
    PrintScore(head);
    c = 'n';
    }
}

struct link *SelectSort(struct link *head){
    struct link *endpt;
    struct link *u;
    struct link *v;
    struct link *p;
    int j;
    u = (struct link *)malloc(sizeof(struct link));
    u->next = head;
    head = u;
    printf("��ѡ������ʽ��\n");
    printf("1:�����併��\n");
    printf("2:����Ժʱ�併��\n");
    scanf("%d",&j);
    if(j == 1){
        for(endpt = NULL;endpt!=head;endpt = p){
            for(p = u = head;u->next->next!=endpt;u = u->next){
                if(u->next->data.age < u->next->next->data.age){
                    v=u->next->next;
                    u->next->next=v->next;
                    v->next=u->next;
                    u->next=v;
                    p=u->next->next;
                }
            }
        }
        u = head;
        head = head->next;
        printf("���������\n");
        return head;
    }
    else if(j == 2){
        for(endpt = NULL;endpt!=head;endpt = p){
            for(p = u = head;u->next->next!=endpt;u = u->next){
                if(strcmp(u->next->data.start_time,u->next->next->data.start_time)<0){
                    v=u->next->next;
                    u->next->next=v->next;
                    v->next=u->next;
                    u->next=v;
                    p=u->next->next;
                }
            }
        }
        u = head;
        head = head->next;
        printf("���������\n");
        return head;
    }
}

void CountData(struct link *head){
    int j = 0;
    int a;
    struct link *p =head,*pr = head;
    printf("��������Ҫͳ�Ƶ���������֣�\n");
    printf("1:��Ա����    2:Ů������  \n");
    printf("3:��ѧ������  4:��ְ������ \n");
    scanf("%d",&a);
    if(j>4||j<0){
        for(;;){
        printf("��������1~4֮������֣�\n");
        scanf("%d",&j);
            if(j>=1&&j<=4){
                break;
            }
        }
    }
    if(a == 1){
        while(p!=NULL){
            if(strcmp("��Ա",p->data.politic) == 0){
                j = j + 1;
            }
            p = p->next;
        }
        printf("�õ����ļ��й���%d����Ա��\n",j);
    }
    else if(a == 2){
        while(p!=NULL){
            if(strcmp("Ů",p->data.sex) == 0){
                j = j + 1;
            }
            p = p->next;
        }
        printf("�õ����ļ��й���%d��Ů����\n",j);
    }
    else if(a == 3){
        while(p!=NULL){
            if(strcmp("����",p->data.edu_level) == 0){
                j = j + 1;
            }
            p = p->next;
        }
        printf("�õ����ļ��й���%d������Ա����\n",j);
    }
    else if(a == 4){
        while(p!=NULL){
            if(strcmp("����",p->data.post) == 0){
                j = j + 1;
            }
            p = p->next;
        }
        printf("�õ����ļ��й���%d�����ڡ�\n",j);
    }
}

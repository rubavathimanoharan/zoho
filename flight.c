#include<stdio.h>
#include<stdlib.h>

int first=3, second=2, third=3;

double cost(int row,int seat);
typedef struct node
{
char row_no;
int seat_no,pin;
char book;
struct node *next,*prev;
}node;



node *hn=NULL;


void create()
{
node *nn,*cn;
int j=1;
int k=2;
char c ='A';

do
{
int i=1;
do
{
k=(k*k)/10+100-k/2;
nn=(struct node*)malloc(sizeof(struct node));
nn->next=nn->prev=NULL;
nn->row_no=c;
nn->seat_no=i;
nn->pin=k;
nn->book='a';
if(hn==NULL)
{
hn=nn;
nn->next=nn->prev=hn;
}
else
{
cn=hn;

while(cn->next!=hn)
	cn=cn->next;

cn->next=nn;
nn->prev=cn;
nn->next=hn;
hn->prev=nn;
}
i++;
}while(i<=first+second+third);
j++;
c++;
}while(j<=10);
}


void display()
{
node *cn;
printf("SSS: %d", second);
second = second + first;
third = second + third;
cn=hn;
printf("%d**%d",first,second);
//printf("------------------------------------------------------------------\n");
printf("|                            BUISNESS                            |\n");
while(cn->next!=hn)
{
if((cn->prev)->row_no!=cn->row_no)
printf("| ");
//window alisa and middle

if(cn->seat_no==1 || cn->seat_no==third){
    printf("W");
}else if(cn->seat_no==first || cn->seat_no-1==second || cn->seat_no==second ||cn->seat_no-1==first ){
    printf("A");
}else{
    printf("M");
}
printf("%c",cn->row_no);
printf("%d", cn->seat_no);
if(cn->book=='a')
printf(" -> a  ");  //green text with black background
else
printf(" -> b  ");  //red text
if(cn->seat_no==first || cn->seat_no==second)
printf("    ");
if((cn->next)->row_no!=cn->row_no)
printf("|\n");
if(cn->row_no=='D'&&cn->seat_no==third)
{
//printf("------------------------------------------------------------------\n");
printf("|                             ECONOMY                               |\n");
}
//if(cn->row_no=='H'&&cn->seat_no==7)
//{
//printf("------------------------------------------------------------------\n");
//printf("|                            Silver                              |\n");
//}
cn=cn->next;
}

printf("%d        ",cn->seat_no);
printf("%c",cn->row_no);

if(cn->book=='a')
printf(" -> a  ");  //green text with black background

else
printf(" -> b  ");  //red text
printf("|\n");

printf("------------------------------------------------------------------\n\n");
printf("BUISNESS-> 150                                        ECONOMY-> 100\n");
}

void display1(node *tmp[20],int n)
{
if(n!=1)
{
printf("------------------------------------------------------------------\n");
printf("THANK YOU!YOU HAVE SUCCESFULLY BOOKED THE SEATS\n");
for(int i=1;i<n;i++)
printf("%d %d \nPIN:%d \n",tmp[i]->row_no,tmp[i]->seat_no,tmp[i]->pin);

printf("!!!!!!!!!!!!!!!!!!KEEP PIN SAFELY!!!!!!!!!!!!!!!!!!!\n");
printf("PINS ARE REQUIRED AT THE TIME OF CANCELATION OF SEATS\n");
printf("------------------------------------------------------------------\n");
}
}
void cancle()
{
char row,ch;
int seat,pin;
node *cn;
printf("SEAT CANCELATION\n");
do
{
ch='a';
cn=hn;
printf("SEAT NUMBRE :");
scanf("%c %d",&row,&seat);
printf("PIN :");
scanf("%d",&pin);
if(row>='A'&&row<='M')
{
while(cn->next!=hn)
{
if(cn->row_no==row && cn->seat_no==seat && cn->pin==pin)
{
printf("Are you sure u want to cancle the Seat (y/n) ");
char c;
scanf("%c",&c);
if(c=='y'||c=='Y')
{
printf("SEAT CANCELED SUCCESFULLY!\n");
cn->book='a';
}
}
else if(cn->row_no==row && cn->seat_no==seat && cn->pin!=pin)
{
printf("invalid SEAT NUMBER && PIN combination!!!!\n");
}
cn=cn->next;
}
if(cn->row_no==row && cn->seat_no==seat && cn->pin==pin)
{
printf("Are you sure u want to cancle (y/n) ");
char c;
scanf("%c",&c);
if(c=='y'||c=='Y')
{
printf("SEAT CANCELED SUCCESFULLY!\n");
cn->book='a';
}
}
else if(cn->row_no==row && cn->seat_no==seat && cn->pin!=pin)
{
printf("invalid SEAT NUMBER && PIN combination!!!!\n");
}
}
else
{
while(cn->next!=hn)
{
if(cn->row_no==row && cn->seat_no==seat && cn->pin==pin)
{
printf("Are you sure u want to cancle the Seat (y/n) ");
char c;
scanf("%c",&c);
if(c=='y'||c=='Y')
{
printf("SEAT CANCELED SUCCESFULLY!\n");
cn->book='a';
}
}
else if(cn->row_no==row && cn->seat_no==seat && cn->pin!=pin)
{
printf("invalid SEAT NUMBER && PIN combination!!!!\n");
}
cn=cn->next;
}
if(cn->row_no==row && cn->seat_no==seat && cn->pin==pin)
{
printf("Are you sure u want to cancle (y/n) ");
char c;
scanf("%c",&c);
if(c=='y'||c=='Y')
{
printf("SEAT CANCELED SUCCESFULLY!\n");
cn->book='a';
}
}
else if(cn->row_no==row && cn->seat_no==seat && cn->pin!=pin)
{
printf("invalid SEAT NUMBER && PIN combination!!!!\n");
}
}
printf("\n\nPRESS 1 To Check Seat Status\n"); 
printf("PRESS 2 To Cancle More Tickets\n");
printf("PRESS 3 To Exit CANCELATION PORTAL\n");
printf("\ninput: ");
scanf("%c",&ch);
if(ch==1)
display();
}while(ch=='2');
}
void book_seat()
{
node *cn,*temp[20];
int n,z,flag;
char roww;
int seat;
char ch;
do
{
z=1;
printf("\nEnter No Of Tickets u Want To Buy: ");
scanf("%d",&n);

printf("\nEnter Seat Number(s) in the format of Row name followed by seat number (eg.A1): \n");
double price=0;
for(int i=1;i<=n;i++)
{
printf("NO=%d ",i); 
scanf("%d",&seat);
scanf("%c", &roww);
printf("row: %c, seat: %d\n", roww, seat);
//2printf("fn call %d",cost(roww,seat));
price=price+cost(roww,seat);
cn=hn;
if(roww>='A'&&roww<='E')
{
//printf("Entering\n");
while(cn->next!=hn)
{
if(cn->row_no==roww && cn->seat_no==seat)
{
if(cn->book=='a')
{
cn->book='b';
temp[z]=cn;
z++;
}
else
{
printf("INVALID CHOISE!\n");
printf("%c %d  Seat is alredy reserved \n",cn->row_no,cn->seat_no);

}
}
cn=cn->next;
}
if(cn->row_no==roww && cn->seat_no==seat)
{
if(cn->book=='a')
{
cn->book='b';
temp[z]=cn;
z++;
}
else
{
printf("INVALID CHOISE!\n");
printf("%c %d Seat is alredy reserved\n",cn->row_no,cn->seat_no);
}
}
}
else //
{
while(cn->prev!=hn)
{
if(cn->row_no==roww && cn->seat_no==seat)
{
if(cn->book=='a')
{
cn->book='b';
temp[z]=cn;
z++;
}
else
{
printf("INVALID CHOISE!\n");
printf("%c %d Seat is alredy reserved\n",cn->row_no,cn->seat_no);
}
}
cn=cn->prev;
}
if(cn->row_no==roww && cn->seat_no==seat)
{
if(cn->book=='a')
{
cn->book='b';
temp[z]=cn;
z++;
}
else
{
printf("INVALID CHOISE!\n");
printf("%c %d Seat is alredy reserved\n",cn->row_no,cn->seat_no);
}
}
}

}

printf("\nprice of the seat is %lf\n",price);
display1(temp,z);
printf("\n\nPRESS 1 To check Seat Status\n");
printf("PRESS 2 To book other seat\n");
printf("PRESS 3 To Exit BOOKING PORTAL\n");
printf("\ninput: ");
scanf("%c",&ch);
if(ch==1)
display();
}while(ch=='2');
}



double cost(int row,int seat)
{
    int food;
    printf("For food press 1 else press 0");
    scanf("%d",&food);
    double price=0,final=0;
    
      printf("%d %c\n",seat,row);
      if((seat%7!=4) && (row>='A' && row<='C'))
      {
          printf("1");
          price=price+((1500)+100);
      }
     else if((seat%7==4) && (row>='A' && row<='C'))
      {
          printf("2");
          price=(price+(1500));
      }
      else if(seat%7!=4 && (row>='D' && row<='J'))
      {
          printf("3");
          price=price+((1000)+100);
      }
      else if(seat%7==4 && (row>='D' && row<='J'))
      {
          printf("4");
          price=price+(1000);
      }
      if(food==1)
      final=final+price+200;
      else
      {
          final=price+final;
      }
      printf("%d",price);
      
      return final;
      
}

int main()
{

FILE *fptr;

   if ((fptr = fopen("C:/data/dataf.txt","r")) == NULL){
       printf("Error! opening file");

       // Program exits if the file pointer returns NULL.
       exit(1);
   }

    fscanf(fptr,"Business { %d ,", &first);
    fscanf(fptr,"%d ,", &second);
    fscanf(fptr,"%d ", &third);
   printf("Value of n=%d %d %d ", first,second,third);
   fclose(fptr);

int ch;
char c;
printf("\n\n\n");
printf("***************FLIGHT TICKET BOOKING SYSTEM*********************");

create();
display();

do
{
printf("\n\n\n");
printf("PRESS 1-> BOOK TICKETS\n");
printf("PRESS 2-> CANCLE TICKETS\n");
printf("PRESS 3-> EXIT\n");
printf("\ninput: ");
scanf("%d",&ch);
switch(ch)
{
case 1:
book_seat();
display();
break;
case 2:
cancle();
display();
break;
}
if(ch!=3)
{
printf("\n\nPRESS 1 To Main Menu\n");
printf("PRESS 2 To Exit CINEMAX PORTAL\n");
printf("\ninput: ");
scanf("%d",&ch);
}
}while(c=='1');
printf("\n\n\n");
return 0;

}
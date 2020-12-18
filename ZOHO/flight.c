#include <stdio.h>
#include <stdlib.h>

int first, second, third, ro;
static int pinn=1;
double cost(int row, int seat);
typedef struct node
{
    char row_no;
    int seat_no, pin;
    char book;
    struct node *next;
} node;

node *hn = NULL;

void create()
{
    node *nn, *cn;
    int j = 1;
    int k = 2;
    char c = 'A';
    do
    {
        int i = 1;
        do
        {
          // k = (k * k) / 10 + 100 - k / 2;
            nn = (struct node *)malloc(sizeof(struct node));
            nn->next  = NULL;
            nn->row_no = c;
            nn->seat_no = i;
           //nn->pin = k;
            nn->book = 'a';
            if (hn == NULL)
            {
                hn = nn;
                nn->next = hn;
            }
            else
            {
                cn = hn;

                while (cn->next != hn)
                    cn = cn->next;

                cn->next = nn;
                nn->next = hn;
            }
            i++;
        } while (i <= first + second + third);
        j++;
        c++;
    } while (j <= ro);

}

void display()
{
    node *cn;
   
    second = second + first;
    third = second + third;
    cn = hn;
    printf("\na  =>  ticket AVAILABLE \nb  =>  ticket BOOKED\n");
    printf("\n W-WINDOW                          A-AISLE                              M-MIDDLE\n\n");
    printf("|                            BUISNESS                            |\n");
    while (cn->next != hn)
    {
        //window asile and middle

        if (cn->seat_no == 1 || cn->seat_no == third)
        {
            printf("W ");
        }
        else if (cn->seat_no == first || cn->seat_no - 1 == second || cn->seat_no == second || cn->seat_no - 1 == first)
        {
            printf("A ");
        }
        else
        {
            printf("M ");
        }
        printf("%c", cn->row_no);
        printf("%d", cn->seat_no);
        if (cn->book == 'a')
            printf(" -> a  "); 
        else
            printf(" -> b  "); 
        if (cn->seat_no == first || cn->seat_no == second)
            printf("    ");
        if ((cn->next)->row_no != cn->row_no)
            printf("\n");
        if (cn->row_no == 'D' && cn->seat_no == third)
        {
            printf("|                             ECONOMY                                                  |\n");
        }

        cn = cn->next;
    }

    printf("%d", cn->seat_no);
    printf("%c", cn->row_no);

    if (cn->book == 'a')
        printf(" -> a  ");

    else
        printf(" -> b  ");
    printf("|\n");
   printf("----------------------------------------------------------------------------------------\n\n");
    printf("BUISNESS-> 1500                                        ECONOMY-> 1000\n");
}

void display1(node *tmp[20], int n)
{
    int j=0;
    if (n != 1)
    {
        printf("------------------------------------------------------------------\n");
        printf("THANK YOU!YOU HAVE SUCCESFULLY BOOKED THE SEATS\n");
        for (int i = 1; i < n; i++)
            printf("%c %d \n", tmp[i]->row_no, tmp[i]->seat_no);
         printf("%d\n",pinn);
        printf("!!!!!!!!!!!!!!!!!!KEEP PIN SAFELY!!!!!!!!!!!!!!!!!!!\n");
        printf("PINS ARE REQUIRED AT THE TIME OF CANCELATION OF SEATS\n");
        printf("------------------------------------------------------------------\n");
    }
}
void cancle()
{
    char cancel_row = '\0';
    int yn, ch;
    int seat, p;
    node *cn;
    printf("SEAT CANCELATION\n");
    do
    {
        ch = 'a';
        cn = hn;
    
        printf("SEAT NUMBER : ");
        scanf("%d", &seat);
        scanf("%c\n", &cancel_row);
       // printf("PIN : ");
        scanf("%d", &p);
        printf("%d",cn->pin);
        if (cancel_row >= 'A' && cancel_row <= 'J')
        {

            while (cn->next != hn)
            {
                if (cn->row_no == cancel_row && cn->seat_no == seat && cn->pin == p)
                {
                    printf("Are you sure u want to cancle the Seat (y=1/n=0) ");
                    scanf("%d", &yn);
                    if (yn == 1 && cn->book=='b')
                    {
                        printf("\n\n!!!!!!!!!!!!!!!!!!!!!!!SEAT CANCELED SUCCESFULLY!!!!!!!!!!!!!!!!!!!!!!!\n");
                        printf("Cost of the cancelled tickets will be refunded soon\n\n THANK YOU!!");
                        cn->book = 'a';
                    }
                    else 
                    {
                        break;
                    }
                }
            
                cn = cn->next;
            }
             if (cn->row_no == cancel_row && cn->seat_no == seat && cn->pin == pinn)
                {
                    printf("Are you sure u want to cancle the Seat (y=1/n=0) ");
                    scanf("%d", &yn);
                    if (yn == 1 && cn->book=='b')
                    {
                        printf("\n\n!!!!!!!!!!!!!!!!!!!!!!!SEAT CANCELED SUCCESFULLY!!!!!!!!!!!!!!!!!!!!!!!\n");
                        printf("Cost of the cancelled tickets will be refunded soon\n\n THANK YOU!!");
                        cn->book = 'a';
                    }
    
                    else 
                    {
                        break;
                    }
                }
        }
        else
        {
            printf("invalid SEAT NUMBER!!!!\n");
        }
        printf("\n\nPRESS 1 To Check Seat Status\n");
        printf("PRESS 2 To Cancle More Tickets\n");
        printf("PRESS 3 To Exit CANCELATION PORTAL\n");
        printf("\ninput: ");
        scanf("%d", &ch);
        if (ch == 1)
            display();
    } while (ch == 2);
}
//BOOK SEAT
void book_seat()
{
    char end_row = ro + 64;
    node *cn, *temp[20];
    int n, z, flag,k=2;
    char roww;
    int seat, opt,food;
    //cn->pin=pin++; 
    do
    {
        z = 1;
        printf("\nEnter No Of Tickets u Want To Buy: ");
        scanf("%d", &n);
        printf("\nEnter Seat Number(s) in the format of seat number followed by Row name (eg.1A): \n");
        double price = 0;
        for (int i = 1; i <= n; i++)
        {
            printf("NO = %d ", i);
            scanf("%d", &seat);
            scanf("%c", &roww);
            printf("row: %c\nseat: %d\n", roww, seat);

            price = price + cost(roww, seat);
            cn = hn;
    
            if (roww >= 'A' && roww <= end_row)
            {
                while (cn->next != hn)
                {
                    if (cn->row_no == roww && cn->seat_no == seat)
                    {
                        if (cn->book == 'a')
                        {
                            cn->book = 'b';
                            cn->pin=pinn;
                            temp[z] = cn;
                            z++;
                        }
                        else
                        {
                            printf("INVALID CHOISE!\n");
                            printf("%c %d  Seat is alredy reserved \n", cn->row_no, cn->seat_no);
                        }
                    }
                    cn = cn->next;
                }
                if (cn->row_no == roww && cn->seat_no == seat)
                {
                    if (cn->book == 'a')
                    {
                        cn->book = 'b';
                        cn->pin=pinn;
                        temp[z] = cn;
                        z++;
                    }
                    else
                    {
                        printf("INVALID CHOISE!\n");
                        printf("%c %d Seat is alredy reserved\n", cn->row_no, cn->seat_no);
                    }
                }
            }
        else
            {
                printf("INVALID ROW NAME AND SEAT NUMBER");
            }
        }
         printf("\n\nPRESS 1 To check Seat Status\n");
            printf("PRESS 2 To book other seat\n");
            printf("PRESS 3 To Exit BOOKING PORTAL\n");
            printf("\ninput: ");
            scanf("%d", &opt);
            if(opt==3)
            {
                
            // printf("\nprice of the seat is %lf\n", price);
             printf("For food press 1 else press 0  :  ");
    scanf("%d", &food);
    if(food==1)
     {
         printf("\nprice of the seat is %lf\n", price+(200*n));
     }
     else
     {
         printf("\nprice of the seat is %lf\n", price);
     }    
            display1(temp, z);
            }
            if (opt == 1)
                display();
                pinn++; 
    } while (opt == 2);
}
double cost(int row, int seat)
{
    double price = 0, final = 0;
   // printf("%d \n%c\n", seat, row);
    if ((seat % 7 != 4) && (row >= 'A' && row <= 'C'))
    {
        price = price + ((1500) + 100);
    }
    else if ((seat % 7 == 4) && (row >= 'A' && row <= 'C'))
    {
        price = (price + (1500));
    }
    else if (seat % 7 != 4 && (row >= 'D' && row <= 'J'))
    {
        price = price + ((1000) + 100);
    }
    else if (seat % 7 == 4 && (row >= 'D' && row <= 'J'))
    {
        price = price + (1000);
    }
   // if (food == 1)
        //final = final + price + 200;
   // else
   // {
       // final = price + final;
    //}
   //return final;
    return price;
}
int main()
{
    FILE *fptr;
    if ((fptr = fopen("C:/data/dataf.txt", "r")) == NULL)
    {
        printf("Error! opening file");
        exit(1);
    }
    int bfirst, bsecond, bthird, bro;
    fscanf(fptr, "Total: { %d ,", &first);
    fscanf(fptr, "%d , ", &second);
    fscanf(fptr, "%d }", &third);
    fscanf(fptr, " => %d", &ro);
    fclose(fptr);
    int ch, c;
    printf("\n\n\n");
    printf("                                  FLIGHT TICKET BOOKING SYSTEM                               ");
    create();
    display();
    do
    {
        printf("\n\n\n");
        printf("PRESS 1-> BOOK TICKETS\n");
        printf("PRESS 2-> CANCLE TICKETS\n");
        printf("PRESS 3-> EXIT\n");
        printf("\ninput: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            book_seat();
            display();
            break;
        case 2:
            cancle();
           // display();
            break;
        }
        if (ch != 3)
        {
            printf("\n\nPRESS 1 To Main Menu\n");
            printf("PRESS 2 To Exit \n");
            printf("\ninput: ");
            scanf("%d", &ch);
        }
    } while (ch == 1);
    printf("\n\n\n");
    return 0;
}

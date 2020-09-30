#include<stdio.h>
#include<stdlib.h>

struct node
{
	int state;
	struct node *link;
};

static int no_symb, no_trans, no_state, state[5], buffer[20], e_closure[20][20]={0}, cur, next;
char symb[10], inp;
struct node *transition[20][20]={NULL};


int findinput(char inp)
{
	int i;
	for(i=0;i<no_symb;i++)
	{
		if(symb[i] == inp)
			return i;
	}
	return 999;
}

void insert_transtable(int cur, char inp, int next)
{
	int j;
	struct node *temp;
	j = findinput(inp);
	if(j==999)
	{
		printf("\nError !! Invalid Input Symbol !!\n");
		exit(0);
	}
	temp = (struct node *)malloc(sizeof(struct node));
	temp->state = next;
	temp->link = transition[cur][j];
	transition[cur][j] = temp;
}

void findclosure(int x,int sta)
{
        struct node *temp;
        int i;
        if(buffer[x])
                return;
	e_closure[sta][inp++]=x;
        buffer[x]=1;
        if(symb[no_symb-1]=='e' && transition[x][no_symb-1]!=NULL)
        {
                temp=transition[x][no_symb-1];
                while(temp!=NULL)
                {
                        findclosure(temp->state,sta);
                        temp=temp->link;
                }
        }
}

void print_e_closure(int i)
{
        int j;
        printf("{");
        for(j=0;e_closure[i][j]!=0;j++)
        printf("q%d,",e_closure[i][j]);
        printf("}");
}

int main()
{
	int i, j;
	char ch;
	printf("\nThe Number Of Input Symbols : ");
	scanf("%d", &no_symb);
	printf("\nEnter Input Symbols : ");
	for(i=0;i<no_symb;i++)
	{
		scanf(" %c", &symb[i]);
	}
	
	printf("\nEnter Number Of States : ");
	scanf("%d", &no_state);
	printf("\nEnter Number Of Transitions : ");
	scanf("%d", &no_trans);
	printf("\nEnter The Transitions : \n");
	for(i=0; i<no_trans; i++)
	{
		scanf("%d %c %d", &cur, &inp, &next);
		insert_transtable(cur, inp, next);
	}

	printf("\n");
        printf("e-closure of states : \n");
        for(i=1;i<=no_state;i++)
        {
                inp=0;
                for(j=0;j<20;j++)
                {
                        buffer[j]=0;
                        e_closure[i][j]=0;
                }
                findclosure(i,i);
                printf("\ne-closure(q%d): ",i);
                print_e_closure(i);
        }
	printf("\n\n");
	return 0;
}


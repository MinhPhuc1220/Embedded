#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    //mot con tro kieu node: luu dia chi node tiep theo
    struct node* next;
} node;

//moi node deu la mot con tro kieu node: dung de quan ly cac node khac
node* makeNode(int x){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

//head la dia chi node dau tien trong dslk (con tro quan ly node dau tien trong dslk)
int size(node *head){
    int cnt = 0;
    while(head != NULL){
        ++cnt;
        //head->next: dia chi cua node ke tiep
        //lay dia chi node ke tiep gan lai cho head
        head = head->next; //giong i++ trong duyet mang
    }
    return cnt;
}
 
void duyet(node *head){
    while(head != NULL){
        printf("%d ",head->data);
        head = head->next;
    }
}

void pushFront(node **head, int x){
   node* newNode = makeNode(x);
   //B1: phan next cua newNode => head (lay next cua node moi luu dia chi cua node dau tien)
   newNode->next = (*head); //*head => dia chi cua node head trong dslk
   //B2: Cap nhap node head => newNode (cap nhap node head la node moi)
   (*head) = newNode; 
}
 
void pushBack(node **head, int x){
   node* newNode = makeNode(x);
   //Ham tranh cho con tro head bang NULL => khi gan tmp cho con tro head se lam loi bo nho
   if(*head == NULL){
      *head = newNode; return;
   }
   node* tmp = *head;
   //duyet den node cuoi cung trong dslk
   while(tmp->next != NULL){
       tmp = tmp->next;
   }
   tmp->next = newNode;
}
 
void insert(node **head, int k, int x){
	int n = size(*head);
	if(k < 1 || k > n + 1) return;
	if(k == 1){
		pushFront(head, x); return;
	}
	node *temp = *head;
	for(int i = 1; i <= k - 2; i++){
		temp = temp->next;
	}
	//temp : k - 1
	node *newNode = makeNode(x);
	newNode->next = temp->next;
	temp->next = newNode;
}

int main(int argc, char const *argv[])
{
    node *head = NULL;
	while(1){
		printf("------------------------------------\n");
		printf("1. Them vao dau\n");
		printf("2. Them vao cuoi\n");
		printf("3. Them vao giua\n");
		printf("4. Duyet\n");
		printf("0. Thoat !\n");
		printf("------------------------------------\n");
		printf("Nhap lua chon :");
		int lc; 
        scanf("%d",&lc);
		if(lc == 1){
			int x; 
            printf("Nhap x :"); 
            scanf("%d",&x);
			pushFront(&head, x);
		}
		else if(lc == 2){
			int x; 
            printf("Nhap x :"); 
            scanf("%d",&x);
			pushBack(&head, x);
		}
		else if(lc == 3){
			int x; 
            printf("Nhap x :"); 
            scanf("%d",&x);
			int k; 
            printf("Nhap k :"); 
            scanf("%d",&k);
			insert(&head, k, x);
		}
		else if(lc == 4){
			duyet(head);
			printf("\n");
		}
		else{
			break;
		}
	}
    return 0;
}

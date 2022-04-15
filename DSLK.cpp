#include<iostream>
using namespace std;
struct Node{
	int Data;
	Node *pNext;
};
struct List{
	Node *pHead;
	Node *pTail;
};
void InitList(List &l){
	l.pHead = l.pTail = NULL;
}
Node *Create (int d){
	Node *pNode = new Node;
	pNode->Data = d;
	pNode->pNext = NULL;
	return pNode;
}
void InsertTail(List &l, Node *p){
	if(l.pHead==NULL){
		l.pHead = l.pTail = p;
	}
	else
	{
	l.pTail->pNext=p;
	l.pTail=p;
	}
}
void Xuat(List l){
	for(Node *p= l.pHead; p!=NULL; p=p->pNext){
		cout<< p->Data<<" ";
	}
}
void Nhap(List A, List B, List &C){
	for(Node *p= A.pHead; p!=NULL; p= p->pNext){
		InsertTail(C, p);
	}
	for(Node *p= B.pHead; p!=NULL; p=p->pNext){
		InsertTail(C, p);
	}
	for(Node *p = C.pHead; p->pNext!=NULL; p=p->pNext){
		for(Node *q = p; q!=NULL; q=q->pNext){
			if(p->Data > q->Data){
				int temp = p->Data;
				p->Data = q->Data;
				q->Data = temp;
			}
		}
	}
}
void insertafterp(List &l, int p, Node *x){
	if(l.pHead==NULL){
		l.pHead=l.pTail=x;
	}
	else if(l.pTail->Data==p){
		InsertTail(l, Create(p));
	}
	else{
		for(Node *i=l.pHead;i!=NULL;i=i->pNext){
			if(i->Data==p){
				x->pNext=i->pNext;
				i->pNext=x;
				break;
			}
		}
	}
}
int main(){
	List A, B, C;
	InitList(A);
	InitList(B);
	InitList(C);
	InsertTail(A, Create(1));
	InsertTail(A, Create(9));
	InsertTail(A, Create(3));
	cout<<"\n Ma cua A la: ";
	Xuat(A);
	InsertTail(B, Create(12));
	InsertTail(B, Create(2));
	InsertTail(B, Create(6));
	InsertTail(B, Create(8));
	insertafterp(B, 6, Create(100));
	cout<<"\n Ma cua B la: ";
	Xuat(B);
	Nhap(A, B, C);
	cout<<"\n Ma cua C la: ";
	Xuat(C);
}




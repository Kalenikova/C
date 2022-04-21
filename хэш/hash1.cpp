#include <iostream>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <windows.h>
#include <fstream>
using namespace std;

typedef struct Data{
    char c;
	int k;
} T;
//typedef struct Data T; // ��� ���������
typedef struct _Node{
   T data;// ������,���������� � �������
   struct _Node *next;// ��������� �������
} Node, *pNode;
typedef int hashTableIndex;  //������ � ���-�������
#define compEQ(a,b) ((a) == (b))
pNode p;
Node **hashTable;
int hashTableSize;

int kolchar(char *s);
hashTableIndex myhash(T data);
pNode insertNode(T data);
void deleteNode(T data);
pNode findNode (T data);

int main()
{
  setlocale(LC_ALL, "rus");//���������� ������� ����������
  int i, k, maxnum=26;
  T a[26];
  char s[255],*ps=s;
  puts("Input string");
  scanf("%s",s);
  for (i=0;i<26;i++){
	   a[i].c=0;
       a[i].k=0;}
  for (i=0;s[i];i++){
    k=kolchar(ps);
    a[i].c=s[i];
    a[i].k=k;
    printf("%d-%c   %s  (%d=%c)\n",k,ps[0],ps,a[i].k,a[i].c);
  ps++;
  }
  //����� ���������  ������� � ����
  ofstream out("List1.txt");
  for (i = 0; i < maxnum; i++){
	  if (a[i].c>0)
 	  out << a[i].c<<" - "<<a[i].k<< "\t";
      }
  out.close();
//�������� � ������������� �-�
  printf("Input size Hash-Table HashTableSize :");
  cin >> hashTableSize;
  hashTable =(Node**)malloc(sizeof(pNode)*hashTableSize);
  for (i = 0; i < hashTableSize; i++)
  hashTable[i] = NULL;
  //������� ������� � �-�
  for (i = 0; i < maxnum; i++)   {
    if(a[i].c>0)
    insertNode(a[i]);
}
// ����� ��������� ������� �� ���-�������
  for (i = maxnum-1; i>=0;i--)
	  {
    p=findNode(a[i]);
	if (p)
	printf("\nASCII-cod %c -->%d",a[i].c,p->data.c);
	else
		printf("%d  NOT FIND  ",a[i].c);
  }
  // ���������� ���-������� � ���� HashTable.txt
  out.open("HashTable1.txt");
  for (i = 0; i < hashTableSize; i++){
    out << i << " : ";
    pNode temp = hashTable[i];
    while ( temp ){
        out <<"("<< temp->data.c <<" "<<temp->data.k<<") ->";
        temp = temp->next;
    }
    out << endl;
  }
 out.close();
  // ������� ���-�������
    for (i = maxnum-1; i >= 0; i--)
    {
        deleteNode(a[i]);
    }
  system("pause");
  return 0;
}

// ���-������� ���������� �������
hashTableIndex myhash(T dat) {
	int i=dat.c;
	return (i % hashTableSize);//������� ���������������� ��� � ������
}
// ������� ������ �������������� � ������� ������� � �������
pNode insertNode(T newdata) {
  pNode p, p0;
  hashTableIndex bucket;
    // ������� ������� � ������ ������
  bucket = myhash(newdata);
  if (!( p = (pNode) malloc(sizeof(Node)))) {
    fprintf (stderr, "�������� ������ (insertNode)\n");
    exit(1);
    }
  p0 = hashTable[bucket];
  hashTable[bucket] = p;
  p->next = p0;
  p->data = newdata;

  return p;
}
//������� �������� ������� �� �������
void deleteNode(T dat) {
  pNode p0, p;
  hashTableIndex bucket;
  p0 = NULL;
  bucket = myhash(dat);
  p = hashTable[bucket];
  while (p && !compEQ(p->data.c, dat.c)){
    p0 = p;
    p = p->next;
    }
  if (!p) return;
  if (p0)  p0->next = p->next;
  else     hashTable[bucket] = p->next;
  free (p);
}
// ������� ������ ������� �� ��������� data
  pNode findNode (T data) {
  Node *p;
  p = hashTable[myhash(data)];
  while (p && !compEQ(p->data.c, data.c))
    p = p->next;
  return p;
}
int kolchar(char *s){
	int k=1,i,j;
	for(i=j=1;s[i];i++)
		if (s[i]!=s[0]) {s[j]=s[i]; j++;}
		else k++;
		s[j]=0;
 return k;
}


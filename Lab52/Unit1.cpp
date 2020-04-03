//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"



TForm1 *Form1;
int maxlkey,cl=0;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
struct Tree{
 int info ;
 Tree *left ,*right ;


}*root,*rot;

void Add_List(Tree*, int);
void View_Tree (Tree*, int);
void NextEdit(void);
Tree* Del_Info(Tree*, int);
void Del_Tree(Tree*);
Tree* List(int);
Tree* Max_KeyL(Tree*);

Tree* List(int inf) {
	Tree *t = new Tree;
t -> info = inf;
	t -> left = t -> right = NULL;
return t;
}


 void Del_Tree(Tree *t) {
  	if ( t != NULL)  {
    		Del_Tree ( t -> left);
    		Del_Tree ( t -> right);
      	delete t;
   	}
}

Tree* Del_Info(Tree *root, int key)  {
	Tree *Del, *Prev_Del, *R, *Prev_R;

	Del = root;
	Prev_Del = NULL;

while (Del != NULL && Del -> info != key) {
		Prev_Del = Del;
		if (Del->info > key)  Del = Del->left;
			else Del = Del->right;
		}
	if (Del == NULL)	{
   	ShowMessage ( "NOT Key!");
			return root;
	}

	if (Del -> right == NULL) R = Del->left;
	else
		if (Del -> left == NULL) R = Del->right;
		else {

			Prev_R = Del;
			R = Del->left;
			while (R->right != NULL) {
				Prev_R = R;
				R = R->right;
			}
//----------------  -------------------
			if( Prev_R == Del)  R->right = Del->right;
			else {
				R->right = Del->right;
				Prev_R->right = R->left;
				R->left = Prev_R;
			}
	 }
	if (Del== root) root = R;
	else
//---------------  ----------------
	if (Del->info < Prev_Del->info)
			Prev_Del->left = NULL;
		else	Prev_Del->right = NULL;
	delete Del;
	return root;

 }

void Add_List(Tree *root, int key)	  {
if (cl==1){
rot=root;
}
      	Tree *prev, *t;
 bool find = true;
	    	t = root;
		while ( t && find) {
		  	prev = t;
		  	if( key == t->info) {
                                find = false;
                                ShowMessage("���� ��� ����!");
			}
		   	else
				if ( key < t -> info ) t = t -> left;
				else   t = t -> right;
		}
		if (find) {
			t = List(key);
			if ( key < prev -> info ) prev -> left = t;
			else    prev -> right = t;
		}
      }


void View_Tree(Tree *p, int level )	{
       String str;
	if ( p )	  {
	   	View_Tree (p -> right , level+1);
	   	for ( int i=0; i<level; i++) str = str + "    ";
				Form1->Memo1->Lines->Add(str + IntToStr(p->info));
	   	View_Tree(p -> left , level+1);
	   }
	}




void __fastcall TForm1::Button1Click(TObject *Sender)
{
 if(root != NULL) Del_Tree(root);

      root = List (StrToInt(Edit1->Text));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
 if(root == NULL) root = List (StrToInt(Edit1->Text));
      else Add_List (root, StrToInt(Edit1->Text));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
 if( rot == NULL ) ShowMessage(" �������� ������!!");
     else {
          Memo1->Lines->Add("---------- View -----------");
          View_Tree(rot, 0);
     }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
      int b = StrToInt(Form1->Edit1->Text);
		    root = Del_Info(root, b);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
Form1->Memo1->Clear();
   Del_Tree(root);
	      	ShowMessage(" ������ �������!");
        root = NULL;
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Edit1KeyPress(TObject *Sender, char &Key)
{

if(Key==13){


  if(cl==0){
    cl++;
    TForm1::Button1Click(Button1);
    NextEdit();
     }
   else{
     TForm1::Button2Click(Button2) ;
     NextEdit();
    }



 }


}

void NextEdit(void){
Form1->Edit1->Text="";
}
//---------------------------------------------------------------------------
Tree* Max_KeyL(Tree *p){
Tree *t;
 root=p;
p=p->left;

int maxlkey=p->info;
while(p!=NULL){
 if(maxlkey<=p->info){
 t=root;
  maxlkey=p->info;
  }
 p=p->right;

}
return t;
}
void __fastcall TForm1::Button6Click(TObject *Sender)
{
int maxlkey;
Tree *p_maxl=Max_KeyL(rot);
                                                                                                                                                                                                                       p_maxl=rot->left;
 Form1->MaxLabel->Caption="������������ �="+IntToStr(rot->left->info);



Del_Tree(p_maxl);
                                                                                                                                                                                                                         rot->left=NULL;
}
//---------------------------------------------------------------------------



















//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
AnsiString s1 ;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{

Memo1->Clear();

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit1KeyPress(TObject *Sender, char &Key)
{
   s1=Edit1->Text;
   AnsiString s2 ;
   if (Key==13)
   {
   int p ;
     if ( s1.Length()<15 ) {
      ShowMessage("������� ������ ��������");}
      else {
     s2=s1.SubString(5 ,10); }

     AnsiString s3 ;
      int t=s1.Length();
      for ( int i=1 ; i<t ; i++)
      {
       if (s1[i]== ' ') {
       p=i ;
       break;
           }
           else { p=5 ;}
       }
        s3= s1.SubString(p ,t+1-p);
        s2.Insert(s3,12);
     //ShowMessage("���� ������");



     Memo1->Lines->Add(s2);
     s2=" ";
         }
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
Edit1->Text="";
s1=" ";
}
//---------------------------------------------------------------------------


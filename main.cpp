
#include "TXLib.h"
#include <fstream>
using namespace std;

bool click_answer(int x)
{
  return(txMouseButtons() == 1 &&
         txMouseX() >= x &&
         txMouseY() >= 350 &&
         txMouseX() <= x+200 &&
         txMouseY() <= 450);
}

struct Form
{
  string text_question;
  int right_answer;
  string text_answer1;
  string text_answer2;
  string text_answer3;
  HDC pic_fon;

};
void draw_answer(int x, string text, int font)
{
  txSetColor(TX_WHITE);
  txSetFillColor(TX_BLACK);
  txSelectFont("Arial", font);
  Win32::RoundRect(txDC(), x, 350, x+200, 450, 20, 20 );
  txDrawText (x, 350, x+200, 450, text.c_str());

}
string getPart(string str, int *pos2)
{
    int pos1 = *pos2 + 1;
    *pos2 = str.find(",", pos1);
    string Part = str.substr(pos1,*pos2 - pos1);
    return Part;
}


int main()
    {
    txCreateWindow (800, 600);
    txTextCursor (false);

    HDC fon1 = txLoadImage("��������/���.bmp");



    int n_question = 1;
    int result = 0;

 Form form;

 Form form_list[10];

    string str;
    int n = 0;
    ifstream file("13131.txt");
    int font = 35;

    while(file.good())
    {
    getline(file, str);
    int pos2 = -1;

    form_list[n].text_question = getPart( str,&pos2);
    form_list[n].right_answer = atoi(getPart( str,&pos2).c_str());
    form_list[n].text_answer1 = getPart( str,&pos2);
    form_list[n].text_answer2 = getPart( str,&pos2);
    form_list[n].text_answer3 = getPart( str,&pos2);
    form_list[n].pic_fon = txLoadImage(getPart(str,&pos2).c_str());
    n++;
    }

 file.close();

 while(n_question<=n)
 {
    txBegin();
    txSetFillColor(TX_BLACK);
    txClear();

  form = form_list[n_question - 1];


    txSetColor(TX_BLACK);
    txSetFillColor(TX_WHITE);
    font = 35;
    txSelectFont("Arial", font);
    txBitBlt (txDC(), 0, 0, 800,600, form.pic_fon);
    txDrawText(50, 50 ,750, 250, form.text_question.c_str());

    if(n_question == 8)
    {
       font = 25;
    }
    draw_answer(50, form.text_answer1, font);
    draw_answer(300, form.text_answer2, font);
    draw_answer(550, form.text_answer3, font);

    font = 35;
    txSelectFont("Arial", font);
    char str[10];
    sprintf(str, "������ %d/%d", n_question, n);
    txDrawText(50, 0 ,750, 50, str );

    if (click_answer(50))
    {
      txSleep(500);
      n_question++;
      if(form.right_answer == 1)
      {
        result++;
      }
    }
    if (click_answer(300))
    {
      txSleep(500);
      n_question++;
      if(form.right_answer == 2)
      {
        result++;
      }
    }

     if (click_answer(550))
    {
      txSleep(500);
      n_question++;
      if(form.right_answer == 3)
      {
        result++;
      }
    }

    txEnd;
    txSleep(50);
 }
    txSetFillColor(TX_BLACK);
    txClear();

     txDrawText(50, 50 ,750, 250, "��� ���������");
    char stroka[10];
    sprintf(stroka, "%d", result);
     txDrawText(50, 150 ,750, 550, stroka);

     if (result==10)
     txDrawText(50, 350 ,750, 250, "������" );
     else if(5<= result <=10)
     txDrawText(50, 350 ,750, 250, "C������" );
     else if(result<5)
     txDrawText(50, 350 ,750, 250, "�������" );

     for(int i=0; i<=n; i++)
     {
        txDeleteDC(form_list[i].pic_fon);
     }

    return 0;
   }

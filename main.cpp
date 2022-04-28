

#include "TXLib.h"

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
};

void draw_answer(int x, string text)
{
  txSetFillColor(TX_BLACK);
  Win32::RoundRect(txDC(), x, 350, x+200, 450, 20, 20 );
  txDrawText (x, 350, x+200, 450, text.c_str());

}

int main()
    {
    txCreateWindow (800, 600);
    txTextCursor (false);

    int n_question = 1;
    int kol_question = 5;
    int result = 0;

 Form form;

 Form form_list[5];
  form_list[0]={"1) Сколько существует на данный момент элементов?", 2,"1) 6","2) 7","3) 8"};
  form_list[1]={"2) В каком мире происходят действия?", 1,"1) Тейват","2) Селестия","3) Ли юэ"};
  form_list[2]={"3) Как зовут нашего помощника?", 2,"1) Итер","2) Паймон","3) Люмин"};
  form_list[3]={"4) Как называют защитника региона?", 3,"1) Боги истоков","2) Фатуи","3) Архонт"};
  form_list[4]={"5) Какой предмет помогает овладеть элементом?", 1,"1) Глаз бога","2) Оружие","3) Артефакт"};

 while(n_question<=kol_question)
 {
    txBegin();
    txSetFillColor(TX_BLACK);
    txClear();

  form = form_list[n_question - 1];


    txSetColor(TX_WHITE);
    txSetFillColor(TX_WHITE);
    txSelectFont("Arial", 30);
    txDrawText(50, 50 ,750, 250, form.text_question.c_str());
    draw_answer(50, form.text_answer1);
    draw_answer(300, form.text_answer2);
    draw_answer(550, form.text_answer3);

    char str[10];
    sprintf(str, "Вопрос %d/%d", n_question, kol_question);
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
     txDrawText(50, 50 ,750, 250, "Ваш результат");
    char str[10];
    sprintf(str, "%d", result);
     txDrawText(50, 150 ,750, 550, str);

     if (result==5)
     txDrawText(50, 350 ,750, 250, "Знаток" );
     else if(3 <= result <= 5)
     txDrawText(50, 350 ,750, 250, "Cредний" );
     else if(result<= 3)
     txDrawText(50, 350 ,750, 250, "Новичок" );
    return 0;
   }

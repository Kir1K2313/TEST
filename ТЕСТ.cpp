

#include "TXLib.h"

struct Form
{
  string text_question;
  string text_answer1;
  string text_answer2;
  string text_answer3;
}
int main()
    {
    txCreateWindow (800, 600);

 Form form1={"������","1","2","3"};
 Form form2={"2������","1","2","3"};
 Form form3{"3)��� ����� ������ ���������?","1)����","2) ������","3)�����"};
 Form form4{"4)��� �������� ��������� �������?","1)���� �������","2)�����","3)������"};
 Form form5{"5)��� ������� �������� �������� ���������?","1)���� ����","2)","3)������"};

 if(n_question == 1) form = form1;
 if(n_question == 2) form = form2;
 if(n_question == 3) form = form3;
 if(n_question == 4) form = form4;
 if(n_question == 5) form = form5;

    return 0;
    }


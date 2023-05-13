#include "MyForm.h"
#include <cmath>
#include <time.h>
#include <iostream>
using namespace ScoreFootballGenerator;
using namespace System::Windows::Forms;



// Application entry point
[STAThreadAttribute]
void main(array<String^>^ args) {
    srand(time(NULL));
	// Initial Application Parameters:
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	ScoreFootballGenerator::MyForm form;
	Application::Run(% form);
}

System::Void ScoreFootballGenerator::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
    for (int i = 0; i < 8; i++)
    {
        dataGridView1->Rows->Add();
    }
    dataGridView1->Rows[0]->Cells[0]->Value = "Разрушители Сетки";
    dataGridView1->Rows[1]->Cells[0]->Value = "Вышибалы";
    dataGridView1->Rows[2]->Cells[0]->Value = "Мячоманы";
    dataGridView1->Rows[3]->Cells[0]->Value = "Дикие Зайцы";
    dataGridView1->Rows[4]->Cells[0]->Value = "Чудаки в Майках";
    dataGridView1->Rows[5]->Cells[0]->Value = "Союз Длинноногих";
    dataGridView1->Rows[6]->Cells[0]->Value = "Короли Штрафных";
    dataGridView1->Rows[7]->Cells[0]->Value = "Пикантные Креветки";

    int scores[8] = { 0 };
    int lambda[8];

    lambda[0] = Convert::ToInt32(numericUpDown1->Value);
    lambda[1] = Convert::ToInt32(numericUpDown2->Value);
    lambda[2] = Convert::ToInt32(numericUpDown3->Value);
    lambda[3] = Convert::ToInt32(numericUpDown4->Value);
    lambda[4] = Convert::ToInt32(numericUpDown5->Value);
    lambda[5] = Convert::ToInt32(numericUpDown6->Value);
    lambda[6] = Convert::ToInt32(numericUpDown7->Value);
    lambda[7] = Convert::ToInt32(numericUpDown8->Value);

    for (int i = 0; i < 8; i++) 
    {
        for (int j = i + 1; j < 8; j++) 
        {
            int score_team1 = 0;
            int score_team2 = 0;
            int m = 0;
            double S = 0;
            double alpha = 0;
            while (S >= -lambda[i])
            {
                alpha =  double(rand()) / RAND_MAX;
                S = S + log(alpha);
                m++;
            }
            score_team1 = m;
            m = 0;
            S = 0;
            while (S >= -lambda[j])
            {
				alpha = double(rand()) / RAND_MAX;
				S = S + log(alpha);
				m++;
			}
            score_team2 = m;
            scores[i] += score_team1;
            scores[j] += score_team2;
        }
    }

    for (int i = 0; i < 8; i++)
    {
        dataGridView1->Rows[i]->Cells[1]->Value = scores[i];
    }

    dataGridView1->Sort(dataGridView1->Columns[1], System::ComponentModel::ListSortDirection::Descending);
   
    for (int i = 1; i < 9; i++)
    {
		dataGridView1->Rows[i-1]->Cells[2]->Value = i;
	}

}

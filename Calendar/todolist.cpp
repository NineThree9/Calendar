#include "todolist.h"

QtWidgetsClass::QtWidgetsClass(QWidget *parent)
	: QWidget(parent)
{
	TastFileIn.open("TastFile.txt");
	string tes = "";
	int t = 0;
	ui.setupUi(this);
	this->setWindowTitle("todo");
	for (int i = 0; i < 8; i++)
	{
		Tast[i] = "";
	}
	
	while (getline(TastFileIn, tes))
	{
		Tast[t] = QString::fromStdString(tes);
		NumOfTaskTemp++;
		t++;
	}
	TastFileIn.close();
	UpDate();
}

QtWidgetsClass::~QtWidgetsClass()
{
}

void QtWidgetsClass::add()
{
	
	QString temp = ui.textEdit->toPlainText();
	ui.textEdit->clear();
	switch (NumOfTaskTemp)
	{
	case 1:
		//ui.label_1->setText(temp);
		Tast[NumOfTaskTemp - 1] = temp;
		NumOfTaskTemp++;
		break;
	case 2:
		//ui.label_2->setText(temp);
		Tast[NumOfTaskTemp - 1] = temp;
		NumOfTaskTemp++;
		break;
	case 3:
		//ui.label_3->setText(temp);
		Tast[NumOfTaskTemp - 1] = temp;
		NumOfTaskTemp++;
		break;
	case 4:
		//ui.label_4->setText(temp);
		Tast[NumOfTaskTemp - 1] = temp;
		NumOfTaskTemp++;
		break;
	case 5:
		//ui.label_5->setText(temp);
		Tast[NumOfTaskTemp - 1] = temp;
		NumOfTaskTemp++;
		break;
	case 6:
		//ui.label_6->setText(temp);
		Tast[NumOfTaskTemp - 1] = temp;
		NumOfTaskTemp++;
		break;
	case 7:
		//ui.label_7->setText(temp);
		Tast[NumOfTaskTemp - 1] = temp;
		NumOfTaskTemp++;
		break;
	case 8:
		//ui.label_8->setText(temp);
		Tast[NumOfTaskTemp - 1] = temp;
		NumOfTaskTemp++;
		break;
	case 9:
		NumOfTaskTemp--;
		QMessageBox::critical(this, "Warning", "task Full", QMessageBox::Ok | QMessageBox::Default, QMessageBox::Cancel | QMessageBox::Escape, 0);
		break;
	};
	UpDate();
}
void QtWidgetsClass::UpDateLabelToTask()
{
	if (ui.label_1->text() == "")
	{
		Tast[0] = "";
	}

	if (ui.label_2->text() == "")
	{
		Tast[1] = "";
	}

	if (ui.label_3->text() == "")
	{
		Tast[2] = "";
	}

	if (ui.label_4->text() == "")
	{
		Tast[3] = "";
	}

	if (ui.label_5->text() == "")
	{
		Tast[4] = "";
	}

	if (ui.label_6->text() == "")
	{
		Tast[5] = "";
	}

	if (ui.label_7->text() == "")
	{
		Tast[6] = "";
	}
	if (ui.label_8->text() == "")
	{
		Tast[7] = "";
	}
}

void QtWidgetsClass::check()
{
	UpDateLabelToTask();
	if (NumOfTaskTemp == 9)
		NumOfTaskTemp--;

	for (int i = 0; i < NumOfTaskTemp; i++)
	{
		if (Tast[i] == "")
		{
			for (int t = i;  t < NumOfTaskTemp;t++)
			{
				if (t + 1 != 8)
				{
					Tast[t] = Tast[t + 1];
				}
				else
				{
					Tast[t] = "";
				}
			}

		}
	}
	if (NumOfTaskTemp > 1)
	{
		NumOfTaskTemp--;
	}
	UpDate();
	this->resize(0, 0);
}
void QtWidgetsClass::UpDate()
{
	TastFileOut.open("TastFile.txt");
	TastFileOut.clear();
	
	

	ui.label_1->setText( Tast[0]);
	ui.label_2->setText( Tast[1]);
	ui.label_3->setText(Tast[2]);
	ui.label_4->setText(Tast[3]);
	ui.label_5->setText(Tast[4]);
	ui.label_6->setText(Tast[5]);
	ui.label_7->setText(Tast[6]);
	ui.label_8->setText(Tast[7]);

	if (Tast[0] == "")
	{
		ui.label_1->hide();
		ui.pushButton_1->hide();
	}
	else
	{   
		TastFileOut << Tast[0].toStdString();
		TastFileOut << endl;
		ui.label_1->show();
		ui.pushButton_1->show();
	}

	if (Tast[1] == "")
	{
		ui.label_2->hide();
		ui.pushButton_2->hide();
	}
	else
	{
		TastFileOut << Tast[1].toStdString();
		TastFileOut << endl;
		ui.label_2->show();
		ui.pushButton_2->show();
	}


	if (Tast[2] == "")
	{
		
		ui.label_3->hide();
		ui.pushButton_3->hide();
	}
	else
	{
		TastFileOut << Tast[2].toStdString();
		TastFileOut << endl;
		ui.label_3->show();
		ui.pushButton_3->show();
	}

	if (Tast[3] == "")
	{

		ui.label_4->hide();
		ui.pushButton_4->hide();
	}
	else
	{
		TastFileOut << Tast[3].toStdString();
		TastFileOut << endl;
		ui.label_4->show();
		ui.pushButton_4->show();
	}


	if (Tast[4] == "")
	{
		ui.label_5->hide();
		ui.pushButton_5->hide();
	}
	else
	{
		TastFileOut << Tast[4].toStdString();
		TastFileOut << endl;
		ui.label_5->show();
		ui.pushButton_5->show();
	}


	if (Tast[5] == "")
	{
		ui.label_6->hide();
		ui.pushButton_6->hide();
	}
	else
	{
		TastFileOut << Tast[5].toStdString();
		TastFileOut << endl;
		ui.label_6->show();
		ui.pushButton_6->show();
	}


	if (Tast[6] == "")
	{
		ui.label_7->hide();
		ui.pushButton_7->hide();
	}
	else
	{
		TastFileOut << Tast[6].toStdString();
		TastFileOut << endl;
		ui.label_7->show();
		ui.pushButton_7->show();
	}


	if (Tast[7] == "")
	{
		ui.label_8->hide();
		ui.pushButton_8->hide();
	}
	else
	{
		TastFileOut << Tast[7].toStdString();
		TastFileOut << endl;
		ui.label_8->show();
		ui.pushButton_8->show();
	}
	this->resize(0, 0);


	TastFileOut.close();

}